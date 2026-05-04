#include "Generate.h"
#include "Log.h"
#include "Script.h"

#include <fstream>
#include <iostream>

#ifdef _WIN64
#define _NT_MAGIC_ IMAGE_NT_OPTIONAL_HDR64_MAGIC
#else
#define _NT_MAGIC_ IMAGE_NT_OPTIONAL_HDR32_MAGIC
#endif // _WIN64


BOOLEAN SaveStringToFile(const std::string& Content, const char* Filename) {
	std::ofstream file(Filename);

	if (!file.is_open()) {
		std::cerr << "Error: Cannot open file " << Filename << std::endl;
		return FALSE;
	}

	file << Content;
	file.close();

	if (file.fail()) {
		std::cerr << "Error: Failed to write to file " << Filename << std::endl;
		return FALSE;
	}

	return TRUE;
}


DWORD Rva2Foa(PIMAGE_NT_HEADERS Nts, DWORD Rva, DWORD FileSize) {
	PIMAGE_SECTION_HEADER pSec = NULL;
	DWORD dwSecVA = 0u;
	DWORD dwSecSize = 0u;
	DWORD dwFoa = 0u;

	pSec = IMAGE_FIRST_SECTION(Nts);
	for (size_t i = 0; i < Nts->FileHeader.NumberOfSections; i++) {
		dwSecVA = pSec->VirtualAddress;
		dwSecSize = pSec->SizeOfRawData;
		if (Rva >= dwSecVA && Rva < (dwSecVA + dwSecSize)) {
			dwFoa = Rva - dwSecVA + pSec->PointerToRawData;
			return dwFoa >= FileSize ? 0u: dwFoa;
		}

		pSec++;
	}

	return 0u;
}

Generate::EPARSESTATUS Generate::Parse(const char* FileName) {
	HANDLE hFile = INVALID_HANDLE_VALUE;
	DWORD dwFileSize = 0u;
	HANDLE hMap = NULL;
	BYTE* pBuffer = NULL;
	PIMAGE_DOS_HEADER pDos = NULL;
	PIMAGE_NT_HEADERS pNts = NULL;
	IMAGE_DATA_DIRECTORY stExportDir;
	DWORD dwTempFoa = 0u;
	PIMAGE_EXPORT_DIRECTORY pExportTable = NULL;
	DWORD dwBaseOrdinal = 0u;
	DWORD dwNumberOfFuncs = 0u;
	DWORD dwNumberOfNames = 0u;
	DWORD* pNameTable = NULL;
	WORD* pOrdinalTable = NULL;
	DWORD* pFunctionsTable = NULL;
	DWORD dwOrdinal = 0u;
	char* pFuncName = NULL;
	std::string szFuncName;

	Generate::EPARSESTATUS eRet = SUCCESS;

	/* 打开文件 */
	hFile = CreateFileA(FileName, GENERIC_READ, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, 0u, NULL);
	if (hFile == INVALID_HANDLE_VALUE) {
		eRet = OPEN_FILE_FAILED;
		goto CLEAR_UP;
	}
	

	/* 获取文件大小 */
	dwFileSize = GetFileSize(hFile, NULL);
	if (dwFileSize == INVALID_FILE_SIZE) {
		eRet = ERROR_FILE_SIZE;
		goto CLEAR_UP;
	}


	/* 创建文件映射 */
	hMap = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
	if (hMap == NULL) {
		eRet = CREATE_FILE_MAPPING_ERROR;
		goto CLEAR_UP;
	}


	/* 映射到当前进程 */
	pBuffer = (BYTE*)MapViewOfFile(hMap, FILE_MAP_READ, 0u, 0u, 0u);
	if (pBuffer == NULL) {
		eRet = MAP_FILE_ERROR;
		goto CLEAR_UP;
	}


	/* 检查是否为PE文件 */
	pDos = (PIMAGE_DOS_HEADER)pBuffer;
	if (pDos->e_magic != IMAGE_DOS_SIGNATURE) {
		eRet = NOT_A_PE_FILE;
		goto CLEAR_UP;
	}

	pNts = (PIMAGE_NT_HEADERS)(pBuffer + pDos->e_lfanew);
	if (pNts->Signature != IMAGE_NT_SIGNATURE) {
		eRet = NOT_A_PE_FILE;
		goto CLEAR_UP;
	}

	if (pNts->OptionalHeader.Magic != _NT_MAGIC_) {
		eRet = ERROR_PROGRAM_BITNESS;
		goto CLEAR_UP;
	}


	/* 定位导出表 */
	ZeroMemory(&stExportDir, sizeof stExportDir);
	stExportDir = pNts->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
	if (stExportDir.VirtualAddress == 0 || stExportDir.Size == 0) {
		eRet = NO_EXPORT_TABLE;
		goto CLEAR_UP;
	}

	dwTempFoa = Rva2Foa(pNts, stExportDir.VirtualAddress, dwFileSize);
	if (dwTempFoa == 0u) {
		eRet = FIND_EXPORT_TABLE_FAILED;
		goto CLEAR_UP;
	}
	pExportTable = (PIMAGE_EXPORT_DIRECTORY)(pBuffer + dwTempFoa);


	/* 获取基础序号,导出函数数量以及有名称导出函数数量 */
	dwBaseOrdinal = pExportTable->Base;
	dwNumberOfFuncs = pExportTable->NumberOfFunctions;
	dwNumberOfNames = pExportTable->NumberOfNames;
	if (dwNumberOfFuncs == 0u) {
		eRet = NO_EXPORT_FUNCTIONS;
		goto CLEAR_UP;
	}


	/* 获取导出函数地址表,导出函数名称表,导出函数名称序号表 */
	dwTempFoa = Rva2Foa(pNts, pExportTable->AddressOfFunctions, dwFileSize);
	pFunctionsTable = (DWORD*)(dwTempFoa ? pBuffer + dwTempFoa : NULL);
	if (pFunctionsTable == NULL) {
		eRet = NO_EXPORT_FUNCTIONS;
		goto CLEAR_UP;
	}

	dwTempFoa = Rva2Foa(pNts, pExportTable->AddressOfNames, dwFileSize);
	pNameTable = (DWORD*)(dwTempFoa ? (pBuffer + dwTempFoa) : NULL);
	dwTempFoa = Rva2Foa(pNts, pExportTable->AddressOfNameOrdinals, dwFileSize);
	pOrdinalTable = (WORD*)(dwTempFoa ? (pBuffer + dwTempFoa) : NULL);
	
	/* 遍历导出函数地址表 */
	SourceScript::SetDllName(FileName);
	for (size_t i = 0; i < dwNumberOfFuncs; i++) {

		/* 过滤导出函数地址表中空项 */
		if (pFunctionsTable[i] == 0u)
			continue;

		pFuncName = NULL;
		dwOrdinal = i + dwBaseOrdinal;

		if (pNameTable && pOrdinalTable) {
			for (size_t n = 0; n < dwNumberOfNames; n++) {
				if (pOrdinalTable[n] == i) {
					dwTempFoa = Rva2Foa(pNts, pNameTable[n], dwFileSize);
					pFuncName = dwTempFoa ? (char*)(pBuffer + dwTempFoa) : NULL;
					break;
				}
			}
		}

		Log("[Ord %u] ", dwOrdinal);
		szFuncName = pFuncName ? pFuncName : "NoNameFunc_" + std::to_string(dwOrdinal);
		Log("%s \r\n", szFuncName.c_str());
		DefScript::AddFunction(szFuncName.c_str(), dwOrdinal);
		NamesScript::AddFunction(szFuncName.c_str());
		HeaderScript::AddFunction(szFuncName.c_str());
		SourceScript::AddFunction(szFuncName.c_str(), dwOrdinal);

	}

	Log("NumberOfFunctions -> %u \r\n", dwNumberOfFuncs);
	Log("NumberOfNames -> %u \r\n", dwNumberOfNames);

	Log("Saving the related files... \r\n", );
	Log("Save in [Names.txt]... \r\n");
	Log("Result -> [%s] \r\n", SaveStringToFile(NamesScript::Generate(), "Names.txt") ? "TRUE" : "FALSE");
	Log("Save in [Export.def]... \r\n");
	Log("Result -> [%s] \r\n", SaveStringToFile(DefScript::Generate(), "Export.def") ? "TRUE" : "FALSE");
	Log("Save in [Hijack.h]... \r\n");
	Log("Result -> [%s] \r\n", SaveStringToFile(HeaderScript::Generate(), "Hijack.h") ? "TRUE" : "FALSE");
	Log("Save in [Hijack.cpp]... \r\n");
	Log("Result -> [%s] \r\n", SaveStringToFile(SourceScript::Generate(), "Hijack.cpp") ? "TRUE" : "FALSE");
	Log("Save completed! \r\n", );

CLEAR_UP:
	if (pBuffer != NULL)
		UnmapViewOfFile(pBuffer);

	if (hMap != NULL)
		CloseHandle(hMap);

	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle(hFile);
	
	return eRet;
}
