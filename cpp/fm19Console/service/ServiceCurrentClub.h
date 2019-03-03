#ifndef SERVICECURRENTCLUB_H
#define SERVICECURRENTCLUB_H
#pragma once


class ServiceCurrentClub
{
	CurrentClub currentClub;

public:

	int getRowid(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.rowIdAddr, currentClub.information.rowIdOffset, 3);
		return memory.currentValue;
	}

	int getUniqeid(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.uniqeIdAddr, currentClub.information.uniqeIddOffset, 2);
		return memory.currentValue;
	}

	char* getFullname(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.fullNameAddr, currentClub.information.fullNameOffset, 5);
		return readBuffer(phandle, memory.currentAddress, 32);
	}

	char* getNickname(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.nicknameAddr, currentClub.information.nicknameOffset, 4);
		return readBuffer(phandle, memory.currentAddress, 32);
	}

	short getYearfounded(HANDLE phandle) {}

	//byte
	short getTeamtype(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.teamTypeAddr, currentClub.information.teamTypeOffset, 1);
		return (char)memory.currentValue;
	}

	short getReputation(HANDLE phandle) {}

	char* getNation(HANDLE phandle) {}

	//byte
	short getStatus(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.statusAddr, currentClub.information.statusOffset, 2);
		return (char)memory.currentValue;
	}

	//byte
	short  getOwnershiptype(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.ownershipTypeAddr, currentClub.information.ownershipTypeOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getChairmantitle(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.chairmanTitleAddr, currentClub.information.chairmanTitleOffset, 3);
		return (char)memory.currentValue;
	}

	short getChairmanstatus(HANDLE phandle) {}

	//byte
	short getTrainingfacilities(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.trainingFacilitiesAddr, currentClub.information.trainingFacilitiesOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getYouthfacilities(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.youthFacilitiesAddr, currentClub.information.youthFacilitiesOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getYouthimportance(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.youthImportanceAddr, currentClub.information.youthImportanceOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getYouthrecruitment(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.youthRecruitmentAddr, currentClub.information.youthRecruitmentOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getJuniorcoaching(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.juniorCoachingAddr, currentClub.information.juniorCoachingOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getCorporatefacilities(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.corporateFacilitiesAddr, currentClub.information.corporateFacilitiesOffset, 3);
		return (char)memory.currentValue;
	}

	//byte
	short getMorale(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.moraleAddr, currentClub.information.moraleOffset, 3);
		return (char)memory.currentValue;
	}

	short getAverageattendance(HANDLE phandle) {}

	int getMinimumattendance(HANDLE phandle) {}

	int getMaximumattendance(HANDLE phandle) {}

	short getCompetition(HANDLE phandle) {}






	/* */
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



