#include <iostream>
#include <Windows.h>
#include "GameVersions.h"
#include "Helpers.h"


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
	cout << "Current My Team: " << clubFullname.currentValue << endl;


	CurrentMemory currentMoney = FindDmaAddy(phandle, currentClub.finances.moneyAddr, currentClub.finances.moneyOffsets, 5);
	cout << "Current money value: " << currentMoney.currentValue << endl;
	cout << "Please enter an new money value: ";
	cin >> newMoney;


	int isWriteProcess = WritePointer(phandle, currentClub.finances.moneyAddr, newMoney, currentClub.finances.moneyOffsets, 5);
	if (!isWriteProcess) {
		std::cerr << "Couldn't write process memory:" << GetLastError() << std::endl;
		getchar();
	}
	cout << "New money value : " << newMoney <<endl;

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");


	return ERROR_SUCCESS;
}



