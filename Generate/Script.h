#ifndef _SCRIPT_H_
#define _SCRIPT_H_

#include <string>
#include <Windows.h>

namespace DefScript {
	void AddFunction(const char* FuncName, DWORD Ordinal = 0u);

	std::string Generate();
}

namespace NamesScript {
	void AddFunction(const char* FuncName);

	std::string Generate();
}

/* 差头文件生成和源文件生成 */
namespace HeaderScript {
	void AddFunction(const char* FuncName);

	std::string Generate();
}

namespace SourceScript {
	void SetDllName(const char* DllName);

	void AddFunction(const char* FuncName, DWORD Ordinal = 0u);

	std::string Generate();
}

#endif // !_SCRIPT_H_