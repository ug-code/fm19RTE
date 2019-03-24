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
	cout << "New money value : " << fixed << newMoney << endl;

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

	//servicePlayer.getPlayers(phandle);
	servicePlayer.testPlayerList(phandle);


	//Close any handles once the program is over
	CloseHandle(phandle);
	system("pause");
}


void playerDetail(HANDLE phandle, int playerUniqueID = 70103100, DWORD_PTR playerUniqueAdress = 0) {
	ServicePlayer servicePlayer;
	DWORD_PTR playerUA;
	if (playerUniqueAdress == 0) {
		playerUA = servicePlayer.findPlayerUniqueAdress(phandle, playerUniqueID);
	}
	else {
		playerUA = playerUniqueAdress;
	}
	PlayerDetail player = servicePlayer.getPlayerDetail(phandle, playerUniqueID, playerUA);
	cout << "|--------------Player Detail-------------------||" << endl;
	cout << "getRowID                       : " << player.getRowID << endl;
	cout << "getUniqeID                     : " << player.getUniqeID << endl;
	cout << "getFirstname                   : " << player.getFirstname << endl;
	cout << "getLastname                    : " << player.getLastname << endl;
	//cout << "getFullname                    : " << player.getFullname << endl;
	cout << "getBirthYear                   : " << player.getBirthYear << endl;
	cout << "getEthnicity                   : " << player.getEthnicity << endl;
	cout << "getHairColour                  : " << player.getHairColour << endl;
	cout << "getHairLength                  : " << player.getHairLength << endl;
	cout << "getSkinTone                    : " << player.getSkinTone << endl;
	cout << "getHeight                      : " << player.getHeight << endl;
	cout << "getWeight                      : " << player.getWeight << endl;
	cout << "getMorale                      : " << player.getMorale << endl;
	cout << "getDeclaredForNation           : " << player.getDeclaredForNation << endl;
	cout << "getInternationalApps           : " << player.getInternationalApps << endl;
	cout << "getInternationalGoals          : " << player.getInternationalGoals << endl;
	cout << "getGeneralOptions              : " << player.getGeneralOptions << endl;
	cout << "getBans                        : " << player.getBans << endl;
	cout << "getInjuries                    : " << player.getInjuries << endl;
	cout << "|--------------Player attributes-------------------||" << endl;
	cout << "|--------------^Player technical-------------------||" << endl;
	cout << "getCorners                     : " << player.attributes.technical.getCorners << endl;
	cout << "getCrossing                    : " << player.attributes.technical.getCrossing << endl;
	cout << "getDribbling                   : " << player.attributes.technical.getDribbling << endl;
	cout << "getFinishing                   : " << player.attributes.technical.getFinishing << endl;
	cout << "getFirstTouch                  : " << player.attributes.technical.getFirstTouch << endl;
	cout << "getFreeKickTaking              : " << player.attributes.technical.getFreeKickTaking << endl;
	cout << "getHeading                     : " << player.attributes.technical.getHeading << endl;
	cout << "getLongShots                   : " << player.attributes.technical.getLongShots << endl;
	cout << "getLongThrows                  : " << player.attributes.technical.getLongThrows << endl;
	cout << "getMarking                     : " << player.attributes.technical.getMarking << endl;
	cout << "getPassing                     : " << player.attributes.technical.getPassing << endl;
	cout << "getPenaltyTaking               : " << player.attributes.technical.getPenaltyTaking << endl;
	cout << "getTackling                    : " << player.attributes.technical.getTackling << endl;
	cout << "getTechnique                   : " << player.attributes.technical.getTechnique << endl;
	cout << "|--------------^Player goalkeeping-------------------||" << endl;
	cout << "getAerialReach                 : " << player.attributes.goalkeeping.getAerialReach << endl;
	cout << "getCommandOfArea               : " << player.attributes.goalkeeping.getCommandOfArea << endl;
	cout << "getCommunication               : " << player.attributes.goalkeeping.getCommunication << endl;
	cout << "getEccentricity                : " << player.attributes.goalkeeping.getEccentricity << endl;
	cout << "getHandling                    : " << player.attributes.goalkeeping.getHandling << endl;
	cout << "getKicking                     : " << player.attributes.goalkeeping.getKicking << endl;
	cout << "getOneOnOnes                   : " << player.attributes.goalkeeping.getOneOnOnes << endl;
	cout << "getReflexes                    : " << player.attributes.goalkeeping.getReflexes << endl;
	cout << "getRushingOut                  : " << player.attributes.goalkeeping.getRushingOut << endl;
	cout << "getTendencyToPunch             : " << player.attributes.goalkeeping.getTendencyToPunch << endl;
	cout << "getThrowing                    : " << player.attributes.goalkeeping.getThrowing << endl;
	cout << "|--------------^Player abilities-------------------||" << endl;
	cout << "getCA                         : " << player.abilities.getCA << endl;
	cout << "getPA                         : " << player.abilities.getPA << endl;
	cout << "getLeftFoot                   : " << player.abilities.getLeftFoot << endl;
	cout << "getRightFoot                  : " << player.abilities.getRightFoot << endl;
	cout << "getMatchSharpness             : " << player.abilities.getMatchSharpness << endl;
	cout << "getMatchExercise              : " << player.abilities.getMatchExercise << endl;
	cout << "|--------------^Player Contract-------------------||" << endl;
	cout << "getClubUniqueID               : " << player.contract.getClubUniqueID << endl;
	cout << "getType                       : " << player.contract.getType << endl;
	cout << "getJobType                    : " << player.contract.getJobType << endl;
	cout << "getValue                      : " << player.contract.getValue << endl;
	cout << "getAskingPrice                : " << player.contract.getAskingPrice << endl;
	cout << "getWeeklyWage                 : " << player.contract.getWeeklyWage << endl;
	cout << "getStartDayOfYear             : " << player.contract.getStartDayOfYear << endl;
	cout << "getStartYear                  : " << player.contract.getStartYear << endl;
	cout << "getEndDayOfYear               : " << player.contract.getEndDayOfYear << endl;
	cout << "getEndYear                    : " << player.contract.getEndYear << endl;
	cout << "getJoinDayOfYear              : " << player.contract.getJoinDayOfYear << endl;
	cout << "getJoinYear                   : " << player.contract.getJoinYear << endl;
	cout << "getLoyaltyBonus               : " << player.contract.getLoyaltyBonus << endl;
	cout << "getSquadStatus                : " << player.contract.getSquadStatus << endl;
	cout << "getSquadNumber                : " << player.contract.getSquadNumber << endl;

}


void playerDatatable(HANDLE phandle) {
	ServicePlayer servicePlayer;
	map<int, DWORD_PTR> playersList = servicePlayer.getPlayerList(phandle);
	// Iterating the map and printing ordered values 
	for (auto i = playersList.begin(); i != playersList.end(); i++) {
		int PlayerUniqueID = i->first;
		DWORD_PTR playerPointerAddress = i->second;

		string getFirstname = servicePlayer.getFirstname(phandle, playerPointerAddress);
		string getLastname = servicePlayer.getLastname(phandle, playerPointerAddress);
		short getCA = servicePlayer.abilities.getCA(phandle, playerPointerAddress);
		short getPA = servicePlayer.abilities.getPA(phandle, playerPointerAddress);
		int getClubUniqueID = servicePlayer.contract.getClubUniqueID(phandle, playerPointerAddress);
		int getValue = servicePlayer.contract.getValue(phandle, playerPointerAddress);

		//PlayerDetail player = servicePlayer.getPlayerDetail(phandle, PlayerUniqueID, playerPointerAddress);
		//playerDetail(phandle, PlayerUniqueID, playerPointerAddress);
		std::cout << PlayerUniqueID << " "
			<< getFirstname << " "
			<< getLastname << " "
			<< getCA << " "
			<< getPA << " "
			<< getClubUniqueID << " "
			<< getValue << " "

			<< '\n';
	}
	//DWORD_PTR playerUniqueAdress = servicePlayer.findPlayerUniqueAdress(phandle, 70103100);
}


void clubDetail(HANDLE phandle, int clubUniqueID = 1725, DWORD_PTR clubUniqueAdress = 0) {
	ServiceClub serviceClub;
	DWORD_PTR clubUA;
	if (clubUniqueAdress == 0) {
		clubUA = serviceClub.findClubUniqueAdress(phandle, clubUniqueID);
	}
	else {
		clubUA = clubUniqueAdress;
	}
	cout << "|--------------Player Detail-------------------||" << endl;
	cout << "getRowID                       : " << serviceClub.getRowID(phandle, clubUA) << endl;
	cout << "getUniqeID                     : " << serviceClub.getUniqeID(phandle, clubUA) << endl;
	cout << "getFullname                    : " << serviceClub.getFullname(phandle, clubUA) << endl;


}

void benchmarkFindPlayerUniqueAdress(HANDLE phandle, int playerUniqueID = 70103100) {
	ServicePlayer servicePlayer;
	DWORD_PTR playerUniqueAdress = servicePlayer.findPlayerUniqueAdress(phandle, playerUniqueID);
}

void testFullPlayer(HANDLE phandle) {
	ServicePlayer servicePlayer;
	PlayerDetail* playersDetail = servicePlayer.getPlayersWithDetail(phandle);


	for (int i = 0; i < sizeof(playersDetail); i++) {
		cout << "player id" << playersDetail[i].getFirstname << endl;
		//PlayerDetail player = playersDetail[i];

	}
}

void hardcodeClubLis(HANDLE phandle) {
	ServiceClub serviceClub;
	serviceClub.scanClubList(phandle);

}

void testFullClub(HANDLE phandle) {
	ServiceClub serviceClub;
	serviceClub.testClubList(phandle);
}
int main() {

	const clock_t begin_time = clock();

	SetConsoleTitle("FM19 REAL EDITOR");
	About();
	HANDLE phandle = GameLoad(windowName);
	//MyProfileGroup(phandle);
	//scanPlayerList(phandle);
	//playerDetail(phandle, 7458500);
	//testFullPlayer(phandle);
	//testFullClub(phandle);
	//hardcodeClubLis(phandle);
	clubDetail(phandle);
	//playerDatatable(phandle);
	//benchmarkFindPlayerUniqueAdress(phandle);
	CloseHandle(phandle);
	printf("Time taken: %.2fs\n", (double)(clock() - begin_time) / CLOCKS_PER_SEC);
	system("pause");
	return 0;

}



