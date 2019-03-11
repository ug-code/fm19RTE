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
	char* getFullname;
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
};

class ServicePlayer
{
	Player player;

public:

	//get player list with uniqueId 4 byte
	void scanPlayerList(HANDLE pHandle) {

		//DWORD_PTR startAddress = 0x430B6600;
		//DWORD_PTR finalAddress = 0x472FED20;
		UINT startAddress = 0x1FFFFF;
		UINT finalAddress = 0x7fffffffffffffff;

		DWORD_PTR address = 0;
		int value;
		DWORD_PTR unique_id;
		DWORD_PTR playerUIDaddress;

		ofstream searchFile;
		searchFile.open("search_player_id.txt", std::ios_base::app);
		searchFile << " Unique ID  || " << "FULL NAME " << '\n';


		for (address = startAddress; address <= finalAddress; address += sizeof(value)) {
			ReadProcessMemory(pHandle, (void*)address, &value, sizeof(value), 0);
			if (value == player.information.guidingID) {
				playerUIDaddress = (address - 0x1C);
				ReadProcessMemory(pHandle, (LPCVOID*)playerUIDaddress, &unique_id, sizeof(DWORD_PTR), NULL);
				CurrentMemory personalN = FindDmaAddy(pHandle, (playerUIDaddress + 0x4C), player.information.firstNameOffset, 2);
				CurrentMemory personalL = FindDmaAddy(pHandle, (playerUIDaddress + 0x54), player.information.lastNameOffset, 2);

				searchFile << personalN.currentAddress << "  " << (int)unique_id << "  " << readBuffer(pHandle, personalN.currentAddress, 32) << " " << readBuffer(pHandle, personalL.currentAddress, 32) << '\n';;

			}
		}


	}

	/**
		FullList staff + Player
		if (*(DWORD*)(dump + x) == 1177786120
		playerUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x -0x24 );

	*/

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


	auto getPlayeList(HANDLE pHandle) {

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


	void testPlayerList(HANDLE pHandle) {
		map<int, DWORD_PTR> playersList = getPlayeList(pHandle);
		// Iterating the map and printing ordered values 
		for (auto i = playersList.begin(); i != playersList.end(); i++) {
			std::cout << i->first << " : " << i->second << '\n';
		}
	}

	DWORD_PTR getPlayerBaseAddress(HANDLE pHandle, int PlayerID) {
		map<int, DWORD_PTR> playersList = getPlayeList(pHandle);
		return  playersList[PlayerID];
	}

	DWORD_PTR getBasePlayer(DWORD_PTR playerUniqueAdress) {
		return playerUniqueAdress - 0x1CC;
	}

	int getRowID(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readInt(phandle, (pplayer + 0x1C8));
	}

	int  getUniqeID(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readInt(phandle, (pplayer + 0x1CC));
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
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readShort(phandle, (pplayer + 0x206));
	}


	/*
	-1:Unknown
	0:Northern European
	1:Mediterranean / Hispanic
	2:North African / Middle Eastern
	3:African / Caribbean
	4:Asian
	5:South East Asian
	6:Pacific Islander
	7:Native American
	8:Native Australian
	9:Mixed Race (Black / White)
	10:East Asian
	*/
	short getEthnicity(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);

		return (char)readShort(phandle, (pplayer + 0x251));

	}

	/*
	0:Unknown
	1:Blonde
	2:Light Brown
	3:Dark Brown
	4:Red
	5:Black
	6:Grey
	8:Changeable (Normal)
	9:Changeable (Dramatic)
	*/
	short getHairColour(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);

		return (char)readShort(phandle, (pplayer + 0x252));

	}

	/*
	4:Unknown
	0:Bald
	1:Short
	2:Medium
	3:Long
	*/
	short getHairLength(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);

		return (char)readShort(phandle, (pplayer + 0x253));

	}

	/*
	-1:Unknown
	0:Skin Tone 1
	1:Skin Tone 2
	2:Skin Tone 3
	3:Skin Tone 4
	4:Skin Tone 5
	5:Skin Tone 6
	6:Skin Tone 7
	7:Skin Tone 8
	8:Skin Tone 9
	9:Skin Tone 10
	10:Skin Tone 11
	11:Skin Tone 12
	12:Skin Tone 13
	13:Skin Tone 14
	14:Skin Tone 15
	15:Skin Tone 16
	16:Skin Tone 17
	17:Skin Tone 18
	18:Skin Tone 19
	19:Skin Tone 20
	*/
	short getSkinTone(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);

		return (char)readShort(phandle, (pplayer + 0x254));

	}

	short getHeight(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readShort(phandle, (pplayer + 0x15E));
	}

	short getWeight(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return readShort(phandle, (pplayer + 0x15C));
	}

	short getMorale(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0x1AB));
	}

	/*
	0:No
	1:Yes
	*/
	short getDeclaredForNation(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0x1A9));
	}

	short getInternationalApps(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0x324));
	}

	short getInternationalGoals(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0x326));
	}
	/*
	0:None
	2:Has No Work Permit
	8:Treated As Non-EU In Italy
	10:Has No Work Permit / Treated As Non-EU In Italy
	*/
	short getGeneralOptions(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0xFA));
	}

	short getBans(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0x18));
	}

	short getInjuries(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		return (char)readShort(phandle, (pplayer + 0xD8));
	}


	PlayerDetail getPlayerDetail(HANDLE phandle, int PlayerID) {
		PlayerDetail playerDetail;
		DWORD_PTR playerUniqueAdress = getPlayerBaseAddress(phandle, PlayerID);
		playerDetail.getRowID				= getRowID(phandle, playerUniqueAdress);
		playerDetail.getUniqeID				= PlayerID;
		playerDetail.getFirstname			= getFirstname(phandle, playerUniqueAdress);
		playerDetail.getLastname			= getLastname(phandle, playerUniqueAdress);
		playerDetail.getFullname			= getFullname(phandle, playerUniqueAdress);
		playerDetail.getBirthYear			= getBirthYear(phandle, playerUniqueAdress);
		playerDetail.getEthnicity			= getEthnicity(phandle, playerUniqueAdress);
		playerDetail.getHairColour			= getHairColour(phandle, playerUniqueAdress);
		playerDetail.getHairLength			= getHairLength(phandle, playerUniqueAdress);
		playerDetail.getSkinTone			= getSkinTone(phandle, playerUniqueAdress);
		playerDetail.getHeight				= getHeight(phandle, playerUniqueAdress);
		playerDetail.getWeight				= getWeight(phandle, playerUniqueAdress);
		playerDetail.getMorale				= getMorale(phandle, playerUniqueAdress);
		playerDetail.getDeclaredForNation	= getDeclaredForNation(phandle, playerUniqueAdress);
		playerDetail.getInternationalApps	= getInternationalApps(phandle, playerUniqueAdress);
		playerDetail.getInternationalGoals	= getInternationalGoals(phandle, playerUniqueAdress);
		playerDetail.getGeneralOptions		= getGeneralOptions(phandle, playerUniqueAdress);
		playerDetail.getBans				= getBans(phandle, playerUniqueAdress);
		playerDetail.getInjuries			= getInjuries(phandle, playerUniqueAdress);
		return playerDetail;
	}
};





#endif



