#ifndef SERVICEPLAYER_H
#define SERVICEPLAYER_H
#pragma once
#include <map>


struct PlayerDetail
{
	int getRowID;
	int getUniqeID;
	char* getFirstname;
	char* getLastname;
	//char* getFullname = "";
	short getBirthYear;
	short getEthnicity;
	short getHairColour;
	short getHairLength;
	short getSkinTone;
	short getHeight;
	short getWeight;
	short getMorale;
	short getDeclaredForNation;
	short getInternationalApps;
	short getInternationalGoals;
	short getGeneralOptions;
	short getBans;
	short getInjuries;
	struct Attributes {
		struct Technical {
			short getCorners;
			short getCrossing;
			short getDribbling;
			short getFinishing;
			short getFirstTouch;
			short getFreeKickTaking;
			short getHeading;
			short getLongShots;
			short getLongThrows;
			short getMarking;
			short getPassing;
			short getPenaltyTaking;
			short getTackling;
			short getTechnique;
		};
		struct Goalkeeping {
			short getAerialReach;
			short getCommandOfArea;
			short getCommunication;
			short getEccentricity;
			short getHandling;
			short getKicking;
			short getOneOnOnes;
			short getReflexes;
			short getRushingOut;
			short getTendencyToPunch;
			short getThrowing;
		};
		struct Mental {
			short getAggression;
			short getAnticipation;
			short getBravery;
			short getComposure;
			short getConcentration;
			short getDecision;
			short getDetermination;
			short getFlair;
			short getLeadership;
			short getOffTheBall;
			short getPositioning;
			short getTeamwork;
			short getVision;
			short getWorkRate;
		};
		struct Physical {

			short getAcceleration;
			short getAgility;
			short getBalance;
			short getJumpingReach;
			short getNaturalFitness;
			short getPace;
			short getStamina;
			short getStrength;
		};
		struct Hidden {
			short getDirtiness;
			short getConsistency;
			short getImpMatches;
			short getInjuryProneness;
			short getVersatility;
		};

		Technical technical;
		Goalkeeping goalkeeping;
		Mental mental;
		Physical physical;
		Hidden hidden;
	};

	struct Positions {
		short getRoleUsedToFillEmptyAttributes;
		short getPreferredCentralPosition;
		short getGK;
		short getSW;
		short getDL;
		short getDC;
		short getDR;
		short getWBL;
		short getWBR;
		short getDM;
		short getML;
		short getMC;
		short getMR;
		short getAML;
		short getAMC;
		short getAMR;
		short getST;
	};
	struct Abilities {
		short getCA;
		short getPA;
		short getLeftFoot;
		short getRightFoot;
		short getMatchSharpness;
		short getMatchExercise;
	};

	struct Personality {

		short getAdaptability;
		short getAmbition;
		short getControversy;
		short getLoyalty;
		short getPressure;
		short getProfessionalism;
		short getSportmanship;
		short getTemperament;

	};

	struct Contract {
		int getClubUniqueID;
		short getType;
		short getJobType;
		int getValue;
		int getAskingPrice;
		int getWeeklyWage;
		short getStartDayOfYear;
		short getStartYear;
		short getEndDayOfYear;
		short getEndYear;
		short getJoinDayOfYear;
		short getJoinYear;
		int getLoyaltyBonus;
		short getSquadStatus;
		short getSquadNumber;
	};

	Attributes attributes;
	Positions positions;
	Abilities abilities;
	Personality personality;
	Contract contract;
};

class ServicePlayer
{
	Player player;

public:

	DWORD_PTR findPlayerUniqueAdress(HANDLE phandle, int PlayerID){
		 DWORD_PTR playerUniqueAdress = getPlayerBaseAddress(phandle, PlayerID);
		 return playerUniqueAdress;
	}

	PlayerDetail getPlayerDetail(HANDLE phandle, int PlayerID, DWORD_PTR playerUniqueAdress) {
		PlayerDetail playerDetail;
		//DWORD_PTR playerUniqueAdress = getPlayerBaseAddress(phandle, PlayerID);
		//Information
		playerDetail.getRowID = getRowID(phandle, playerUniqueAdress);
		playerDetail.getUniqeID = PlayerID;
		playerDetail.getFirstname = getFirstname(phandle, playerUniqueAdress);
		playerDetail.getLastname = getLastname(phandle, playerUniqueAdress);
		//playerDetail.getFullname = getFullname(phandle, playerUniqueAdress);
		playerDetail.getBirthYear = getBirthYear(phandle, playerUniqueAdress);
		playerDetail.getEthnicity = getEthnicity(phandle, playerUniqueAdress);
		playerDetail.getHairColour = getHairColour(phandle, playerUniqueAdress);
		playerDetail.getHairLength = getHairLength(phandle, playerUniqueAdress);
		playerDetail.getSkinTone = getSkinTone(phandle, playerUniqueAdress);
		playerDetail.getHeight = getHeight(phandle, playerUniqueAdress);
		playerDetail.getWeight = getWeight(phandle, playerUniqueAdress);
		playerDetail.getMorale = getMorale(phandle, playerUniqueAdress);
		playerDetail.getDeclaredForNation = getDeclaredForNation(phandle, playerUniqueAdress);
		playerDetail.getInternationalApps = getInternationalApps(phandle, playerUniqueAdress);
		playerDetail.getInternationalGoals = getInternationalGoals(phandle, playerUniqueAdress);
		playerDetail.getGeneralOptions = getGeneralOptions(phandle, playerUniqueAdress);
		playerDetail.getBans = getBans(phandle, playerUniqueAdress);
		playerDetail.getInjuries = getInjuries(phandle, playerUniqueAdress);
		//Attributes
		//-techical
		playerDetail.attributes.technical.getCorners = attributes.technical.getCorners(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getCrossing = attributes.technical.getCrossing(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getDribbling = attributes.technical.getDribbling(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getFinishing = attributes.technical.getFinishing(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getFirstTouch = attributes.technical.getFirstTouch(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getFreeKickTaking = attributes.technical.getFreeKickTaking(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getHeading = attributes.technical.getHeading(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getLongShots = attributes.technical.getLongShots(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getLongThrows = attributes.technical.getLongThrows(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getMarking = attributes.technical.getMarking(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getPassing = attributes.technical.getPassing(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getPenaltyTaking = attributes.technical.getPenaltyTaking(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getTackling = attributes.technical.getTackling(phandle, playerUniqueAdress);
		playerDetail.attributes.technical.getTechnique = attributes.technical.getTechnique(phandle, playerUniqueAdress);
		//-goalkeeping
		playerDetail.attributes.goalkeeping.getAerialReach = attributes.goalkeeping.getAerialReach(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getCommandOfArea = attributes.goalkeeping.getCommandOfArea(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getCommunication = attributes.goalkeeping.getCommunication(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getEccentricity = attributes.goalkeeping.getEccentricity(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getHandling = attributes.goalkeeping.getHandling(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getKicking = attributes.goalkeeping.getKicking(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getOneOnOnes = attributes.goalkeeping.getOneOnOnes(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getReflexes = attributes.goalkeeping.getReflexes(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getRushingOut = attributes.goalkeeping.getRushingOut(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getTendencyToPunch = attributes.goalkeeping.getTendencyToPunch(phandle, playerUniqueAdress);
		playerDetail.attributes.goalkeeping.getThrowing = attributes.goalkeeping.getThrowing(phandle, playerUniqueAdress);
		//-mental
		playerDetail.attributes.mental.getAggression = attributes.mental.getAggression(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getAnticipation = attributes.mental.getAnticipation(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getBravery = attributes.mental.getBravery(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getComposure = attributes.mental.getComposure(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getConcentration = attributes.mental.getConcentration(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getDecision = attributes.mental.getDecision(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getDetermination = attributes.mental.getDetermination(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getFlair = attributes.mental.getFlair(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getLeadership = attributes.mental.getLeadership(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getOffTheBall = attributes.mental.getOffTheBall(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getPositioning = attributes.mental.getPositioning(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getTeamwork = attributes.mental.getTeamwork(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getVision = attributes.mental.getVision(phandle, playerUniqueAdress);
		playerDetail.attributes.mental.getWorkRate = attributes.mental.getWorkRate(phandle, playerUniqueAdress);
		//-physical
		playerDetail.attributes.physical.getAcceleration = attributes.physical.getAcceleration(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getAgility = attributes.physical.getAgility(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getBalance = attributes.physical.getBalance(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getJumpingReach = attributes.physical.getJumpingReach(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getNaturalFitness = attributes.physical.getNaturalFitness(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getPace = attributes.physical.getPace(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getStamina = attributes.physical.getStamina(phandle, playerUniqueAdress);
		playerDetail.attributes.physical.getStrength = attributes.physical.getStrength(phandle, playerUniqueAdress);

		//-hidden
		playerDetail.attributes.hidden.getDirtiness = attributes.hidden.getDirtiness(phandle, playerUniqueAdress);
		playerDetail.attributes.hidden.getConsistency = attributes.hidden.getConsistency(phandle, playerUniqueAdress);
		playerDetail.attributes.hidden.getImpMatches = attributes.hidden.getImpMatches(phandle, playerUniqueAdress);
		playerDetail.attributes.hidden.getInjuryProneness = attributes.hidden.getInjuryProneness(phandle, playerUniqueAdress);
		playerDetail.attributes.hidden.getVersatility = attributes.hidden.getVersatility(phandle, playerUniqueAdress);

		//positions
		playerDetail.positions.getRoleUsedToFillEmptyAttributes = positions.getRoleUsedToFillEmptyAttributes(phandle, playerUniqueAdress);
		playerDetail.positions.getPreferredCentralPosition = positions.getPreferredCentralPosition(phandle, playerUniqueAdress);
		playerDetail.positions.getGK = positions.getGK(phandle, playerUniqueAdress);
		playerDetail.positions.getSW = positions.getSW(phandle, playerUniqueAdress);
		playerDetail.positions.getDL = positions.getDL(phandle, playerUniqueAdress);
		playerDetail.positions.getDC = positions.getDC(phandle, playerUniqueAdress);
		playerDetail.positions.getDR = positions.getDR(phandle, playerUniqueAdress);
		playerDetail.positions.getWBL = positions.getWBL(phandle, playerUniqueAdress);
		playerDetail.positions.getWBR = positions.getWBR(phandle, playerUniqueAdress);
		playerDetail.positions.getDM = positions.getDM(phandle, playerUniqueAdress);
		playerDetail.positions.getML = positions.getML(phandle, playerUniqueAdress);
		playerDetail.positions.getMC = positions.getMC(phandle, playerUniqueAdress);
		playerDetail.positions.getMR = positions.getMR(phandle, playerUniqueAdress);
		playerDetail.positions.getAML = positions.getAML(phandle, playerUniqueAdress);
		playerDetail.positions.getAMC = positions.getAMC(phandle, playerUniqueAdress);
		playerDetail.positions.getAMR = positions.getAMR(phandle, playerUniqueAdress);
		playerDetail.positions.getST = positions.getST(phandle, playerUniqueAdress);

		//abilities
		playerDetail.abilities.getCA = abilities.getCA(phandle, playerUniqueAdress);
		playerDetail.abilities.getPA = abilities.getPA(phandle, playerUniqueAdress);
		playerDetail.abilities.getLeftFoot = abilities.getLeftFoot(phandle, playerUniqueAdress);
		playerDetail.abilities.getRightFoot = abilities.getRightFoot(phandle, playerUniqueAdress);
		playerDetail.abilities.getMatchSharpness = abilities.getMatchSharpness(phandle, playerUniqueAdress);
		playerDetail.abilities.getMatchExercise = abilities.getMatchExercise(phandle, playerUniqueAdress);

		//personality
		playerDetail.personality.getAdaptability = personality.getAdaptability(phandle, playerUniqueAdress);
		playerDetail.personality.getAmbition = personality.getAmbition(phandle, playerUniqueAdress);
		playerDetail.personality.getControversy = personality.getControversy(phandle, playerUniqueAdress);
		playerDetail.personality.getLoyalty = personality.getLoyalty(phandle, playerUniqueAdress);
		playerDetail.personality.getPressure = personality.getPressure(phandle, playerUniqueAdress);
		playerDetail.personality.getProfessionalism = personality.getProfessionalism(phandle, playerUniqueAdress);
		playerDetail.personality.getSportmanship = personality.getSportmanship(phandle, playerUniqueAdress);
		playerDetail.personality.getTemperament = personality.getTemperament(phandle, playerUniqueAdress);
		//contract
		playerDetail.contract.getClubUniqueID = contract.getClubUniqueID(phandle, playerUniqueAdress);
		playerDetail.contract.getType = contract.getType(phandle, playerUniqueAdress);
		playerDetail.contract.getJobType = contract.getJobType(phandle, playerUniqueAdress);
		playerDetail.contract.getValue = contract.getValue(phandle, playerUniqueAdress);
		playerDetail.contract.getAskingPrice = contract.getAskingPrice(phandle, playerUniqueAdress);
		playerDetail.contract.getWeeklyWage = contract.getWeeklyWage(phandle, playerUniqueAdress);
		playerDetail.contract.getStartDayOfYear = contract.getStartDayOfYear(phandle, playerUniqueAdress);
		playerDetail.contract.getStartYear = contract.getStartYear(phandle, playerUniqueAdress);
		playerDetail.contract.getEndDayOfYear = contract.getEndDayOfYear(phandle, playerUniqueAdress);
		playerDetail.contract.getEndYear = contract.getEndYear(phandle, playerUniqueAdress);
		playerDetail.contract.getJoinDayOfYear = contract.getJoinDayOfYear(phandle, playerUniqueAdress);
		playerDetail.contract.getJoinYear = contract.getJoinYear(phandle, playerUniqueAdress);
		playerDetail.contract.getLoyaltyBonus = contract.getLoyaltyBonus(phandle, playerUniqueAdress);
		playerDetail.contract.getSquadStatus = contract.getSquadStatus(phandle, playerUniqueAdress);
		playerDetail.contract.getSquadNumber = contract.getSquadNumber(phandle, playerUniqueAdress);

		return playerDetail;
	}

	static DWORD_PTR getBasePlayer(DWORD_PTR playerUniqueAdress) {
		return playerUniqueAdress - 0x1CC;
	}

	static int readIntPUA(HANDLE phandle, DWORD_PTR playerUniqueAdress, DWORD_PTR offset) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readInt(phandle, (pplayer + offset));
	}

	static uint8_t readBytePUA(HANDLE phandle, DWORD_PTR playerUniqueAdress, DWORD_PTR offset) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readByte(phandle, (pplayer + offset));
	}

	static short readShortPUA(HANDLE phandle, DWORD_PTR playerUniqueAdress, DWORD_PTR offset) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readShort(phandle, (pplayer + offset));
	}



	/**
		FullList staff + Player
		if (*(DWORD*)(dump + x) == 1177786120
		playerUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x -0x24 );

	*/
	
	// we don't need this,remove it
	void getPlayers(HANDLE pHandle) {
		//to write 
		int found = 0;
		SYSTEM_INFO sysInfo = { 0 };
		GetSystemInfo(&sysInfo);
		ofstream searchFile;
		searchFile.open("search_player_id.txt", std::ios_base::app);
		searchFile << " Unique ID  || " << "FULL NAME " << '\n';
		DWORD_PTR startAddress = (DWORD_PTR)sysInfo.lpMinimumApplicationAddress;
		DWORD_PTR endAddress = (DWORD_PTR)sysInfo.lpMaximumApplicationAddress;
		int value;
		DWORD_PTR unique_id;
		DWORD_PTR unique_id2;
		DWORD_PTR playerUIDaddress;
		while (startAddress < endAddress) {

			MEMORY_BASIC_INFORMATION mbi = { 0 };
			if (VirtualQueryEx(pHandle, (LPCVOID)startAddress, &mbi, sizeof(mbi)) != 0) { //if 1          
				if (mbi.State == MEM_COMMIT && ((mbi.Protect & PAGE_GUARD) == 0) && ((mbi.Protect & PAGE_NOACCESS) == 0)) {   //if 2       
					auto dump = new unsigned char[mbi.RegionSize + 1];
					memset(dump, 0x00, mbi.RegionSize + 1);


					ReadProcessMemory(pHandle, (LPCVOID*)mbi.BaseAddress, dump, mbi.RegionSize, NULL);

					for (auto x = 0; x < mbi.RegionSize - 4; x += 4) { // 4 bytes                   

						if (*(DWORD*)(dump + x) == player.information.guidingID)
						{
							playerUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x - 0x1C);

							ReadProcessMemory(pHandle, (LPCVOID*)playerUIDaddress, &unique_id, sizeof(DWORD_PTR), NULL);
							ReadProcessMemory(pHandle, (LPCVOID*)(playerUIDaddress + 0x4), &unique_id2, sizeof(DWORD_PTR), NULL);

							if ((int)unique_id == (int)unique_id2) {
								//CurrentMemory personalN = FindDmaAddy(pHandle, (playerUIDaddress + 0x4C), player.information.firstNameOffset, 2);
								//CurrentMemory personalL = FindDmaAddy(pHandle, (playerUIDaddress + 0x54), player.information.lastNameOffset, 2);

								searchFile << hex << (DWORD_PTR)mbi.BaseAddress + x;
								searchFile.unsetf(ios::hex);
								//searchFile << "  " << (int)unique_id << "  " << readBuffer(pHandle, personalN.currentAddress, 32) << " " << readBuffer(pHandle, personalL.currentAddress, 32) << '\n';;
								searchFile << "  " << (int)unique_id << "  " << this->getFullname(pHandle, playerUIDaddress) << '\n';;
							}

							/*
							found++;
							cout.unsetf(ios::hex);

							std::cout << found << std::endl;
							cout.setf(ios::hex, ios::basefield);

							std::cout << hex <<" " << (DWORD_PTR)mbi.BaseAddress + x <<std::endl;
							*/

						}
					}
					delete[] dump;

				}

				startAddress += mbi.RegionSize;

			}
		}
	}// while 

	auto getPlayerList(HANDLE pHandle) {

		map<int, DWORD_PTR> playersList;

		SYSTEM_INFO sysInfo = { 0 };
		GetSystemInfo(&sysInfo);


		DWORD_PTR startAddress = (DWORD_PTR)sysInfo.lpMinimumApplicationAddress;
		DWORD_PTR endAddress = (DWORD_PTR)sysInfo.lpMaximumApplicationAddress;


		DWORD_PTR unique_id;
		DWORD_PTR unique_id2;
		DWORD_PTR playerUIDaddress;
		while (startAddress < endAddress) {

			MEMORY_BASIC_INFORMATION mbi = { 0 };
			if (VirtualQueryEx(pHandle, (LPCVOID)startAddress, &mbi, sizeof(mbi)) != 0) { //if 1          
				if (mbi.State == MEM_COMMIT && ((mbi.Protect & PAGE_GUARD) == 0) && ((mbi.Protect & PAGE_NOACCESS) == 0)) {   //if 2       
					auto dump = new unsigned char[mbi.RegionSize + 1];
					memset(dump, 0x00, mbi.RegionSize + 1);

					ReadProcessMemory(pHandle, (LPCVOID*)mbi.BaseAddress, dump, mbi.RegionSize, NULL);

					for (auto x = 0; x < mbi.RegionSize - 4; x += 4) { // 4 bytes                   
						if (*(DWORD*)(dump + x) == player.information.guidingID)
						{
							playerUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x - 0x1C);

							ReadProcessMemory(pHandle, (LPCVOID*)playerUIDaddress, &unique_id, sizeof(DWORD_PTR), NULL);
							ReadProcessMemory(pHandle, (LPCVOID*)(playerUIDaddress + 0x4), &unique_id2, sizeof(DWORD_PTR), NULL);

							if ((int)unique_id == (int)unique_id2) {
								playersList.insert(std::pair<int, DWORD_PTR >((int)unique_id, playerUIDaddress));
							}

						}
					}
					delete[] dump;
				}
				startAddress += mbi.RegionSize;
			}
		}

		return playersList;
	}// while 



	PlayerDetail* getPlayersWithDetail(HANDLE pHandle) {
		map<int, DWORD_PTR> playersList = getPlayerList(pHandle);
		// Iterating the map and printing ordered values 
		DWORD_PTR playerPointerAddress;
		int playerUniqueID;
		PlayerDetail *pDetail;
		PlayerDetail player;
		int x = 0;
		for (auto i = playersList.begin(); i != playersList.end(); i++) {
			playerUniqueID = i->first;
			playerPointerAddress = playersList[playerUniqueID];

			pDetail[x] = getPlayerDetail(pHandle, playerUniqueID, playerPointerAddress);
			x++;
		}
		return pDetail;

	}

	void testPlayerList(HANDLE pHandle) {
		map<int, DWORD_PTR> playersList = getPlayerList(pHandle);
		// Iterating the map and printing ordered values 
		for (auto i = playersList.begin(); i != playersList.end(); i++) {
			std::cout << i->first << " : " << i->second << '\n';
		}
	}

	DWORD_PTR getPlayerBaseAddress(HANDLE pHandle, int PlayerID) {
		map<int, DWORD_PTR> playersList = getPlayerList(pHandle);
		return  playersList[PlayerID];
	}

	int getRowID(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readInt(phandle, (pplayer + 0x1C8));
	}

	int  getUniqeID(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readIntPUA(phandle, playerUniqueAdress, 0x1CC);
	}

	char* getFirstname(HANDLE phandle, DWORD_PTR playerUIDaddress) {
		CurrentMemory memory = FindDmaAddy(phandle, (playerUIDaddress + 0x4C), player.information.firstNameOffset, 2);
		return readBuffer(phandle, memory.currentAddress, 32);
	}

	char* getLastname(HANDLE phandle, DWORD_PTR playerUIDaddress) {
		CurrentMemory memory = FindDmaAddy(phandle, (playerUIDaddress + 0x54), player.information.lastNameOffset, 2);
		return readBuffer(phandle, memory.currentAddress, 32);

	}

	char* getFullname(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		DWORD_PTR offset[1] = { 0x4 };//+C    River

		CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x208), offset, 1);
		return readBuffer(phandle, memory.currentAddress, 32);
	}

	short getBirthYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readShortPUA(phandle, playerUniqueAdress, 0x206);
	}

	//mapEthnicity
	short getEthnicity(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x251);
	}

	short getHairColour(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x252);
	}

	//mapHairLength
	short getHairLength(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x253);
	}

	short getSkinTone(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x254);
	}

	short getHeight(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readShortPUA(phandle, playerUniqueAdress, 0x15E);
	}

	short getWeight(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readShortPUA(phandle, playerUniqueAdress, 0x15C);
	}

	short getMorale(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x1AB);
	}

	//mapDeclaredForNation
	short getDeclaredForNation(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x1A9);
	}

	short getInternationalApps(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x324);
	}

	short getInternationalGoals(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x326);
	}

	//mapGeneralOptions
	short getGeneralOptions(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0xFA);
	}

	short getBans(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0x18);
	}

	short getInjuries(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		return readBytePUA(phandle, playerUniqueAdress, 0xD8);
	}

	struct Attributes {

		struct Technical {
			short getCorners(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x18E);
			}

			short getCrossing(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x173);
			}

			short getDribbling(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x174);
			}

			short getFinishing(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x175);
			}

			short getFirstTouch(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x189);
			}

			short getFreeKickTaking(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x196);
			}

			short getHeading(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x176);
			}

			short getLongShots(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x177);
			}

			short getLongThrows(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x191);
			}

			short getMarking(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x178);
			}

			short getPassing(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x17A);
			}

			short getPenaltyTaking(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x17B);
			}

			short getTackling(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x17C);
			}

			short getTechnique(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x18A);
			}


		};

		struct Goalkeeping {
			short getAerialReach(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x17F);
			}

			short getCommandOfArea(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x180);
			}

			short getCommunication(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x181);
			}

			short getEccentricity(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x192);
			}

			short getHandling(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x17E);
			}
			short getKicking(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x182);
			}

			short getOneOnOnes(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x186);
			}

			short getReflexes(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x188);
			}

			short getRushingOut(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x193);
			}

			short getTendencyToPunch(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x194);
			}

			short getThrowing(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x183);
			}

		};

		struct Mental {

			short getAggression(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A0);
			}

			short getAnticipation(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x184);
			}

			short getBravery(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x19E);
			}

			short getComposure(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A7);
			}

			short getConcentration(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A8);
			}

			short getDecision(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x185);
			}

			short getDetermination(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A6);
			}

			short getFlair(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x18D);
			}

			short getLeadership(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x19B);
			}

			short getOffTheBall(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x179);
			}

			short getPositioning(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x187);
			}

			short getTeamwork(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x18F);
			}

			short getVision(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x17D);
			}

			short getWorkRate(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x190);
			}

		};

		struct Physical {

			short getAcceleration(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x195);
			}

			short getAgility(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A1);
			}

			short getBalance(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x19D);
			}

			short getJumpingReach(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x19A);
			}

			short getNaturalFitness(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A5);
			}

			short getPace(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x199);

			}

			short getStamina(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x198);
			}

			short getStrength(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x197);
			}

		};

		struct Hidden {
			short getDirtiness(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x19C);
			}
			short getConsistency(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x19F);
			}
			short getImpMatches(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A2);
			}
			short getInjuryProneness(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A3);
			}
			short getVersatility(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
				return readBytePUA(phandle, playerUniqueAdress, 0x1A4);
			}
		};

		Technical technical;
		Goalkeeping goalkeeping;
		Mental mental;
		Physical physical;
		Hidden hidden;

	};

	struct Positions {

		//mapRoleUsedToFillEmptyAttributes
		short getRoleUsedToFillEmptyAttributes(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x1B3);
		}

		//mapRoleUsedToFillEmptyAttributes
		short getPreferredCentralPosition(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x1B2);
		}

		short getGK(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x164);
		}

		short getSW(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x165);
		}

		short getDL(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x166);
		}

		short getDC(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x167);
		}
		short getDR(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x168);
		}
		short getWBL(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x171);
		}
		short getWBR(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x172);
		}
		short getDM(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x169);
		}
		short getML(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x16A);
		}
		short getMC(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x16B);
		}
		short getMR(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x16C);
		}
		short getAML(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x16D);
		}
		short getAMC(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x16E);
		}
		short getAMR(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x16F);
		}
		short getST(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x170);
		}
	};

	struct Abilities {
		short getCA(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readShortPUA(phandle, playerUniqueAdress, 0x158);
		}

		short getPA(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readShortPUA(phandle, playerUniqueAdress, 0x15A);
		}

		short getLeftFoot(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x18B);
		}

		short getRightFoot(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x18C);
		}

		short getMatchSharpness(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readShortPUA(phandle, playerUniqueAdress, 0x14C);
		}
		short getMatchExercise(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readShortPUA(phandle, playerUniqueAdress, 0x150);
		}
	};

	struct Personality {

		short getAdaptability(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x240);
		}

		short getAmbition(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x241);
		}

		short getControversy(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x247);
		}

		short getLoyalty(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x242);
		}

		short getPressure(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x243);
		}

		short getProfessionalism(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x244);
		}

		short getSportmanship(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x245);
		}

		short getTemperament(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readBytePUA(phandle, playerUniqueAdress, 0x246);
		}

	};

	struct Contract {

		int getClubUniqueID(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[2] = { 0x10,0xC };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 2);
			return memory.currentValue;
		}

		//mapType
		short getType(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x9A };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return (char)memory.currentValue;
		}

		//mapJobType
		short getJobType(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x1C };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return (char)memory.currentValue;
		}

		int getValue(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[2] = { 0x10,0xC };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x128), offset, 2);
			return memory.currentValue;
		}

		/*
		-1:Not Set
		mapAskingPrice
		*/
		int getAskingPrice(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			return readIntPUA(phandle, playerUniqueAdress, 0x12C);
		}

		int getWeeklyWage(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x18 };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return memory.currentValue;
		}

		short getStartDayOfYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x3C };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return (char)memory.currentValue;
		}

		short getStartYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x3E };
			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return memory.currentValue;
		}

		short getEndDayOfYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x40 };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return memory.currentValue;
		}

		short getEndYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x42 };
			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return memory.currentValue;
		}

		short getJoinDayOfYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x44 };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return (char)memory.currentValue;
		}

		short getJoinYear(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x46 };
			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return memory.currentValue;
		}

		int getLoyaltyBonus(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x90 };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return memory.currentValue;
		}

		//mapSquadStatus
		short getSquadStatus(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x4C };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return (char)memory.currentValue;
		}

		//-1:Not Set
		short getSquadNumber(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
			DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
			DWORD_PTR offset[1] = { 0x53 };

			CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x288), offset, 1);
			return (char)memory.currentValue;
		}
		/*
				  <Description>"Transfer Status"</Description>
				  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">4:Not Set
	5:Transfer Listed
	6:Listed for Loan
	7:Transfer and Load Listed
	12:Transfer Lister by Request
	15:Listed by Request &amp; Loan Listed
	68:Not Available for Loan
	69:Transfer Listed / NA for Loan
	76:Listed by Request / NA for Loan
	</DropDownList>
				  <VariableType>Byte</VariableType>
				  <Address>[pplayer_base]+288</Address>
				  <Offsets>
					<Offset>4E</Offset>
				  </Offsets>
				  <Description>"Clauses &amp; Bonuses -&gt;"</Description>
				  <Options moHideChildren="1"/>
				  <LastState Value="" RealAddress="00000000"/>
				  <Color>292CCC</Color>
				  <GroupHeader>1</GroupHeader>
				  <CheatEntries>
					<CheatEntry>
					  <ID>1026</ID>
					  <Description>"1 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1003</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="15" RealAddress="68B7A166"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>6</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1001</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="-1" RealAddress="68B7A160"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>0</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1004</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="25" RealAddress="68B7A164"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>4</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1027</ID>
					  <Description>"2 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1025</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="32" RealAddress="68B7A16E"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>E</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1023</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="2913" RealAddress="68B7A168"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>8</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1024</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="-1" RealAddress="68B7A16C"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>C</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1028</ID>
					  <Description>"3 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1022</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="33" RealAddress="68B7A176"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>16</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1020</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="1456" RealAddress="68B7A170"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>10</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1021</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="-1" RealAddress="68B7A174"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>14</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1029</ID>
					  <Description>"4 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1019</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="38" RealAddress="68B7A17E"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>1E</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1017</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="728" RealAddress="68B7A178"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>18</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1018</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="-1" RealAddress="68B7A17C"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>1C</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1030</ID>
					  <Description>"5 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1016</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A186"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>26</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1014</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="1757639504" RealAddress="68B7A180"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>20</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1015</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A184"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>24</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1031</ID>
					  <Description>"6 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1013</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A18E"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>2E</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1011</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="1757639520" RealAddress="68B7A188"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>28</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1012</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A18C"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>2C</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1032</ID>
					  <Description>"7 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1010</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A196"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>36</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1008</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="1757639520" RealAddress="68B7A190"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>30</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1009</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>"fm.exe"+17743D10</Address>
						  <Offsets>
							<Offset>34</Offset>
							<Offset>58</Offset>
							<Offset>288</Offset>
							<Offset>38</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
					<CheatEntry>
					  <ID>1033</ID>
					  <Description>"8 -&gt;"</Description>
					  <Options moHideChildren="1"/>
					  <LastState Value="" RealAddress="00000000"/>
					  <Color>16CC1C</Color>
					  <GroupHeader>1</GroupHeader>
					  <CheatEntries>
						<CheatEntry>
						  <ID>1007</ID>
						  <Description>"Type"</Description>
						  <DropDownList ReadOnly="1" DescriptionOnly="1" DisplayValueAsItem="1">0:Minimum Fee Release / None
	1:Relegation Release
	2:Non Promotion Release
	3:Yearly Wage Rise (%)
	4:Promotion Wage Rise
	5:Relegation Wage Drop
	6:Non-Playing Job Offer Release
	7:Sell On Fee (%)
	8:Sell On Fee (%)
	9:Sell On Fee Profit (%)
	10:Seasonal Landmark Goal Bonus
	11:One-Year Extension After League Games (Final Season)
	12:Match Highest Earner
	13:Wage After Reaching Club League Games
	14:Top Division Promotion Wage Rise
	15:Top Division Relegation Wage Drop
	16:Minimum Fee Release Clause (Foreign Clubs)
	17:Minimum Fee Release Clause (Domestic Clubs in Higher Division)
	18:Minimum Fee Release Clause (Domestic Clubs)
	19:Wage After Reaching International Appearances
	22:Optional Contract Extension By Club
	25:One-Year Extension After League Games (Promoted Final Season)
	26:One-Year Extension After League Games (Avoid Relegation Final Season)
	27:Minimum Fee Release Clause (Clubs in a Major Continental Competition)
	29:Contract Extension After Promotion
	30:Injury Release Clause
	31:Minimum Fee Release Clause (Clubs in a Continental Competition)
	32:Appearance Fee
	33:Goal Bonus
	34:Clean Sheet Bonus
	35:Team of the Year Bonus (Division)
	36:Top Goalscorer Bonus (Division)
	37:International Cap Bonus
	38:Unused Substitute Fee
	54:Will Leave At End Of Contract
	55:Active Relegation Release Clause
	56:Active Non Promotion Release Clause
	57:Committee Assigned Minimum Fee Release Clause
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A19E"/>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>3E</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1005</ID>
						  <Description>"Value"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A198"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>4 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>38</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
						<CheatEntry>
						  <ID>1006</ID>
						  <Description>"Info"</Description>
						  <DropDownList DescriptionOnly="1" DisplayValueAsItem="1">-1:N/A
	0:None
	</DropDownList>
						  <LastState Value="0" RealAddress="68B7A19C"/>
						  <ShowAsSigned>1</ShowAsSigned>
						  <VariableType>2 Bytes</VariableType>
						  <Address>[pplayer_base]+288</Address>
						  <Offsets>
							<Offset>3C</Offset>
							<Offset>58</Offset>
						  </Offsets>
						</CheatEntry>
					  </CheatEntries>
					</CheatEntry>
				  </CheatEntries>
				</CheatEntry>
			  </CheatEntries>
			</CheatEntry>
		*/
	};
	Attributes attributes;
	Positions positions;
	Abilities abilities;
	Personality personality;
	Contract contract;

};

#endif



