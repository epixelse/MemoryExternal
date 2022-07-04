#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

DWORD GetProcessId(const wchar_t* processName);
uintptr_t GetModuleBaseAddress(DWORD processId, const wchar_t* moduleName);


