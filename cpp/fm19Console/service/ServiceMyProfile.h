#ifndef SERVICEMYPROFILE_H
#define SERVICEMYPROFILE_H
#pragma once


class ServiceMyProfile
{

public:
	MyProfile myProfile;

	int  getRowId(HANDLE phandle) {
		CurrentMemory rowId = FindDmaAddy(phandle, myProfile.information.rowIdAddr, myProfile.information.rowIdOffset, 4);
		return rowId.currentValue;
	}

	int  getUniqeId(HANDLE phandle) {
		CurrentMemory uniqeId = FindDmaAddy(phandle, myProfile.information.uniqeIdAddr, myProfile.information.uniqeIddOffset, 4);
		return uniqeId.currentValue;
	}

	short getCoachingLicense(HANDLE phandle) {
		CurrentMemory coachingLicense = FindDmaAddy(phandle, myProfile.information.coachingLicenseAddr, myProfile.information.coachingLicenseOffset, 4);
		return (char)coachingLicense.currentValue;
	}

	struct Characteristic {
		MyProfile myProfile;

		int getRowId(HANDLE phandle) {
			CurrentMemory rowId = FindDmaAddy(phandle, myProfile.information.characteristic.rowIdAddr, myProfile.information.characteristic.rowIdOffset, 4);
			return rowId.currentValue;
		}

		short getHandsOnApproach(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.handsOnApproachAddr, myProfile.information.characteristic.handsOnApproachOffset, 2);
			return (char)memory.currentValue;
		}

		short getDomesticPlayerBias(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.domesticPlayerBiasAddr, myProfile.information.characteristic.domesticPlayerBiasOffset, 2);
			return (char)memory.currentValue;
		}

		short getTacticalConsistency(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.tacticalConsistencyAddr, myProfile.information.characteristic.tacticalConsistencyOffset, 2);
			return (char)memory.currentValue;
		}

		short getClubPlayerLoyalty(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.clubPlayerLoyaltyAddr, myProfile.information.characteristic.clubPlayerLoyaltyOffset, 2);
			return (char)memory.currentValue;
		}

		short getSquadDiscipline(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.squadDisciplineAddr, myProfile.information.characteristic.squadDisciplineOffset, 2);
			return (char)memory.currentValue;
		}

		short getFinancialControl(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.financialControlAddr, myProfile.information.characteristic.financialControlOffset, 2);
			return (char)memory.currentValue;
		}

		int getMediaHandling(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.characteristic.mediaHandlingAddr, myProfile.information.characteristic.mediaHandlingOffset, 2);
			return(char)memory.currentValue;
		}

	};
	Characteristic characteristic;

	struct Reputation
	{
		MyProfile myProfile;

		short getHomeRep(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.reputation.homeRepAddr, myProfile.information.reputation.homeRepOffset, 2);
			return memory.currentValue;
		}

		short getCurrentRep(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.reputation.currentRepAddr, myProfile.information.reputation.currentRepOffset, 2);
			return memory.currentValue;
		}
		short getWorldRep(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.reputation.worldRepAddr, myProfile.information.reputation.worldRepOffset, 2);
			return memory.currentValue;
		}
	};
	Reputation reputation;

	struct Contract
	{
		MyProfile myProfile;

		short getType(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.contract.typeAddr, myProfile.information.contract.typeOffset, 3);
			return (char)memory.currentValue;
		}

		short getJobType(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.contract.jobTypeAddr, myProfile.information.contract.jobTypeOffset, 3);
			return (char)memory.currentValue;
		}

		int getWeeklyWage(HANDLE phandle) {
			CurrentMemory memory = FindDmaAddy(phandle, myProfile.information.contract.weeklyWageAddr, myProfile.information.contract.weeklyWageOffset, 3);
			return memory.currentValue;
		}
	};
	Contract contract;
};


#endif



