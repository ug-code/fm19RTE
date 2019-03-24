#ifndef SERVICECLUB_H
#define SERVICECLUB_H
#pragma once
#include <map>


class ServiceClub
{
	Club club;
	Stadium stadium;

public:


	static DWORD_PTR getBaseClub(DWORD_PTR club_base) {
		return club_base -0xC;
	}

	DWORD_PTR findClubUniqueAdress(HANDLE phandle, int clubId) {
		DWORD_PTR playerUniqueAdress = getClubBaseAddress(phandle, clubId);
		return playerUniqueAdress;
	}



	//get club list with uniqueId 4 byte
	void scanClubList(HANDLE pHandle) {
		DWORD_PTR address = 0;

		int value;
		std::ofstream searchFile;

		searchFile.open("search_team_id.txt", std::ios_base::app);
		searchFile << " Unique ID  || " <<"Nation ||"<< "Team Name || " << "League Name" << '\n';


		SYSTEM_INFO sysInfo = { 0 };
		GetSystemInfo(&sysInfo);


		DWORD_PTR startAddress = (DWORD_PTR)sysInfo.lpMinimumApplicationAddress;
		DWORD_PTR endAddress = (DWORD_PTR)sysInfo.lpMaximumApplicationAddress;


		DWORD_PTR unique_id;
		DWORD_PTR unique_id2;
		DWORD_PTR clubUIDaddress;
		while (startAddress < endAddress) {

			MEMORY_BASIC_INFORMATION mbi = { 0 };
			if (VirtualQueryEx(pHandle, (LPCVOID)startAddress, &mbi, sizeof(mbi)) != 0) { //if 1          
				if (mbi.State == MEM_COMMIT && ((mbi.Protect & PAGE_GUARD) == 0) && ((mbi.Protect & PAGE_NOACCESS) == 0)) {   //if 2       
					auto dump = new unsigned char[mbi.RegionSize + 1];
					memset(dump, 0x00, mbi.RegionSize + 1);

					ReadProcessMemory(pHandle, (LPCVOID*)mbi.BaseAddress, dump, mbi.RegionSize, NULL);

					for (auto x = 0; x < mbi.RegionSize - 4; x += 4) { // 4 bytes                   
						if (*(DWORD*)(dump + x) == club.information.guidingID)
						{

							clubUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x - 0xB4);

							ReadProcessMemory(pHandle, (LPCVOID*)clubUIDaddress, &unique_id, sizeof(DWORD_PTR), NULL);
							ReadProcessMemory(pHandle, (LPCVOID*)(clubUIDaddress + 0x4), &unique_id2, sizeof(DWORD_PTR), NULL);

							if ((int)unique_id == (int)unique_id2) {
								CurrentMemory shortName = FindDmaAddy(pHandle, (clubUIDaddress + 0xC), club.information.shortNameOffset, 2);
								CurrentMemory fullName = FindDmaAddy(pHandle, (clubUIDaddress + 0xC), club.information.fullNameOffset, 2);


								//CurrentMemory nation = FindDmaAddy(pHandle, (clubUIDaddress + 0xFFC), club.information.nationOffset, 2);
								CurrentMemory divisionStatus = FindDmaAddy(pHandle, (clubUIDaddress + 0x54), club.information.divisionStatusOffset, 2);

								CurrentMemory leagueName = FindDmaAddy(pHandle, (clubUIDaddress + 0x44), club.information.leagueNameOffset, 2);
								CurrentMemory stadiumID = FindDmaAddy(pHandle, (clubUIDaddress + 0xC), club.information.stadiumIDOffset, 3);


								// searchFile.setf(ios::hex, ios::basefield);
								//searchFile << uppercase<< clubUIDaddress << " || ";

								//searchFile.unsetf(ios::hex);
								searchFile << (int)unique_id << " ## "
									<< stadiumID.currentValue << " ## "
									<< readBuffer(pHandle, shortName.currentAddress, 32) << " ## "
									<< readBuffer(pHandle, fullName.currentAddress, 32) << " ## "
									//<< readBuffer(pHandle, divisionStatus.currentAddress, 45)
									<< '\n';
							}

						}
					}
					delete[] dump;
				}
				startAddress += mbi.RegionSize;
			}
		}


	}


	auto getClubList(HANDLE pHandle) {

		map<int, DWORD_PTR> clubList;

		SYSTEM_INFO sysInfo = { 0 };
		GetSystemInfo(&sysInfo);


		DWORD_PTR startAddress = (DWORD_PTR)sysInfo.lpMinimumApplicationAddress;
		DWORD_PTR endAddress = (DWORD_PTR)sysInfo.lpMaximumApplicationAddress;


		DWORD_PTR unique_id;
		DWORD_PTR unique_id2;
		DWORD_PTR clubUIDaddress;
		while (startAddress < endAddress) {

			MEMORY_BASIC_INFORMATION mbi = { 0 };
			if (VirtualQueryEx(pHandle, (LPCVOID)startAddress, &mbi, sizeof(mbi)) != 0) { //if 1          
				if (mbi.State == MEM_COMMIT && ((mbi.Protect & PAGE_GUARD) == 0) && ((mbi.Protect & PAGE_NOACCESS) == 0)) {   //if 2       
					auto dump = new unsigned char[mbi.RegionSize + 1];
					memset(dump, 0x00, mbi.RegionSize + 1);

					ReadProcessMemory(pHandle, (LPCVOID*)mbi.BaseAddress, dump, mbi.RegionSize, NULL);

					for (auto x = 0; x < mbi.RegionSize - 4; x += 4) { // 4 bytes                   
						if (*(DWORD*)(dump + x) == club.information.guidingID)
						{

							clubUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x +0xC);

							ReadProcessMemory(pHandle, (LPCVOID*)clubUIDaddress, &unique_id, sizeof(DWORD_PTR), NULL);
							ReadProcessMemory(pHandle, (LPCVOID*)(clubUIDaddress + 0x4), &unique_id2, sizeof(DWORD_PTR), NULL);

							if ((int)unique_id == (int)unique_id2) {
								clubList.insert(std::pair<int, DWORD_PTR >((int)unique_id, clubUIDaddress));
							}

						}
					}
					delete[] dump;
				}
				startAddress += mbi.RegionSize;
			}
		}

		return clubList;
	}

	DWORD_PTR getClubBaseAddress(HANDLE pHandle, int clubId) {
		map<int, DWORD_PTR> clubList = getClubList(pHandle);
		return  clubList[clubId];
	}


	void testClubList(HANDLE pHandle) {
		map<int, DWORD_PTR> playersList = getClubList(pHandle);
		std::cout << playersList.size() << '\n';
		/*
		// Iterating the map and printing ordered values 
		for (auto i = playersList.begin(); i != playersList.end(); i++) {
			std::cout << i->first << " : " << i->second << '\n';
		}
		*/
	}

	int getRowID(HANDLE phandle, DWORD_PTR club_base) {
		DWORD_PTR pplayer = getBaseClub(club_base);
		return readInt(phandle, (pplayer + 0x8));
	}

	int getUniqeID(HANDLE phandle, DWORD_PTR club_base) {
		DWORD_PTR pplayer = getBaseClub(club_base);
		return readInt(phandle, (pplayer + 0xC));
	}

	char* getFullname(HANDLE phandle, DWORD_PTR club_base) {
		DWORD_PTR pplayer = getBaseClub(club_base);
		DWORD_PTR offset[1] = { 0x4 };//+C    River

		CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0xB8), offset, 1);
		return readBuffer(phandle, memory.currentAddress, 64);
	}




	int getStadiumLongitude(HANDLE pHandle, DWORD_PTR stadiumUIDaddress) {
		int ptemp = 0;
		ReadProcessMemory(pHandle, (void*)(stadiumUIDaddress+stadium.longitudeOffset), &ptemp, sizeof(ptemp), 0);
		return ptemp;
	}

	int getStadiumLatitude(HANDLE pHandle, DWORD_PTR stadiumUIDaddress) {
		int ptemp = 0;
		ReadProcessMemory(pHandle, (void*)(stadiumUIDaddress + stadium.latitudeOffset), &ptemp, sizeof(ptemp), 0);
		return ptemp;
	}	
	
	int getStadiumSeatingCapaity(HANDLE pHandle, DWORD_PTR stadiumUIDaddress) {
		int ptemp = 0;
		ReadProcessMemory(pHandle, (void*)(stadiumUIDaddress + stadium.seatingCapaityOffset), &ptemp, sizeof(ptemp), 0);
		return ptemp;
	}

	int getStadiumExpansionCapaity(HANDLE pHandle, DWORD_PTR stadiumUIDaddress) {
		int ptemp = 0;
		ReadProcessMemory(pHandle, (void*)(stadiumUIDaddress + stadium.expansionCapaityOffset), &ptemp, sizeof(ptemp), 0);
		return ptemp;
	}
	int getStadiumUsedCapaity(HANDLE pHandle, DWORD_PTR stadiumUIDaddress) {
		int ptemp = 0;
		ReadProcessMemory(pHandle, (void*)(stadiumUIDaddress + stadium.usedCapaityOffset), &ptemp, sizeof(ptemp), 0);
		return ptemp;
	}
};



#endif



