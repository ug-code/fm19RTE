#ifndef SERVICEPLAYER_H
#define SERVICEPLAYER_H
#pragma once

class ServicePlayer
{
	Player player;

public:


	//get player list with uniqueId 4 byte
	void scanPlayerList(HANDLE pHandle) {
		DWORD_PTR startAddress = 0x430B6600;
		DWORD_PTR finalAddress = 0x472FED20;
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

				searchFile << (int)unique_id << "  " << readBuffer(pHandle, personalN.currentAddress, 32) << " " << readBuffer(pHandle, personalL.currentAddress, 32) << '\n';;

			}
		}


	}

};



#endif



