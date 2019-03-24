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

		DWORD_PTR nicknameAddr = 0x1469D3900;
		DWORD_PTR nicknameOffset[4] = { 0x18,0xB0,0xA0,0x4 };
		
		DWORD_PTR yearFoundedAddr = 0x1469D3900;
		DWORD_PTR yearFoundedOffset[3] = { 0x18,0xF8,0x98 };

		DWORD_PTR teamTypeAddr = 0x1469D3900;
		DWORD_PTR teamTypeOffset[1] = { 0x30 };
	
		DWORD_PTR reputationAddr = 0x1469D3900;
		DWORD_PTR reputationOffset[1] = { 0xB0 };

		DWORD_PTR nationAddr = 0x1469D3900;
		DWORD_PTR nationOffset[4] = { 0x18,0xD0,0xB8,0x4 };
	
		DWORD_PTR statusAddr = 0x1469D3900;
		DWORD_PTR statusOffset[2] = { 0x18,0x158 };

		DWORD_PTR ownershipTypeAddr = 0x1469D3900;
		DWORD_PTR ownershipTypeOffset[3] = { 0x18,0xF8,0xC9 };

		DWORD_PTR chairmanTitleAddr = 0x1469D3900;
		DWORD_PTR chairmanTitleOffset[3] = { 0x18,0xF8,0xCA };

		DWORD_PTR chairmanStatusAddr = 0x1469D3900;
		DWORD_PTR chairmanStatusOffset[3] = { 0x18,0xF8 ,0xA0};

		DWORD_PTR trainingFacilitiesAddr = 0x1469D3900;
		DWORD_PTR trainingFacilitiesOffset[3] = { 0x18,0xF8 ,0xBf};

		DWORD_PTR youthFacilitiesAddr = 0x1469D3900;
		DWORD_PTR youthFacilitiesOffset[3] ={ 0x18,0xF8 ,0xCB};
	
		DWORD_PTR youthImportanceAddr = 0x1469D3900;
		DWORD_PTR youthImportanceOffset[3] ={ 0x18,0xF8 ,0xC6};

		DWORD_PTR youthRecruitmentAddr = 0x1469D3900;
		DWORD_PTR youthRecruitmentOffset[3] ={ 0x18,0xF8 ,0xCD};

		DWORD_PTR juniorCoachingAddr = 0x1469D3900;
		DWORD_PTR juniorCoachingOffset[3] ={ 0x18,0xF8 ,0xCC};

		DWORD_PTR corporateFacilitiesAddr = 0x1469D3900;
		DWORD_PTR corporateFacilitiesOffset[3] ={ 0x18,0x148 ,0x759};
	
		DWORD_PTR moraleAddr = 0x1469D3900;
		DWORD_PTR moraleOffset[3] ={ 0x18,0xF8 ,0xC0};

		DWORD_PTR averageAttendanceAddr = 0x1469D3900;
		DWORD_PTR averageAttendanceOffset[3] ={ 0x18,0xB0 ,0x68};

		DWORD_PTR minimumAttendanceAddr = 0x1469D3900;
		DWORD_PTR minimumAttendanceOffset[3] ={ 0x18,0xB0 ,0x6C};

		DWORD_PTR maximumAttendanceAddr = 0x1469D3900;
		DWORD_PTR maximumAttendanceOffset[3] ={ 0x18,0xB0 ,0x70};

		DWORD_PTR competitionAddr = 0x1469D3900;
		DWORD_PTR competitionOffset[3] = { 0x120,0x58,0x4 };

	};

	struct Finances
	{
		DWORD_PTR balanceAddr = 0x1469D3900;
		DWORD_PTR balanceOffset[3] ={ 0x18,0x148 ,0x18};

		DWORD_PTR transferBudgetSeasonAddr = 0x1469D3900;
		DWORD_PTR transferBudgetSeasonOffset[3] ={ 0x18,0x148 ,0x680};

		DWORD_PTR transferBudgetRemAddr = 0x1469D3900;
		DWORD_PTR transferBudgetRemOffset[3] ={ 0x18,0x148 ,0x67C};

		DWORD_PTR trnIncomeMadeAvailableAddr = 0x1469D3900;
		DWORD_PTR trnIncomeMadeAvailableOffset[3] ={ 0x18,0x148 ,0x684};

		DWORD_PTR weeklyWageBudgetAddr = 0x1469D3900;
		DWORD_PTR weeklyWageBudgetOffset[3] ={ 0x18,0x148 ,0x6B8};

		DWORD_PTR weeklyWageBudgetUsedAddr = 0x1469D3900;
		DWORD_PTR weeklyWageBudgetUsedOffset[3] ={ 0x18,0x148 ,0x6C4};
	
		DWORD_PTR highestWageAllowedAddr = 0x1469D3900;
		DWORD_PTR highestWageAllowedOffset[3] ={ 0x18,0x148 ,0x6BC};

		DWORD_PTR highestWagePaidWAddr = 0x1469D3900;
		DWORD_PTR highestWagePaidWOffset[3] ={ 0x18,0x148 ,0x6D8};

		DWORD_PTR highestStaffWagePaidWAddr = 0x1469D3900;
		DWORD_PTR highestStaffWagePaidWOffset[3] ={ 0x18,0x148 ,0x6DC};

		DWORD_PTR youthGrantIncomeAddr = 0x1469D3900;
		DWORD_PTR youthGrantIncomeOffset[3] ={ 0x18,0x148 ,0x690};

		DWORD_PTR sugarDaddyAddr = 0x1469D3900;
		DWORD_PTR sugarDaddyOffset[3] ={ 0x18,0x148 ,0x3D};

		DWORD_PTR averageMatchTicketPriceAddr = 0x1469D3900;
		DWORD_PTR averageMatchTicketPriceOffset[3] ={ 0x18,0x148 ,0x1C};

		DWORD_PTR averageSeasonTicketPriceAddr = 0x1469D3900;
		DWORD_PTR averageSeasonTicketPriceOffset[3] ={ 0x18,0x148 ,0x20};

		DWORD_PTR matchTicketPriceRatioAddr = 0x1469D3900;
		DWORD_PTR matchTicketPriceRatioOffset[3] ={ 0x18,0x148 ,0x24};

		DWORD_PTR seasonTicketPriceRatioAddr = 0x1469D3900;
		DWORD_PTR  seasonTicketPriceRatioOffset[3] ={ 0x18,0x148 ,0x28};

		DWORD_PTR seasonTicketChangeRatioAddr = 0x1469D3900;
		DWORD_PTR seasonTicketChangeRatioOffset[3] ={ 0x18,0xF8 ,0x2C};

		DWORD_PTR numberOfSeasonTicketHoldersAddr = 0x1469D3900;
		DWORD_PTR numberOfSeasonTicketHoldersOffset[3] ={ 0x18,0x148 ,0x80};

		DWORD_PTR latestSeasonTicketSalesAddr = 0x1469D3900;
		DWORD_PTR latestSeasonTicketSalesOffset[3] ={ 0x18,0x148 ,0x7DC};

		DWORD_PTR stadiumRentalPerYearAddr = 0x1469D3900;
		DWORD_PTR stadiumRentalPerYearOffset[3] ={ 0x18,0x148 ,0x6AC};

		DWORD_PTR stateOfEmergencyAddr = 0x1469D3900;
		DWORD_PTR stateOfEmergencyOffset[3] ={ 0x18,0x148 ,0x74D};

		DWORD_PTR startingLastYearsTurnoverAddr = 0x1469D3900;
		DWORD_PTR startingLastYearsTurnoverOffset[3] ={ 0x18,0x148 ,0x6B0};

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
		int  guidingID = 1177780600;
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

