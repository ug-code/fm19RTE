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

	short getYearfounded(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.yearFoundedAddr, currentClub.information.yearFoundedOffset, 3);
		return  memory.currentValue;
	}

	//byte
	short getTeamtype(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.teamTypeAddr, currentClub.information.teamTypeOffset, 1);
		return (char)memory.currentValue;
	}

	short getReputation(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.reputationAddr, currentClub.information.reputationOffset, 1);
		return  memory.currentValue;
	}

	char* getNation(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.nationAddr, currentClub.information.nationOffset, 1);
		return readBuffer(phandle, memory.currentAddress, 32);
	}

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

	short getAverageattendance(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.averageAttendanceAddr, currentClub.information.averageAttendanceOffset, 3);
		return memory.currentValue;
	}

	int getMinimumattendance(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.minimumAttendanceAddr, currentClub.information.minimumAttendanceOffset, 3);
		return memory.currentValue;
	}

	int getMaximumattendance(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.maximumAttendanceAddr, currentClub.information.maximumAttendanceOffset, 3);
		return memory.currentValue;
	}

	short getCompetition(HANDLE phandle) {
		CurrentMemory memory = FindDmaAddy(phandle, currentClub.information.competitionAddr, currentClub.information.competitionOffset, 3);
		short repulationValue = memory.currentValue;
		return repulationValue;
	}

	struct Finances
	{
		CurrentClub currentClub;
	};
	Finances finances;


	int setClubMoney(HANDLE phandle, double &newMoney) {
		int isWriteProcess = WritePointer(phandle, currentClub.finances.balanceAddr, newMoney, currentClub.finances.balanceOffset, 3);
		if (!isWriteProcess) {
			std::cerr << "Couldn't write process memory:" << GetLastError() << std::endl;
			getchar();
		}
		return  isWriteProcess;
	}


};



#endif



