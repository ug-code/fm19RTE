#ifndef SERVICECLUB_H
#define SERVICECLUB_H
#pragma once


class ServiceClub
{
	Club club;
	Stadium stadium;

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
		searchFile << " Unique ID  || " <<"Nation ||"<< "Team Name || " << "League Name" << '\n';
		for (address = startAddress; address <= finalAddress; address += sizeof(value)) {
			ReadProcessMemory(pHandle, (void*)address, &value, sizeof(value), 0);
			if (value == club.information.guidingID) {
				clubUIDaddress = (address - 0xB4);
				ReadProcessMemory(pHandle, (void*)clubUIDaddress, &unique_id, sizeof(value), 0);
				if ((int)unique_id==0) {
					continue;
				}
				CurrentMemory shortName = FindDmaAddy(pHandle, (clubUIDaddress + 0xC), club.information.shortNameOffset, 2);
				CurrentMemory fullName= FindDmaAddy(pHandle, (clubUIDaddress + 0xC), club.information.fullNameOffset, 2);


				//CurrentMemory nation = FindDmaAddy(pHandle, (clubUIDaddress + 0xFFC), club.information.nationOffset, 2);
				CurrentMemory divisionStatus = FindDmaAddy(pHandle, (clubUIDaddress + 0x54), club.information.divisionStatusOffset, 2);

				CurrentMemory leagueName = FindDmaAddy(pHandle, (clubUIDaddress + 0x44), club.information.leagueNameOffset, 2);
				CurrentMemory stadiumID = FindDmaAddy(pHandle, (clubUIDaddress + 0xC), club.information.stadiumIDOffset, 3);


				// searchFile.setf(ios::hex, ios::basefield);
				 //searchFile << uppercase<< clubUIDaddress << " || ";

				 //searchFile.unsetf(ios::hex);
				searchFile << (int)unique_id << " ## " 
					<< stadiumID.currentValue << " ## "
					<< readBuffer(pHandle, shortName.currentAddress, 32) <<" ## "
					<< readBuffer(pHandle, fullName.currentAddress, 32) << " ## "
					<<readBuffer(pHandle, divisionStatus.currentAddress, 45)
					<< '\n';

			


			}
		}

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



