#ifndef SERVICECURRENTCLUB_H
#define SERVICECURRENTCLUB_H
#pragma once


class ServiceCurrentClub
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


};



#endif



