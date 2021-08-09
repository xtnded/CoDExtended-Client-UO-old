#include "stdafx.h"
#include "shared.h"
#include "client.h"

void CleanupExit() {
	void(*o)();
	*(UINT32*)&o = 0x40F8E0;
	o();

	void Sys_Unload();
	Sys_Unload();
}

void Main_UnprotectModule(HMODULE hModule) {
	PIMAGE_DOS_HEADER header = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS ntHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + header->e_lfanew);

	// unprotect the entire PE image
	SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
	DWORD oldProtect;
	VirtualProtect((LPVOID)hModule, size, PAGE_EXECUTE_READWRITE, &oldProtect);
}

bool apply_hooks() {
	HMODULE hModule;
	if (SUCCEEDED(GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCSTR)apply_hooks, &hModule))) {
		Main_UnprotectModule(hModule);
	}

	void patch_opcode_loadlibrary();
	patch_opcode_loadlibrary();
	
	if (codversion != CODUO_51) return true;

	PATCH_PUSH_STRING_PTR_VALUE(0x4F467C, "CoD UO Extended");

	__call(0x46B565, (int)CleanupExit);

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	__call(0x56FB98, (int)WinMain);

	unlock_client_structure(); // make some client cls_ structure members writeable etc

	// void CL_Frame(int msec);
	// __call(0x43C8C3, (int)CL_Frame);

	void CL_Init();
	__call(0x43C166, (int)CL_Init);
	__call(0x43C7C7, (int)CL_Init);

	return true;
}