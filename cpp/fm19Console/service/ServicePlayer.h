#ifndef SERVICEPLAYER_H
#define SERVICEPLAYER_H
#pragma once

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

	void findPlayer(HANDLE pHandle) {
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
								playerUIDaddress = ((DWORD_PTR)mbi.BaseAddress + x -0x1C);

								ReadProcessMemory(pHandle, (LPCVOID*)playerUIDaddress, &unique_id, sizeof(DWORD_PTR), NULL);
								ReadProcessMemory(pHandle, (LPCVOID*)(playerUIDaddress+0x4), &unique_id2, sizeof(DWORD_PTR), NULL);

								if ((int)unique_id == (int)unique_id2) {
									//CurrentMemory personalN = FindDmaAddy(pHandle, (playerUIDaddress + 0x4C), player.information.firstNameOffset, 2);
									//CurrentMemory personalL = FindDmaAddy(pHandle, (playerUIDaddress + 0x54), player.information.lastNameOffset, 2);

									searchFile << hex << (DWORD_PTR)mbi.BaseAddress + x;
									searchFile.unsetf(ios::hex);
									//searchFile << "  " << (int)unique_id << "  " << readBuffer(pHandle, personalN.currentAddress, 32) << " " << readBuffer(pHandle, personalL.currentAddress, 32) << '\n';;
									searchFile << "  " << (int)unique_id << "  " << this->fullname(pHandle, playerUIDaddress) << '\n';;
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

	DWORD_PTR getBasePlayer(DWORD_PTR playerUniqueAdress) {
		return playerUniqueAdress - 0x1CC;
	}

	char* fullname(HANDLE phandle, DWORD_PTR playerUniqueAdress) {
		DWORD_PTR pplayer = getBasePlayer(playerUniqueAdress);
		DWORD_PTR offset[1] = { 0x4 };//+C    River

		CurrentMemory memory = FindDmaAddy(phandle, (pplayer + 0x208), offset, 1);
		return readBuffer(phandle, memory.currentAddress, 32);
	}

};





#endif



