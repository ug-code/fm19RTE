#include <iostream>
#include <Windows.h>
#include "GameVersions.h"
#include "Helpers.h"
#include <iomanip>
#include "service\ServiceMyProfile.h"
#include "service\ServiceCurrentClub.h"
#include "service\ServiceClub.h"
#include "service\ServicePlayer.h"
#include <fstream>


using namespace std;

//Current team setting
unsigned int currentMoney;

//Change team setting
double newMoney;


void TestGroup(HANDLE phandle) {
	ServiceCurrentClub serviceCurrentClub;
	ServiceClub serviceClub;
	ServicePlayer servicePlayer;

	DWORD_PTR pTemp;
	DWORD_PTR pointerAddr;


	//playerlist 	unique number =1177858536
	servicePlayer.scanPlayerList(phandle);//1177786120

										  //teamlist  unique number =1177833896
	serviceClub.scanClubList(phandle);
	system("pause");
	exit(0);




	char rightStr[] = "Mezitlispor";
	std::ofstream searchFile;
	searchFile.open("search.txt", std::ios_base::app);
	DWORD_PTR firstSearch = 0x09E330BC;
	DWORD_PTR lastSearch = 0x0A10E59C;
	int searchCount = ((lastSearch - firstSearch) / 0x20);
	cout << "searchCount    :" << searchCount << endl;
	for (int c = 0; c < searchCount; c++) {
		searchFile << readBuffer(phandle, firstSearch + (c * 0x20), 32) << '\n';;

	}
	DWORD_PTR firstSearch42 = 0x42CF896C;
	DWORD_PTR lastSearch42 = 0x42D289AC;
	int searchCount42 = ((lastSearch42 - firstSearch42) / 0x20);
	cout << "searchCount    :" << searchCount42 << endl;
	for (int c = 0; c < searchCount42; c++) {
		searchFile << readBuffer(phandle, firstSearch42 + (c * 0x20), 32) << '\n';;
	}

	system("pause");
	exit(0);





	std::ofstream teamfile;
	teamfile.open("team_list.txt", std::ios_base::app);
	DWORD_PTR firstTeamPointer = 0x42D189CC;
	DWORD_PTR lastTeamPointer = 0x42D289AC;
	int teamCount = ((lastTeamPointer - firstTeamPointer) / 0x20);
	cout << "cityCount    :" << teamCount << endl;
	for (int c = 0; c < teamCount; c++) {
		teamfile << readBuffer(phandle, firstTeamPointer + (c * 0x20), 32) << '\n';;

	}

	system("pause");
	exit(0);


	std::ofstream cityfile;
	cityfile.open("juventus_load_city.txt", std::ios_base::app);
	DWORD_PTR firstCityPointer = 0x09E430EC;
	DWORD_PTR lastCityPointer = 0x09E530CC;
	int cityCount = ((lastCityPointer - firstCityPointer) / 0x20);
	cout << "cityCount    :" << cityCount << endl;
	for (int c = 0; c < cityCount; c++) {
		cityfile << readBuffer(phandle, firstCityPointer + (c * 0x20), 32) << '\n';;

	}

	system("pause");
	exit(0);




	std::ofstream outfile;
	outfile.open("juventus_load_team.txt", std::ios_base::app);
	DWORD_PTR teamPointer = 0x0A0F38AC;
	for (int c = 0; c < 122333; c++) {
		outfile << readBuffer(phandle, teamPointer + (c * 0x20), 32) << '\n';;
		//cout << "First Team    :" << readBuffer(phandle, 0x09E330BC+(c*0x20), 32) << endl;

	}
	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");
}
void CurrenTeamGroup() {

	SetConsoleTitle("FM19 REAL EDITOR");
	About();
	HANDLE phandle = GameLoad(windowName);
	ServiceCurrentClub serviceCurrentClub;
	cout << "Current Team                    :" << serviceCurrentClub.getFullname(phandle) << endl;
	cout << "Current repulation              :" << serviceCurrentClub.getReputation(phandle) << endl;
	cout << "Current competition             :" << serviceCurrentClub.getCompetition(phandle) << endl;
	cout << "Current nation                  :" << serviceCurrentClub.getNation(phandle) << endl;
	//cout << "Current money value             :" << serviceCurrentClub.getMoney(phandle) << endl;
	cout << "Please enter an new money value : ";
	cin >> newMoney;

	serviceCurrentClub.setClubMoney(phandle, newMoney);
	cout << "New money value : " <<fixed << newMoney << endl;

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");

}
void MyProfileGroup(HANDLE phandle) {
	ServiceMyProfile serviceMyProfile;
	cout << "|--------------MyProfile-------------------||" << endl;
	cout << "getRowId                 :" << serviceMyProfile.getRowId(phandle) << endl;
	cout << "getUniqeId               :" << serviceMyProfile.getUniqeId(phandle) << endl;
	cout << "getCoachingLicense       :" << serviceMyProfile.getCoachingLicense(phandle) << endl;
	cout << "|--------------Characteristic--------------||" << endl;
	cout << "getHandsOnApproach       :" << serviceMyProfile.characteristic.getHandsOnApproach(phandle) << endl;
	cout << "getTacticalConsistency   :" << serviceMyProfile.characteristic.getTacticalConsistency(phandle) << endl;
	cout << "getClubPlayerLoyalty     :" << serviceMyProfile.characteristic.getClubPlayerLoyalty(phandle) << endl;
	cout << "getSquadDiscipline       :" << serviceMyProfile.characteristic.getSquadDiscipline(phandle) << endl;
	cout << "getFinancialControl      :" << serviceMyProfile.characteristic.getFinancialControl(phandle) << endl;
	cout << "getMediaHandling         :" << serviceMyProfile.characteristic.getMediaHandling(phandle) << endl;
	cout << "||--------------Reputation------------------||" << endl;
	cout << "getHomeRep               :" << serviceMyProfile.reputation.getHomeRep(phandle) << endl;
	cout << "getCurrentRep            :" << serviceMyProfile.reputation.getCurrentRep(phandle) << endl;
	cout << "getWorldRep              :" << serviceMyProfile.reputation.getWorldRep(phandle) << endl;
	cout << "||--------------Contract--------------------||" << endl;
	cout << "getHomeRep               :" << serviceMyProfile.contract.getType(phandle) << endl;
	cout << "getJobType               :" << serviceMyProfile.contract.getJobType(phandle) << endl;
	cout << "getWeeklyWage            :" << serviceMyProfile.contract.getWeeklyWage(phandle) << endl;

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");

}
void scanPlayerList(HANDLE phandle) {
	ServicePlayer servicePlayer;
	cout << "|--------------Player-------------------||" << endl;
	const char someData[] = "boluspor";

	servicePlayer.findPlayer(phandle);

	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");
}
int main() {
	SetConsoleTitle("FM19 REAL EDITOR");
	About();
	HANDLE phandle = GameLoad(windowName);
	//MyProfileGroup(phandle);
	scanPlayerList(phandle);
	return 0;

}



