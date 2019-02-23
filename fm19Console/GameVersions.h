#ifndef GAME_VERSIONS_H
#define GAME_VERSIONS_H
#include <windows.h>
#include <string>


//Game Settting
LPCSTR windowName = "Football Manager 2019";
LPCSTR gameVersion = "fm 19 v19.1.1 1159619 (64)";


struct MyProfile
{
	struct Information {
		DWORD_PTR rowIdAddr = 0x146A79BE0;
		DWORD_PTR rowIdOffset[4] = { 0x8,0x528,0x8,0x8 };

		DWORD_PTR uniqeIdAddr = 0x146A79BE0;
		DWORD_PTR uniqeIddOffset[4] = { 0x8 ,0x528,0x8,0xC };

		DWORD_PTR coachingLicenseAddr = 0x146A79BE0;
		DWORD_PTR coachingLicenseOffset[4] = { 0x8 ,0x528,0x8,0x16A };

		struct Characteristic {
			DWORD_PTR rowIdAddr = 0x146A79BE0;
			DWORD_PTR rowIdOffset[4] = { 0x8,0x528,0x8,0x8 };

			DWORD_PTR handsOnApproachAddr = 0x146A79BE0;
			DWORD_PTR handsOnApproachOffset[2] = { 0x8 ,0x313 };

			DWORD_PTR domesticPlayerBiasAddr = 0x146A79BE0;
			DWORD_PTR domesticPlayerBiasOffset[2] = { 0x8 ,0x312 };

			DWORD_PTR tacticalConsistencyAddr = 0x146A79BE0;
			DWORD_PTR tacticalConsistencyOffset[2] = { 0x8 ,0x311 };

			DWORD_PTR clubPlayerLoyaltyAddr = 0x146A79BE0;
			DWORD_PTR clubPlayerLoyaltyOffset[2] = { 0x8 ,0x310 };

			DWORD_PTR squadDisciplineAddr = 0x146A79BE0;
			DWORD_PTR squadDisciplineOffset[2] = { 0x8 ,0x30F };

			DWORD_PTR financialControlAddr = 0x146A79BE0;
			DWORD_PTR financialControlOffset[2] = { 0x8 ,0x30E };

			DWORD_PTR mediaHandlingAddr = 0x146A79BE0;
			DWORD_PTR mediaHandlingOffset[2] = { 0x8 ,0x314 };
		};
		struct Reputation
		{
			DWORD_PTR homeRepAddr = 0x146A79BE0;
			DWORD_PTR homeRepOffset[2] = { 0x8,0xB4 };

			DWORD_PTR currentRepAddr = 0x146A79BE0;
			DWORD_PTR currentRepOffset[2] = { 0x8 ,0xB6 };

			DWORD_PTR worldRepAddr = 0x146A79BE0;
			DWORD_PTR worldRepOffset[2] = { 0x8 ,0xB8 };
		};
		struct Contract
		{
			DWORD_PTR typeAddr = 0x146A79BE0;
			DWORD_PTR typeOffset[3] = { 0x8,0x528,0x9A };

			DWORD_PTR jobTypeAddr = 0x146A79BE0;
			DWORD_PTR jobTypeOffset[3] = { 0x8,0x528,0x1C };

			DWORD_PTR weeklyWageAddr = 0x146A79BE0;
			DWORD_PTR weeklyWageOffset[3] = { 0x8,0x528,0x18 };
		};

		Characteristic characteristic;
		Reputation reputation;
		Contract  contract;

	};
	Information information;

};

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

		DWORD_PTR reputationAddr = 0x1469D3900;
		DWORD_PTR reputationOffset[1] = { 0xB0 };

		DWORD_PTR competitionAddr = 0x1469D3900;
		DWORD_PTR competitionOffset[3] = { 0x120,0x58,0x4 };


		DWORD_PTR nationAddr = 0x1469D3900;
		DWORD_PTR nationOffset[4] = { 0x18,0xD0,0xB8,0x4 };


	};

	struct Finances
	{
		DWORD_PTR moneyAddr = 0x1469B91F0;
		DWORD_PTR moneyOffsets[5] = { 0x0,0x50,0x70,0x148,0x67C };
	};
	Information information;
	Finances finances;


};


struct Player {

	struct Information
	{
		int  guidingID = 1177858536;
		DWORD_PTR firstNameOffset[2] = { 0x0,0x4 };
		DWORD_PTR lastNameOffset[2] = { 0x0,0x4 };



	};

	Information information;
};


struct Club {

	struct Information
	{
		int  guidingID = 1177833896;
		DWORD_PTR nationOffset[2] = { 0xB8, 0x4 };


		DWORD_PTR shortNameOffset[2] = { 0xC0 ,0x4 };//+C    River
		DWORD_PTR fullNameOffset[2] = { 0xB8 ,0x4 }; //+C     Club Atletico River Plate
		DWORD_PTR divisionIDOffset = { 0xC };//+44  10241
		DWORD_PTR leagueNameOffset[2] = { 0x58,0x4 }; //+44
		DWORD_PTR divisionStatusOffset[2] = { 0x60 ,0x4 };//+54 Premier Division


		DWORD_PTR stadiumIDOffset[3] = { 0x0,0x78,0xC };//+C




	};

	Information information;
};


struct Stadium {
	DWORD_PTR unknowID;
	DWORD_PTR longitudeOffset = { 0x58 };
	DWORD_PTR latitudeOffset = { 0x54 };
	DWORD_PTR capacityOffset = { 0x60 };
	DWORD_PTR seatingCapaityOffset = { 0x64 };
	DWORD_PTR expansionCapaityOffset = { 0x70 };
	DWORD_PTR usedCapaityOffset = { 0x68 };

};

#endif

