#include <iostream>
#include <Windows.h>
#include "GameVersions.h"
#include "Helpers.h"
#include <iomanip>


using namespace std;

//Current team setting
unsigned int currentMoney;

//Change team setting
int newMoney;

int main() {

	SetConsoleTitle(L"FM19 REAL EDITOR");
	About();
	HANDLE phandle = GameLoad(windowName);
	CurrentClub currentClub;


	CurrentMemory clubFullname = FindDmaAddy(phandle, currentClub.information.fullNameAddr, currentClub.information.fullNameOffset, 5);
	cout << "Current my Team: " << myInt2text(clubFullname.currentValue) << endl;

	CurrentMemory clubReputation = FindDmaAddy(phandle, currentClub.information.reputationAddr, currentClub.information.reputationOffset, 1);
	short repulationValue = clubReputation.currentValue;
	cout << "Current my repulation: " << (repulationValue) << endl;

	CurrentMemory clubCompetition = FindDmaAddy(phandle, currentClub.information.competitionAddr, currentClub.information.competitionOffset, 3);
	cout << "Current my competition: " << myInt2text(clubCompetition.currentValue) << endl;


	CurrentMemory clubNation = FindDmaAddy(phandle, currentClub.information.nationAddr, currentClub.information.nationOffset,4 );
	cout << "Current my nation: " << myInt2text(clubNation.currentValue) << endl;

	CurrentMemory currentMoney = FindDmaAddy(phandle, currentClub.finances.moneyAddr, currentClub.finances.moneyOffsets, 5);
	cout << "Current money value: " << currentMoney.currentValue << endl;
	cout << "Please enter an new money value: ";
	cin >> newMoney;


	int isWriteProcess = WritePointer(phandle, currentClub.finances.moneyAddr, newMoney, currentClub.finances.moneyOffsets, 5);
	if (!isWriteProcess) {
		std::cerr << "Couldn't write process memory:" << GetLastError() << std::endl;
		getchar();
	}
	cout << "New money value : " << newMoney << endl;

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");

	return ERROR_SUCCESS;
}



