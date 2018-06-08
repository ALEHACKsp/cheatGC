#pragma once

DWORD MyD3DApplication = 0x105B214; // FE5F6C
DWORD ClockMgr = 0x10434DC; // BE5F6C
DWORD PlayerOffsetX = 0x53C0; // 51B4
DWORD PlayerOffsetY = 0x53C4; // 51B8

DWORD PlayerLevel = NULL;

HANDLE hHPMPThread = NULL;
HANDLE hVACThread = NULL;

bool HpMpThreadShouldRun = false;
bool VACThreadShouldRun = false;

DWORD LocalPlayer = oGetLocalPlayer();