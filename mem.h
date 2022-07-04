#pragma once
#include <Windows.h>
#include <vector>

namespace mem
{
	void PatchBytesEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
	void NopBytesEx(BYTE* dst, unsigned int size, HANDLE hProcess);
	uintptr_t FindPtrChain(HANDLE hProcess, uintptr_t ptr, std::vector<unsigned int> offsets);
}