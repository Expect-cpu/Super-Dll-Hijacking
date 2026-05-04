
# Super-Dll-Hijacking

## Introduction
 - Super-Dll-Hijacking is a tool that automates the generation of DLL hijacking source code. It parses the export table of a target DLL file and automatically generates the corresponding hijacking DLL source code, significantly simplifying the development and exploitation process of DLL hijacking techniques.

## Features
 - 🔍 Export Table Parsing - Automatically reads exported function names, ordinals, and addresses from the target DLL.
 - ⚡ Source Code Generation - Generate the complete hijacking code based on the analysis results.
 - 📦 Forwarder Support - Automatically includes function forwarding logic to ensure original DLL functionality remains intact.
 - 🧹 Lightweight & Easy to Use - Single executable with no complex dependencies.
 - 🛡️ Defense Research - Suitable for security researchers to understand DLL hijacking principles and develop defense measures.

## Use Cases
 - Windows security research and penetration testing
 - Malware behavior analysis and simulation
 - Software compatibility debugging and hook development
 - Persistence technique research in red teaming operations

## Supported Platforms

| Architecture | Support Status |
|--------------|----------------|
| **x86 (32-bit)** | ✅ Fully supported |
| **x64 (64-bit)** | ⏳ Planned (coming in a future update) |

> **Note**: The current version only supports parsing 32-bit DLLs. 64-bit support is under development and will be available in a subsequent release.

## Usage Steps
 - 1.Use Virtual Studio 2019 (or other versions) to compile the Release-x86 version of the project or directly use the directory /Release/Super-Dll-Parser-32.exe.
 - 2.Use cmd.exe to enter the following command:
```cmd
    cd [The directory where Super-Dll-Parser-32.exe is located]
    Super-Dll-Parser-32.exe [Full path of the DLL file to be hijacked]
```
 - 3.Import the generated files (Export.def, Hijack.h, Hijack.cpp) into your own DLL project.

## Example
```C++
#include "HiJack.h"

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hinstDLL);
        /* Call the generated hijack initialization function. */ 
		if (Hijack::Load())
			MessageBoxA(0, "劫持成功!", 0, 0);

	}
	else if (fdwReason == DLL_PROCESS_DETACH) {
		Hijack::Free();
	}

	return TRUE;
}
```

## Disclaimer
 - This project is for educational and security research purposes only. Unauthorized use of DLL hijacking techniques to attack others' systems is illegal. Users must comply with local laws and regulations and bear all responsibility arising from the use of this tool. The author and project contributors are not responsible for any misuse.

## License
 - This project is licensed under the MIT License.

## Contributing
 - Issues and Pull Requests are welcome. If you encounter issues parsing specific DLLs, please provide a sample (or export table information) for improvement.
