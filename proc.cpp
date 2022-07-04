#include "proc.h"

DWORD GetProcessId(const wchar_t* processName)
{
	HANDLE hProcessSnap;
	DWORD processId = 0;

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hProcessSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hProcessSnap, &pe32))
		{
			do
			{
				if (!_wcsicmp(pe32.szExeFile, processName))
				{
					processId = pe32.th32ProcessID;
					break;
				}
			} while (Process32Next(hProcessSnap, &pe32));
		}
	}

	CloseHandle(hProcessSnap);
	return processId;
}

uintptr_t GetModuleBaseAddress(DWORD processId, const wchar_t* moduleName)
{
	HANDLE hModuleSnap;
	uintptr_t modAddress = 0;

	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);

	if (hModuleSnap != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 me32;
		me32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hModuleSnap, &me32))
		{
			do
			{
				if (!_wcsicmp(me32.szModule, moduleName))
				{
					modAddress = (uintptr_t)me32.modBaseAddr;
					break;
				}
			} while (Module32Next(hModuleSnap, &me32));
		}
	}
	CloseHandle(hModuleSnap);
	return modAddress;
}