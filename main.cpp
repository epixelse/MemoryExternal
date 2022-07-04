// Learning C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "proc.h"
#include "mem.h"

int main()
{
    // Get the process Id, handle, and the ac_client's base address
    DWORD processId = GetProcessId(L"ac_client.exe");
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, processId);
    uintptr_t moduleBaseAddress = GetModuleBaseAddress(processId,L"ac_client.exe");

    // Create new health value and write to the address it's stored in
    const int newHealth = 1337;
    uintptr_t healthAddr = mem::FindPtrChain(hProcess, moduleBaseAddress + 0x10f4f4, { 0xF8 });
    mem::PatchBytesEx((BYTE*)healthAddr, (BYTE*)&newHealth, sizeof(newHealth), hProcess);



    return 0;
}
