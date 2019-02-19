#ifndef SERVICECLUB_H
#define SERVICECLUB_H
#pragma once


class ServiceClub
{
	Club club;

public:


	//get club list with uniqueId 4 byte
	void scanClubList(HANDLE pHandle) {
		DWORD_PTR startAddress = 0x3CA0AFF8;
		DWORD_PTR finalAddress = 0x3F0B4E28;
		DWORD_PTR address = 0;
		DWORD_PTR clubUIDaddress;

		int value;
		int unique_id;
		std::ofstream searchFile;

		searchFile.open("search_team_id.txt", std::ios_base::app);
		searchFile << " Unique ID  || " << "Team Name || " << "League Name" << '\n';
		for (address = startAddress; address <= finalAddress; address += sizeof(value)) {
			ReadProcessMemory(pHandle, (void*)address, &value, sizeof(value), 0);
			if (value == club.information.guidingID) {
				clubUIDaddress = (address - 0xB4);
				ReadProcessMemory(pHandle, (void*)clubUIDaddress, &unique_id, sizeof(value), 0);

				CurrentMemory clubName = FindDmaAddy(pHandle, (clubUIDaddress + 0xCC), club.information.clubNameOffset, 2);
				CurrentMemory leagueName = FindDmaAddy(pHandle, (clubUIDaddress + 0x44), club.information.leagueNameOffset, 2);

				searchFile << (int)unique_id << "  " <<
					readBuffer(pHandle, clubName.currentAddress, 32) << " " <<
					readBuffer(pHandle, leagueName.currentAddress, 32) << '\n';;


			}
		}

	}


};



#endif



