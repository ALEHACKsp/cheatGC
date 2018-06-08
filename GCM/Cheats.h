#pragma once

#include "Globals.h"

DWORD addr_to_ret = 0x79624A;
static __declspec(naked) void nGetPlayerLevel() {

	__asm {

		mov PlayerLevel, eax;
		cmp eax, [0x1044124];
		jmp addr_to_ret;
	}

}

DWORD addr_to_return = 0xA6D9AF;
DWORD inside_call = 0x5A216B;
static __declspec(naked) void InfMonsterSpec() {

	__asm {

		mov dword ptr [eax+0x00], 870;
		push edx;
		mov edx, PlayerLevel;
		add edx, 27;
		mov [eax+0x04], edx;
		pop edx;
		push eax;
		lea ecx, [ebp-0x34];
		call inside_call;
		jmp addr_to_return;
	}

}

DWORD addr_to_return2 = 0x794F84;
static __declspec(naked) void VACItems() {

	__asm {

		mov [esi+0x30], 0x32;
		push edx;
		mov edx, LocalPlayer;
		push ebx;
		mov ebx, LocalPlayer;
		add ebx, PlayerOffsetX;
		mov ebx, [ebx];
		mov dword ptr [esi+0x38], ebx;
		mov ebx, LocalPlayer;
		add ebx, PlayerOffsetY;
		mov ebx, [ebx];
		mov dword ptr [esi+0x3C], ebx;
		pop ebx;
		pop edx;
		mov ecx, esi;
		jmp addr_to_return2;

	}

}

void enable_infmonster_specs() {
	printf("0x%08X\n", InfMonsterSpec);
	MakeJMP((PBYTE)0x796244, (DWORD)nGetPlayerLevel, 6);
	MakeJMP((PBYTE)0xA6D9A6, (DWORD)InfMonsterSpec, 9);

}

void disable_infmonster_specs() {

	*(BYTE*)0xA6D9A6 = 0x50;
	*(BYTE*)0xA6D9A7 = 0x8D;
	*(BYTE*)0xA6D9A8 = 0x4D;
	*(BYTE*)0xA6D9A9 = 0xCC;
	*(BYTE*)0xA6D9AA = 0xE8;
	*(BYTE*)0xA6D9AB = 0xBC;
	*(BYTE*)0xA6D9AC = 0x47;
	*(BYTE*)0xA6D9AD = 0xB3;
	*(BYTE*)0xA6D9AE = 0xFF;

	*(BYTE*)0x796244 = 0x3B;
	*(BYTE*)0x796245 = 0x05;
	*(BYTE*)0x796246 = 0x24;
	*(BYTE*)0x796247 = 0x41;
	*(BYTE*)0x796248 = 0x04;
	*(BYTE*)0x796249 = 0x01;

}

void enable_cooldown_inf_spawn() {

	*(BYTE*)0x7DFC8D = 0x83;
	*(BYTE*)0x7DFC8E = 0xF8;
	*(BYTE*)0x7DFC8F = 0x03;
	*(BYTE*)0x7DFC90 = 0x7C;
	*(BYTE*)0x7DFC91 = 0x0B;

}

void disable_cooldown_inf_spawn() {
	*(BYTE*)0x7DFC8D = 0x3B;
	*(BYTE*)0x7DFC8E = 0x41;
	*(BYTE*)0x7DFC8F = 0x18;
	*(BYTE*)0x7DFC90 = 0x75;
	*(BYTE*)0x7DFC91 = 0x0B;
}

void enable_vac_item() {

	MakeJMP((PBYTE)0x794F7F, (DWORD)VACItems, 5);

}

void disable_vac_item() {

	*(BYTE*)0x794F7F = 0xFF;
	*(BYTE*)0x794F80 = 0x46;
	*(BYTE*)0x794F81 = 0x30;
	*(BYTE*)0x794F82 = 0x8B;
	*(BYTE*)0x794F83 = 0xCE;

}