#pragma once

void VAC_thread() {

	printf("0x%08X\n", (DWORD)VACItems);

	enable_vac_item();

	while (VACThreadShouldRun) {

		Sleep(75);

		oKillAllMonster();

	}

	disable_vac_item();

	printf("\n<- Leaving VAC Thread\n");

}

void HPMP_thread() {

	while (HpMpThreadShouldRun) {

		Sleep(25);

		if (NULL != LocalPlayer) {
			oChange_HP((void*)LocalPlayer, 40000, true, true, -1);
			oChange_MP((void*)LocalPlayer, 4.0f);

		}


	}

	printf("\n<- Leaving HP/MP Thread\n");

}