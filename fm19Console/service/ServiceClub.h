#ifndef SERVICECLUB_H
#define SERVICECLUB_H
#pragma once


class ServiceClub
{
	CurrentClub currentClub;

public:
	char* getClubFullname(HANDLE phandle) {
		CurrentMemory clubFullname = FindDmaAddy(phandle, currentClub.information.fullNameAddr, currentClub.information.fullNameOffset, 5);
		return readBuffer(phandle, clubFullname.currentAddress, 32);
	}

	short getClubReputation(HANDLE phandle) {
		CurrentMemory clubReputation = FindDmaAddy(phandle, currentClub.information.reputationAddr, currentClub.information.reputationOffset, 1);
		short repulationValue = clubReputation.currentValue;		
		return repulationValue;
	}

	char* getClubCompetition(HANDLE phandle) {
		CurrentMemory clubCompetition = FindDmaAddy(phandle, currentClub.information.competitionAddr, currentClub.information.competitionOffset, 3);
		return readBuffer(phandle, clubCompetition.currentAddress, 32);
	}
	char* getClubNation(HANDLE phandle) {
		CurrentMemory clubNation = FindDmaAddy(phandle, currentClub.information.nationAddr, currentClub.information.nationOffset, 4);
		return readBuffer(phandle, clubNation.currentAddress, 32);
	}

	double getClubMoney(HANDLE phandle) {
		CurrentMemory currentMoney = FindDmaAddy(phandle, currentClub.finances.moneyAddr, currentClub.finances.moneyOffsets, 5);
		return currentMoney.currentValue;
	}

	int setClubMoney(HANDLE phandle, double &newMoney) {
		int isWriteProcess = WritePointer(phandle, currentClub.finances.moneyAddr, newMoney, currentClub.finances.moneyOffsets, 5);
		if (!isWriteProcess) {
			std::cerr << "Couldn't write process memory:" << GetLastError() << std::endl;
			getchar();
		}
		return  isWriteProcess;
	}

	//get club list with uniqueId 4 byte
	void scanClubList(HANDLE pHandle, int value) {
		DWORD_PTR startAddress = 0x3CA0AFF8;
		DWORD_PTR finalAddress = 0x3E0B4E28;
		DWORD_PTR address = 0;
		int valor;
		int unique_id;
		std::ofstream searchFile;
		searchFile.open("search_team_id.txt", std::ios_base::app);
		for (address = startAddress; address <= finalAddress; address += sizeof(valor)) {
			ReadProcessMemory(pHandle, (void*)address, &valor, sizeof(valor), 0);
			if (valor == value) {
				ReadProcessMemory(pHandle, (void*)(address - 0xB4), &unique_id, sizeof(valor), 0);
				searchFile << unique_id << '\n';;

			}
		}

	}

	//get player list with uniqueId 4 byte
	void scanPlayerList(HANDLE pHandle, int value) {
		DWORD_PTR startAddress = 0x430B6600;
		DWORD_PTR finalAddress = 0x472FED20;
		DWORD_PTR address = 0;
		DWORD_PTR firstNameOffset[2] = { 0x0,0x4 };
		int valor;
		DWORD_PTR unique_id;
		char* first_name = new char[32];
		std::ofstream searchFile;
		searchFile.open("search_player_id.txt", std::ios_base::app);
		searchFile << " Unique ID  || " << "FULL NAME " << '\n';
		for (address = startAddress; address <= finalAddress; address += sizeof(valor)) {
			ReadProcessMemory(pHandle, (void*)address, &valor, sizeof(valor), 0);
			if (valor == value) {
				ReadProcessMemory(pHandle, (LPCVOID*)(address - 0x1C), &unique_id, sizeof(DWORD_PTR), NULL);
				CurrentMemory personalN = FindDmaAddy(pHandle, ((address - 0x1C) + 0x4C), firstNameOffset, 2);
				CurrentMemory personalL = FindDmaAddy(pHandle, ((address - 0x1C) + 0x54), firstNameOffset, 2);

				searchFile << (int)unique_id << "  " << readBuffer(pHandle, personalN.currentAddress, 32) << " " << readBuffer(pHandle, personalL.currentAddress, 32) << '\n';;

			}
		}
	}

};



#endif



