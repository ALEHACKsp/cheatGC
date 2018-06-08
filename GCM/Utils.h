#pragma once

void MakeJMP(BYTE *pAddress, DWORD dwJumpTo, DWORD dwLen)
{
	DWORD dwOldProtect, dwBkup, dwRelAddr;
	VirtualProtect(pAddress, dwLen, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	dwRelAddr = (DWORD)(dwJumpTo - (DWORD)pAddress) - 5;
	*pAddress = 0xE9;
	*((DWORD *)(pAddress + 0x1)) = dwRelAddr;
	for (DWORD x = 0x5; x < dwLen; x++) *(pAddress + x) = 0x90;
	VirtualProtect(pAddress, dwLen, dwOldProtect, &dwBkup);
	return;
}

void dealloc(LPVOID mem) {
	DWORD dwOldProtect, dwBkup;
	int length = 0;
	for (length = 0; *((UINT32 *)(&((unsigned char *)mem)[length])) != 0xCCCCCCCC; ++length);
	VirtualProtect((LPVOID)mem, length, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	for (int i = 0; i < length; i++)*(BYTE*)((DWORD)mem + i) = 0xCC;
	VirtualProtect((LPVOID)mem, length, dwOldProtect, &dwBkup);
}