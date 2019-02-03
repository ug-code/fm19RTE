#ifndef GAME_VERSIONS_H
#define GAME_VERSIONS_H
#include <windows.h>
#include <string>


//Game Settting
LPCSTR windowName = "Football Manager 2019";
LPCSTR gameVersion = "fm 19 v19.1.1 1159619 (64)";
//my current Team 

struct CurrentClub
{
	struct Information
	{
		DWORD_PTR rowIdAddr = 0x41B08838;
		DWORD_PTR rowIdOffset[3] = { 0x10,0x18,0x8 };

		DWORD_PTR uniqeIdAddr = 0x50E1DEA0;
		DWORD_PTR uniqeIddOffset[2] = { 0x18 ,0xC };
		
		DWORD_PTR fullNameAddr = 0x1469BBAD8;
		DWORD_PTR fullNameOffset[5] = { 0x160,0x30,0x18,0xC0,0x4 };
			
	};
	struct Finances
	{
		DWORD_PTR moneyAddr = 0x1469B91F0;
		DWORD_PTR moneyOffsets[5] = { 0x0,0x50,0x70,0x148,0x67C };
	};
	Information information;
	Finances finances;


};





#endif

