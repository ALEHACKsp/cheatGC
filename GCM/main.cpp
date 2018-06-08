#include "main.h"

void main_thread() {

	system("cls");

	*(BYTE*)0x47351D = 235; // 0x44DBD1

	*(BYTE*)0x9E448B = 0x90;
	*(BYTE*)0x9E448C = 0x90;
	*(BYTE*)0x9E448D = 0x90;
	*(BYTE*)0x9E448E = 0x90;
	*(BYTE*)0x9E448F = 0x90;
	*(BYTE*)0x9E4490 = 0x90;
	*(BYTE*)0x9E4491 = 0x90;
	*(BYTE*)0x9E4492 = 0x90;
	*(BYTE*)0x9E4493 = 0x90;

	// Counter Timers

	*(BYTE*)0x7F782B = 0xEB;
	*(BYTE*)0x7F333B = 0xEB;
	*(BYTE*)0x7DFCC7 = 0xEB;

	bool b_inf_spawn = false;
	bool b_infmon_spec = false;

	if (!LocalPlayer)
		oGetLocalPlayer();
	printf("0x%08X\n", LocalPlayer);

	while (!(GetAsyncKeyState(VK_END))) {

		Sleep(1);

		if (NULL != LocalPlayer) {

			if (GetAsyncKeyState(VK_NUMPAD1)) {

				Sleep(300);
				printf("0x%08X\n", PlayerLevel);
				/*DWORD a = *(DWORD*)0x105B214 + 0x2C540;
				printf("0x%08X\n", a);
				DWORD b = oUnk((void*)a);
				printf("0x%08X\n", b);
				printf("%d\n", oGetPlayerLevel(__PAIR__(*(__int64 *)(b + 0xE) >> 0x20, *(__int64 *)(b + 0xE))));*/

			}

			if (GetAsyncKeyState(VK_NUMPAD2)) {

				Sleep(300);

				b_inf_spawn ? disable_cooldown_inf_spawn() : enable_cooldown_inf_spawn();

				b_inf_spawn = !b_inf_spawn;

				printf("SetMonsterInfSpawn %d\n", b_inf_spawn);

			}

			if (GetAsyncKeyState(VK_NUMPAD3)) {

				Sleep(300);

				b_infmon_spec ? disable_infmonster_specs() : enable_infmonster_specs();

				b_infmon_spec = !b_infmon_spec;

				printf("SetMonsterAttrib %d\n", b_infmon_spec);

			}

			if (GetAsyncKeyState(VK_MBUTTON)) {
				const float* mouse_pos = oGetWorldScreenPos();
				
				*(float*)(LocalPlayer + PlayerOffsetX) = mouse_pos[0];
				*(float*)(LocalPlayer + PlayerOffsetY) = mouse_pos[1];
			}

			if (GetAsyncKeyState(VK_NUMPAD8)) {
				Sleep(300);
				for (int i = 0; i < 150; i++) {

					DWORD monster = oGetMonster((void*)0x11D1958, i); // 11741D0
					if (monster) {
						
						printf("%d\n", oGetMonsterType((void*)monster));

					}

				}

			}

			if (GetAsyncKeyState(VK_NUMPAD4)) {
				Sleep(300);
				DWORD pMonsterManager = *(DWORD*)((*(DWORD*)0x11D196C) + 0x8); // 11741E4
				DWORD* pMonsters = (DWORD*)(pMonsterManager + 0x10);
				if (*pMonsters) {
					printf("\nMobs killed\n");

					oKillAllMonster();
				}
			}

			if (GetAsyncKeyState(VK_NUMPAD6)) {

				Sleep(300);
				if (!VACThreadShouldRun) {
					printf("\n-> VAC Thread Created!\n");
					VACThreadShouldRun = true;
					hVACThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&VAC_thread, NULL, 0, NULL);
					SetThreadPriority(hVACThread, THREAD_PRIORITY_IDLE);

				}
				else {

					VACThreadShouldRun = false;
					WaitForSingleObject(hVACThread, INFINITE);
					CloseHandle(hVACThread);
					hVACThread = NULL;

				}

			}

			if (GetAsyncKeyState(VK_NUMPAD7)) {

				Sleep(300);
				printf("\nTime set!\n");
				*(DWORD*)((*(DWORD*)ClockMgr) + 0x40) = 201758;

			}

			if (GetAsyncKeyState(VK_NUMPAD5)) {

				Sleep(300);

				if (!HpMpThreadShouldRun) {
					printf("\n-> HP/MP Thread Created!\n");
					HpMpThreadShouldRun = true;
					hHPMPThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&HPMP_thread, NULL, 0, NULL);
					SetThreadPriority(hHPMPThread, THREAD_PRIORITY_IDLE);

				}
				else {

					if (NULL != hHPMPThread) {
						HpMpThreadShouldRun = false;
						WaitForSingleObject(hHPMPThread, INFINITE);
						CloseHandle(hHPMPThread);
						hHPMPThread = NULL;
					}

				}

			}

		}

	}

	if (hHPMPThread) {

		TerminateThread(hHPMPThread, 0);
		CloseHandle(hHPMPThread);

	}

	if (hVACThread) {

		TerminateThread(hVACThread, 0);
		CloseHandle(hVACThread);

	}

	disable_cooldown_inf_spawn();
	disable_vac_item();
	disable_infmonster_specs();
	dealloc((LPVOID)nGetPlayerLevel);
	dealloc((LPVOID)VACItems);
	dealloc((LPVOID)InfMonsterSpec);

	system("cls");
	printf("\nFinished!\n");
	fclose(stdout);
	FreeConsole();
	
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{

	DisableThreadLibraryCalls(hModule);
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		if (AllocConsole())
		{
			freopen("CONOUT$", "w", stdout);
		}

		SetThreadPriority(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main_thread, NULL, 0, NULL), THREAD_BASE_PRIORITY_IDLE);
	

	}

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;

}