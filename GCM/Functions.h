#pragma once

typedef DWORD (_cdecl * GetPosition)(DWORD a, const char* name, int offset);
GetPosition oGetPosition = (GetPosition)0x46EE2B; // 0x450C1B

typedef DWORD (_cdecl * GetLocalPlayer)();
GetLocalPlayer oGetLocalPlayer = (GetLocalPlayer)0x83843A; // 0x806EA6

typedef float* (_cdecl * GetWorldScreenPos)();
GetWorldScreenPos oGetWorldScreenPos = (GetWorldScreenPos)0x46EAEE; // 0x448FAA

typedef float* (_stdcall * GetEnemyMonsterPos)(int a1, int a2);
GetEnemyMonsterPos oGetEnemyMonsterPos = (GetEnemyMonsterPos)0x97D357; // 0x93EBEB

typedef void(__thiscall * Change_HP)(void *pThis, float, bool EffectAtk, bool EffectDef, int ExtraMonsterNum);
Change_HP oChange_HP = (Change_HP)0x9D39C4; // 0x9936C8

typedef void(__thiscall * Change_MP)(void *pThis, float);
Change_MP oChange_MP = (Change_MP)0x8B644F; // 0x881B60

typedef char(__stdcall * RequireFile)(const char* path);
RequireFile oRequireFile = (RequireFile)0x7A971D; // 0x77D3DF

typedef void(_cdecl * KillAllMonsters)();
KillAllMonsters oKillAllMonster = (KillAllMonsters)0x9FFCB8; // 0x9BF444

typedef bool(__thiscall * SetX)(void* pThis, float x);
SetX oSetX = (SetX)0x7DCD61; // 0x7ACF53

typedef bool(__thiscall * SetY)(void* pThis, float y);
SetY oSetY = (SetY)0x7DCD7E; // 0x7ACF70

typedef DWORD(__thiscall * GetMonster)(void* pThis, int index);
GetMonster oGetMonster = (GetMonster)0xA03E21; // 0x9C363D

typedef int(__thiscall * GetMonstersAlive)(void* pThis);
GetMonstersAlive oGetMonstersAlive = (GetMonstersAlive)0x9FFE7A; // 0x9BF606

typedef int(__thiscall * SendMonsterKill)(void* pThis);
SendMonsterKill oSendMonsterKill = (SendMonsterKill)0x8237E2; // 0x7F29CE

typedef bool(__thiscall * IsLive)(void* pThis);
IsLive oIsLive = (IsLive)0x4A7C0A; // 0x48581A

typedef bool(__thiscall * SetLive)(void* pThis, char duno);
SetLive oSetLive = (SetLive)0x81F6FA; // 0x7EE866

typedef bool(__thiscall * IsDead)(void* pThis);
IsDead oIsDead = (IsDead)0x82E97A; // 0x7FD54B

typedef bool(__thiscall * StartMonster)(void* pThis, unsigned int a2, int a3, int a4, int a5, char a6);
StartMonster oStartMonster = (StartMonster)0x9B9B59; // 0x97AA81

typedef int(__thiscall * Turn)(void* pThis);
Turn oTurn = (Turn)0x82EBC9; // 0x7FD79A

typedef void(__thiscall * StartTimer)(void* pThis);
StartTimer oStartTimer = (StartTimer)0x81F902; // 0x7EEA76

typedef void(__thiscall * StopTimer)(void* pThis);
StopTimer oStopTimer = (StopTimer)0x81F90A; // 0x7EEA7E

typedef void(__thiscall * StopCoolTimer)(void* pThis);
StopCoolTimer oStopCoolTimer = (StopCoolTimer)0x4A7BE7; // 0x4857F7

typedef DWORD(__cdecl * GetKD3DWnd)(DWORD a1, const char* name);
GetKD3DWnd oGetKD3DWnd = (GetKD3DWnd)0x467DD8;

typedef void(__thiscall * FreezeAttack)(void* pThis, double a2, float a3, bool a4);
FreezeAttack oFreezeAttack = (FreezeAttack)0x9A6C56; // 0x968E48

typedef bool(__thiscall * SetFrameLock)(void* pThis, bool duno);
SetFrameLock oSetFrameLock = (SetFrameLock)0x7DCD9B; // 0x7ACF8D

typedef int(__thiscall * GetMonsterType)(void* pThis);
GetMonsterType oGetMonsterType = (GetMonsterType)0x4A7C11; // 0x485821

typedef void(__thiscall * SetHP)(void* pThis, float value);
SetHP oSetHP = (SetHP)0x842C84; // 0x81107A

typedef DWORD (__thiscall * Unk)(void* pThis);
Unk oUnk = (Unk)0x9124B4;

template<class T>  __int64  __PAIR__ (DWORD high, T low) { return (((__int64)high) << sizeof(high) * 8) | (unsigned int)(low); }
typedef char (__cdecl* GetPlayerLevel)(__int64 a1);
GetPlayerLevel oGetPlayerLevel = (GetPlayerLevel)0x795E02;