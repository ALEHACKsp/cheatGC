#pragma once

class AVKQuestGameManager;
class VTQuestGameManager;
class VTAUQuest;
class AUStage;
class VTAUStage;

AVKQuestGameManager pAVKQuestGameManager = *(AVKQuestGameManager*)0x10530C0;

class AVKQuestGameManager
{
public:
	VTQuestGameManager * VT_QuestGameManager; //0x0000 
	VTAUQuest* VT_AUQuest; //0x0004
	char pad_0x0008[0xC]; //0x0008
	AUStage* AUStage; //0x0014 
}; //Size=0x0018

class VTQuestGameManager
{
public:
	char pad_0x0000[0x4]; //0x0000
}; //Size=0x0004

class AUStage
{
public:
	VTAUStage * pVTAUStage; //0x0000 
}; //Size=0x0004

class VTAUStage
{
public:
	char pad_0x0000[0x100]; //0x0000
}; //Size=0x0100

