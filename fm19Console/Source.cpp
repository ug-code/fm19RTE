#include <iostream>
#include <Windows.h>
#include "GameVersions.h"
#include "Helpers.h"
#include <iomanip>
#include "service\ServiceClub.h"


using namespace std;

//Current team setting
unsigned int currentMoney;

//Change team setting
double newMoney;

int main() {

	SetConsoleTitle("FM19 REAL EDITOR");
	About();
	HANDLE phandle = GameLoad(windowName);
	ServiceClub serviceClub;

	cout << "Current Team                    :" << serviceClub.getClubFullname(phandle) << endl;
	cout << "Current repulation              :" << serviceClub.getClubReputation(phandle) << endl;
	cout << "Current competition             :" << serviceClub.getClubCompetition(phandle) << endl;
	cout << "Current nation                  :" << serviceClub.getClubNation(phandle) << endl;
	cout << "Current money value             :" << serviceClub.getClubMoney(phandle) << endl;
	cout << "Please enter an new money value : ";
	cin >> newMoney;

	serviceClub.setClubMoney(phandle, newMoney);
	cout << "New money value : " <<fixed << newMoney << endl;

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");

	return ERROR_SUCCESS;
}



