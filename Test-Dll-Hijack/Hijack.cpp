#include "Hijack.h"


HMODULE m_hModule = NULL;
ULONG_PTR m_ExportFuncs[60] = { 0 }; 

BOOLEAN Hijack::Load(){ 
	m_hModule = LoadLibraryA("C:\\Windows\\SysWOW64\\bcrypt.dll");
	if (!m_hModule) 
		goto FAILED;

	m_ExportFuncs[0] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(1));
	if (!m_ExportFuncs[0])
		goto FAILED;

	m_ExportFuncs[1] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(2));
	if (!m_ExportFuncs[1])
		goto FAILED;

	m_ExportFuncs[2] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(3));
	if (!m_ExportFuncs[2])
		goto FAILED;

	m_ExportFuncs[3] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(4));
	if (!m_ExportFuncs[3])
		goto FAILED;

	m_ExportFuncs[4] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(5));
	if (!m_ExportFuncs[4])
		goto FAILED;

	m_ExportFuncs[5] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(6));
	if (!m_ExportFuncs[5])
		goto FAILED;

	m_ExportFuncs[6] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(7));
	if (!m_ExportFuncs[6])
		goto FAILED;

	m_ExportFuncs[7] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(8));
	if (!m_ExportFuncs[7])
		goto FAILED;

	m_ExportFuncs[8] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(9));
	if (!m_ExportFuncs[8])
		goto FAILED;

	m_ExportFuncs[9] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(10));
	if (!m_ExportFuncs[9])
		goto FAILED;

	m_ExportFuncs[10] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(11));
	if (!m_ExportFuncs[10])
		goto FAILED;

	m_ExportFuncs[11] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(12));
	if (!m_ExportFuncs[11])
		goto FAILED;

	m_ExportFuncs[12] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(13));
	if (!m_ExportFuncs[12])
		goto FAILED;

	m_ExportFuncs[13] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(14));
	if (!m_ExportFuncs[13])
		goto FAILED;

	m_ExportFuncs[14] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(15));
	if (!m_ExportFuncs[14])
		goto FAILED;

	m_ExportFuncs[15] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(16));
	if (!m_ExportFuncs[15])
		goto FAILED;

	m_ExportFuncs[16] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(17));
	if (!m_ExportFuncs[16])
		goto FAILED;

	m_ExportFuncs[17] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(18));
	if (!m_ExportFuncs[17])
		goto FAILED;

	m_ExportFuncs[18] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(19));
	if (!m_ExportFuncs[18])
		goto FAILED;

	m_ExportFuncs[19] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(20));
	if (!m_ExportFuncs[19])
		goto FAILED;

	m_ExportFuncs[20] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(21));
	if (!m_ExportFuncs[20])
		goto FAILED;

	m_ExportFuncs[21] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(22));
	if (!m_ExportFuncs[21])
		goto FAILED;

	m_ExportFuncs[22] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(23));
	if (!m_ExportFuncs[22])
		goto FAILED;

	m_ExportFuncs[23] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(24));
	if (!m_ExportFuncs[23])
		goto FAILED;

	m_ExportFuncs[24] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(25));
	if (!m_ExportFuncs[24])
		goto FAILED;

	m_ExportFuncs[25] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(26));
	if (!m_ExportFuncs[25])
		goto FAILED;

	m_ExportFuncs[26] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(27));
	if (!m_ExportFuncs[26])
		goto FAILED;

	m_ExportFuncs[27] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(28));
	if (!m_ExportFuncs[27])
		goto FAILED;

	m_ExportFuncs[28] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(29));
	if (!m_ExportFuncs[28])
		goto FAILED;

	m_ExportFuncs[29] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(30));
	if (!m_ExportFuncs[29])
		goto FAILED;

	m_ExportFuncs[30] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(31));
	if (!m_ExportFuncs[30])
		goto FAILED;

	m_ExportFuncs[31] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(32));
	if (!m_ExportFuncs[31])
		goto FAILED;

	m_ExportFuncs[32] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(33));
	if (!m_ExportFuncs[32])
		goto FAILED;

	m_ExportFuncs[33] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(34));
	if (!m_ExportFuncs[33])
		goto FAILED;

	m_ExportFuncs[34] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(35));
	if (!m_ExportFuncs[34])
		goto FAILED;

	m_ExportFuncs[35] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(36));
	if (!m_ExportFuncs[35])
		goto FAILED;

	m_ExportFuncs[36] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(37));
	if (!m_ExportFuncs[36])
		goto FAILED;

	m_ExportFuncs[37] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(38));
	if (!m_ExportFuncs[37])
		goto FAILED;

	m_ExportFuncs[38] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(39));
	if (!m_ExportFuncs[38])
		goto FAILED;

	m_ExportFuncs[39] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(40));
	if (!m_ExportFuncs[39])
		goto FAILED;

	m_ExportFuncs[40] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(41));
	if (!m_ExportFuncs[40])
		goto FAILED;

	m_ExportFuncs[41] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(42));
	if (!m_ExportFuncs[41])
		goto FAILED;

	m_ExportFuncs[42] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(43));
	if (!m_ExportFuncs[42])
		goto FAILED;

	m_ExportFuncs[43] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(44));
	if (!m_ExportFuncs[43])
		goto FAILED;

	m_ExportFuncs[44] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(45));
	if (!m_ExportFuncs[44])
		goto FAILED;

	m_ExportFuncs[45] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(46));
	if (!m_ExportFuncs[45])
		goto FAILED;

	m_ExportFuncs[46] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(47));
	if (!m_ExportFuncs[46])
		goto FAILED;

	m_ExportFuncs[47] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(48));
	if (!m_ExportFuncs[47])
		goto FAILED;

	m_ExportFuncs[48] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(49));
	if (!m_ExportFuncs[48])
		goto FAILED;

	m_ExportFuncs[49] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(50));
	if (!m_ExportFuncs[49])
		goto FAILED;

	m_ExportFuncs[50] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(51));
	if (!m_ExportFuncs[50])
		goto FAILED;

	m_ExportFuncs[51] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(52));
	if (!m_ExportFuncs[51])
		goto FAILED;

	m_ExportFuncs[52] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(53));
	if (!m_ExportFuncs[52])
		goto FAILED;

	m_ExportFuncs[53] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(54));
	if (!m_ExportFuncs[53])
		goto FAILED;

	m_ExportFuncs[54] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(55));
	if (!m_ExportFuncs[54])
		goto FAILED;

	m_ExportFuncs[55] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(56));
	if (!m_ExportFuncs[55])
		goto FAILED;

	m_ExportFuncs[56] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(57));
	if (!m_ExportFuncs[56])
		goto FAILED;

	m_ExportFuncs[57] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(58));
	if (!m_ExportFuncs[57])
		goto FAILED;

	m_ExportFuncs[58] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(59));
	if (!m_ExportFuncs[58])
		goto FAILED;

	m_ExportFuncs[59] = (ULONG_PTR)GetProcAddress(m_hModule, MAKEINTRESOURCEA(60));
	if (!m_ExportFuncs[59])
		goto FAILED;

	return TRUE;
FAILED:
	Hijack::Free();
	return FALSE;
};

VOID Hijack::Free() {
	if (m_hModule)
		FreeModule(m_hModule);
	m_hModule = NULL;
}

__declspec(naked) void BCryptAddContextFunction() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 0 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptAddContextFunctionProvider() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 1 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptCloseAlgorithmProvider() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 2 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptConfigureContext() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 3 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptConfigureContextFunction() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 4 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptCreateContext() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 5 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptCreateHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 6 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptCreateMultiHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 7 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDecapsulate() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 8 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDecrypt() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 9 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDeleteContext() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 10 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDeriveKey() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 11 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDeriveKeyCapi() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 12 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDeriveKeyPBKDF2() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 13 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDestroyHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 14 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDestroyKey() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 15 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDestroySecret() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 16 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDuplicateHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 17 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptDuplicateKey() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 18 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEncapsulate() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 19 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEncrypt() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 20 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEnumAlgorithms() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 21 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEnumContextFunctionProviders() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 22 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEnumContextFunctions() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 23 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEnumContexts() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 24 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEnumProviders() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 25 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptEnumRegisteredProviders() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 26 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptExportKey() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 27 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptFinalizeKeyPair() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 28 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptFinishHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 29 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptFreeBuffer() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 30 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptGenRandom() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 31 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptGenerateKeyPair() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 32 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptGenerateSymmetricKey() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 33 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptGetFipsAlgorithmMode() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 34 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptGetProperty() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 35 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 36 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptHashData() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 37 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptImportKey() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 38 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptImportKeyPair() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 39 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptKeyDerivation() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 40 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptOpenAlgorithmProvider() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 41 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptProcessMultiOperations() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 42 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptQueryContextConfiguration() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 43 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptQueryContextFunctionConfiguration() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 44 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptQueryContextFunctionProperty() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 45 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptQueryProviderRegistration() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 46 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptRegisterConfigChangeNotify() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 47 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptRegisterProvider() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 48 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptRemoveContextFunction() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 49 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptRemoveContextFunctionProvider() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 50 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptResolveProviders() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 51 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptSecretAgreement() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 52 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptSetAuditingInterface() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 53 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptSetContextFunctionProperty() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 54 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptSetProperty() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 55 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptSignHash() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 56 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptUnregisterConfigChangeNotify() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 57 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptUnregisterProvider() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 58 * 4]
		jmp EAX
	};
}
__declspec(naked) void BCryptVerifySignature() {
	__asm {
		mov EAX, dword ptr [m_ExportFuncs + 59 * 4]
		jmp EAX
	};
}