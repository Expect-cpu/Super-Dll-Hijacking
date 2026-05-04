#include "Script.h"

#define _DEF_START_ "LIBRARY\n\tEXPORTS"
#define _HEADER_START_ "#ifndef _HIJACK_H_\n#define _HIJACK_H_\n\n#include <Windows.h>\n\nnamespace Hijack { \n\tBOOLEAN Load(); \n\n\tVOID Free(); \n};\n"
#define _SOURCE_START_ "#include \"Hijack.h\"\n\n"

std::string m_NameScript;
std::string m_DefScript;
std::string m_HeaderScript;
std::string m_SourceScript_NameSpace;
std::string m_SourceScript_Hook;
int m_FuncCount = 0;

void NamesScript::AddFunction(const char* FuncName) {
	m_NameScript.append(FuncName);
	m_NameScript.append("\n");
}

std::string NamesScript::Generate() {
	return m_NameScript;
}

void DefScript::AddFunction(const char* FuncName, DWORD Ordinal) {
	static BOOLEAN isInit = FALSE;

	if (isInit == FALSE) {
		m_DefScript = _DEF_START_;
		isInit = TRUE;
	}

	m_DefScript.append("\n\t");
	m_DefScript.append(FuncName);
	if (Ordinal != 0) {
		m_DefScript.append(" @");
		m_DefScript.append(std::to_string(Ordinal));
	}
}

std::string DefScript::Generate() {
	m_DefScript.append("\n");
	return m_DefScript;
}

void HeaderScript::AddFunction(const char* FuncName) {
	static BOOLEAN isInit = FALSE;

	if (isInit == FALSE) {
		m_HeaderScript = _HEADER_START_;
		isInit = TRUE;
	}
	m_HeaderScript.append("\n");
	m_HeaderScript.append("void ");
	m_HeaderScript.append(FuncName);
	m_HeaderScript.append("();");

}

std::string HeaderScript::Generate() {
	m_HeaderScript.append("\n");
	m_HeaderScript.append("\n");
	m_HeaderScript.append("#endif");
	return m_HeaderScript;
}

void SourceScript::AddFunction(const char* FuncName, DWORD Ordinal) {

	/*
		m_ExportFuncs[0] = (ULONG_PTR)GetProcAddress(m_hModule, "BCryptAddContextFunction");
		if (!m_ExportFuncs[0])
			goto FAILED;
	*/

	m_SourceScript_NameSpace.append("\t");
	m_SourceScript_NameSpace.append("m_ExportFuncs[");
	m_SourceScript_NameSpace.append(std::to_string(m_FuncCount));
	m_SourceScript_NameSpace.append("] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(");
	m_SourceScript_NameSpace.append(std::to_string(Ordinal));
	m_SourceScript_NameSpace.append("));");
	m_SourceScript_NameSpace.append("\n");
	m_SourceScript_NameSpace.append("\t");
	m_SourceScript_NameSpace.append("if (!m_ExportFuncs[");
	m_SourceScript_NameSpace.append(std::to_string(m_FuncCount));
	m_SourceScript_NameSpace.append("])");
	m_SourceScript_NameSpace.append("\n");
	m_SourceScript_NameSpace.append("\t\t");
	m_SourceScript_NameSpace.append("goto FAILED;");
	m_SourceScript_NameSpace.append("\n\n");

	/*
	* 函数实现未完成
	* __declspec(naked) void BCryptAddContextFunction() {
		__asm JMP m_ExportFuncs[0];
	
		__asm RET;
	}
	*/
	m_SourceScript_Hook.append("\n");
	m_SourceScript_Hook.append("__declspec(naked) void ");
	m_SourceScript_Hook.append(FuncName);
	m_SourceScript_Hook.append("() {");
	/*
		__asm {
			mov eax, dword ptr [m_ExportFuncs + 20 * 4]
			jmp eax
		}
	*/
	m_SourceScript_Hook.append("\n\t");
	m_SourceScript_Hook.append("__asm {");
	m_SourceScript_Hook.append("\n\t\t");
	m_SourceScript_Hook.append("mov EAX, dword ptr [m_ExportFuncs + ");
	m_SourceScript_Hook.append(std::to_string(m_FuncCount));
	m_SourceScript_Hook.append(" * 4]");
	m_SourceScript_Hook.append("\n\t\t");
	m_SourceScript_Hook.append("jmp EAX");
	m_SourceScript_Hook.append("\n\t");
	m_SourceScript_Hook.append("};");
	m_SourceScript_Hook.append("\n");
	m_SourceScript_Hook.append("}");
	m_FuncCount++;
	
}

std::string SourceScript::Generate() {
	std::string result;

	/* 构建namespace Load和Free方法 */
	result = _SOURCE_START_;
	result.append("\n");
	result.append("HMODULE m_hModule = NULL;\n");
	result.append("ULONG_PTR m_ExportFuncs[");
	result.append(std::to_string(m_FuncCount));
	result.append("] = { 0 }; \n");
	result.append("\n");
	result.append("BOOLEAN Hijack::Load(){ \n");
	result.append(m_SourceScript_NameSpace);
	result.append("\t");
	result.append("return TRUE;");
	result.append("\n");
	result.append("FAILED:");
	result.append("\n");
	result.append("\t");
	result.append("Hijack::Free();");
	result.append("\n");
	result.append("\t");
	result.append("return FALSE;");
	result.append("\n");
	result.append("};");
	result.append("\n\n");
	/*
		VOID Hijack::Free() {
			if (m_hModule)
				FreeModule(m_hModule);
			m_hModule = NULL;
		}
	*/
	result.append("VOID Hijack::Free() {");
	result.append("\n");
	result.append("\t");
	result.append("if (m_hModule)");
	result.append("\n");
	result.append("\t\t");
	result.append("FreeModule(m_hModule);");
	result.append("\n");
	result.append("\t");
	result.append("m_hModule = NULL;");
	result.append("\n");
	result.append("}");
	
	result.append("\n");

	result.append(m_SourceScript_Hook);

	return result;
}

void SourceScript::SetDllName(const char* DllName)
{
	std::string szOldDllName = DllName;
	std::string szNewDllName;
	for (char c : szOldDllName) {
		if (c == '\\') {
			szNewDllName += "\\\\";
		}
		else {
			szNewDllName += c;
		}
	}
	m_SourceScript_NameSpace.append("\t");
	m_SourceScript_NameSpace.append("m_hModule = LoadLibraryA(");
	m_SourceScript_NameSpace.append("\"");
	m_SourceScript_NameSpace.append(szNewDllName);
	m_SourceScript_NameSpace.append("\");");
	m_SourceScript_NameSpace.append("\n");
	m_SourceScript_NameSpace.append("\t");
	m_SourceScript_NameSpace.append("if (!m_hModule) ");
	m_SourceScript_NameSpace.append("\n");
	m_SourceScript_NameSpace.append("\t\t");
	m_SourceScript_NameSpace.append("goto FAILED;");
	m_SourceScript_NameSpace.append("\n\n");
	

}
