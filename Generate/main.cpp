#include "Log.h"
#include "Generate.h"

int main(int argc, char* argv[]) {
	Generate::EPARSESTATUS eStatus = Generate::SUCCESS;
	char* pFileName = NULL;

	if (argc < 2 || argv[1] == NULL) {
		pFileName = (char*)"C:\\Windows\\SysWOW64\\bcrypt.dll";
	}
	else {
		pFileName = argv[1];
	}

	
	Log("FileName:[%s] \r\n", pFileName);
	eStatus = Generate::Parse(pFileName);
	switch (eStatus)
	{
		case Generate::OPEN_FILE_FAILED: {
			Log("Failed to open the file! Please make sure the file name is correct. \r\n");
			goto END;
		}
		case Generate::ERROR_FILE_SIZE: {
			Log("Abnormal file size, please check if the file is too large! \r\n");
			goto END;
		}
		case Generate::CREATE_FILE_MAPPING_ERROR: {
			Log("Unable to create file mapping! \r\n");
			goto END;
		}
		case Generate::NOT_A_PE_FILE: {
			Log("Not a valid PE file! \r\n");
			goto END;
		}
		case Generate::ERROR_PROGRAM_BITNESS: {
			Log("Wrong file bit version, please use Super-Dll-Parser-32.exe to open 32-bit programs, and use Super-Dll-Parser-64 to open 64-bit programs! \r\n");
			goto END;
		}
		case Generate::NO_EXPORT_TABLE: {
			Log("The file does not have an export table. \r\n");
			goto END;
		}
		case Generate::FIND_EXPORT_TABLE_FAILED: {
			Log("Cannot find export function table. \r\n");
			goto END;
		}
		case Generate::NO_EXPORT_FUNCTIONS: {
			Log("The export function table is empty. \r\n");
			goto END;
		}
		case Generate::SUCCESS: {
			Log("Parsing successful! The related files have been created in the current directory. \r\n");
			Log("The related files have been created in the current directory [>_<]! \r\n");
			break;
		}
	}

END:
	system("pause");
	return 0;
}