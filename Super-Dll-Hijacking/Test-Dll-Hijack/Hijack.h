#ifndef _HIJACK_H_
#define _HIJACK_H_

#include <Windows.h>

namespace Hijack { 
	BOOLEAN Load(); 

	VOID Free(); 
};

void BCryptAddContextFunction();
void BCryptAddContextFunctionProvider();
void BCryptCloseAlgorithmProvider();
void BCryptConfigureContext();
void BCryptConfigureContextFunction();
void BCryptCreateContext();
void BCryptCreateHash();
void BCryptCreateMultiHash();
void BCryptDecapsulate();
void BCryptDecrypt();
void BCryptDeleteContext();
void BCryptDeriveKey();
void BCryptDeriveKeyCapi();
void BCryptDeriveKeyPBKDF2();
void BCryptDestroyHash();
void BCryptDestroyKey();
void BCryptDestroySecret();
void BCryptDuplicateHash();
void BCryptDuplicateKey();
void BCryptEncapsulate();
void BCryptEncrypt();
void BCryptEnumAlgorithms();
void BCryptEnumContextFunctionProviders();
void BCryptEnumContextFunctions();
void BCryptEnumContexts();
void BCryptEnumProviders();
void BCryptEnumRegisteredProviders();
void BCryptExportKey();
void BCryptFinalizeKeyPair();
void BCryptFinishHash();
void BCryptFreeBuffer();
void BCryptGenRandom();
void BCryptGenerateKeyPair();
void BCryptGenerateSymmetricKey();
void BCryptGetFipsAlgorithmMode();
void BCryptGetProperty();
void BCryptHash();
void BCryptHashData();
void BCryptImportKey();
void BCryptImportKeyPair();
void BCryptKeyDerivation();
void BCryptOpenAlgorithmProvider();
void BCryptProcessMultiOperations();
void BCryptQueryContextConfiguration();
void BCryptQueryContextFunctionConfiguration();
void BCryptQueryContextFunctionProperty();
void BCryptQueryProviderRegistration();
void BCryptRegisterConfigChangeNotify();
void BCryptRegisterProvider();
void BCryptRemoveContextFunction();
void BCryptRemoveContextFunctionProvider();
void BCryptResolveProviders();
void BCryptSecretAgreement();
void BCryptSetAuditingInterface();
void BCryptSetContextFunctionProperty();
void BCryptSetProperty();
void BCryptSignHash();
void BCryptUnregisterConfigChangeNotify();
void BCryptUnregisterProvider();
void BCryptVerifySignature();

#endif