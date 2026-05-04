#include "HiJack.h"


BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
) {
	/* 模块加载时消息 */
	if (fdwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hinstDLL);

		/* 劫持DLL
			示例为劫持QQ音乐中的bcrypt.dll
		*/
		if (Hijack::Load())
			MessageBoxA(0, "劫持成功!", 0, 0);

	}
	/* 模块卸载时消息 */
	else if (fdwReason == DLL_PROCESS_DETACH) {
		Hijack::Free();
	}

	return TRUE;
}