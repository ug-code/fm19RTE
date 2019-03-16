#ifndef SERVICEPLAYERMAPS_H
#define SERVICEPLAYERMAPS_H
#pragma once
#include <map>


const static std::map<int, std::string> mapEthnicity = {
	{ -1, "Unknown" },
	{ 0,"Northern European" },
	{ 1,"Mediterranean / Hispanic" },
	{ 2,"North African / Middle Eastern" },
	{ 3,"African / Caribbean" },
	{ 4,"Asian" },
	{ 5,"South East Asian" },
	{ 6,"Pacific Islander" },
	{ 7 ,"Native American" },
	{ 8 ,"Native Australian" },
	{ 9,"Mixed Race(Black / White)" },
	{ 10 , "East Asian" }
};


const static std::map<int, std::string> mapHairColour = {
	{ 0,"Unknown" },
	{ 1,"Blonde" },
	{ 2,"Light Brown" },
	{ 3,"Dark Brown" },
	{ 4,"Red" },
	{ 5,"Black" },
	{ 6,"Grey" },
	{ 8,"Changeable (Normal)" },
	{ 9,"Changeable (Dramatic)" }
};

const static std::map<int, std::string> mapHairLength = {
	{ 0,"Bald" },
	{ 1,"Short" },
	{ 2,"Medium" },
	{ 3,"Long" },
	{ 4,"Unknown" },
};

const static std::map<int, std::string> mapSkinTone = {
	{ -1,"Unknown" },
	{ 0,"Skin Tone 1" },
	{ 1,"Skin Tone 2" },
	{ 2,"Skin Tone 3" },
	{ 3,"Skin Tone 4" },
	{ 4,"Skin Tone 5" },
	{ 5,"Skin Tone 6" },
	{ 6,"Skin Tone 7" },
	{ 7,"Skin Tone 8" },
	{ 8,"Skin Tone 9" },
	{ 9,"Skin Tone 10" },
	{ 10,"Skin Tone 11" },
	{ 11,"Skin Tone 12" },
	{ 12,"Skin Tone 13" },
	{ 13,"Skin Tone 14" },
	{ 14,"Skin Tone 15" },
	{ 15,"Skin Tone 16" },
	{ 16,"Skin Tone 17" },
	{ 17,"Skin Tone 18" },
	{ 18,"Skin Tone 19" },
	{ 19,"Skin Tone 20" },
};

const static std::map<int, std::string> mapDeclaredForNatione = {
	{ 0,"No" },
	{ 1,"Yes" },
};

const static std::map<int, std::string> mapGeneralOptions = {
	{ 0,"None" },
	{ 2,"Has No Work Permit" },
	{ 8,"Treated As Non-EU In Italy" },
	{ 10,"Has No Work Permit / Treated As Non-EU In Italy" },
};

const static std::map<int, std::string> mapRoleUsedToFillEmptyAttributes = {
	{-1, "Automatic"},
	{ 0,"Goalkeeper" },
	{ 12,"Sweeper Keeper" },
	{ 14,"Libero" },
	{ 2,"Full-Back" },
	{ 3,"Wing-Back" },
	{ 36,"No-Nonsense Full-Back" },
	{ 38,"Complete Wing-Back" },
	{ 44,"Inverted Wing-Back" },
	{ 1,"Central Defender" },
	{ 24,"Ball Playing Defender" },
	{ 29,"No-Nonsense Centre-Back" },
	{ 4,"Defensive Midfielder" },
	{ 15,"Deep Lying Playmaker" },
	{ 33,"Anchor Man" },
	{ 35,"Half Back" },
	{ 39,"Regista" },
	{ 28,"Ball Winning Midfielder" },
	{ 46,"Roaming Playmaker" },
	{ 6,"Wide Midfielder" },
	{ 30,"Defensive Winger" },
	{ 43,"Wide Playmaker" },
	{ 5,"Central Midfielder" },
	{ 16,"Box To Box Midfielder" },
	{ 17,"Advanced Playmaker" },
	{ 7,"Winger" },
	{ 27,"Inside Forward" },
	{ 49,"Inverted Winger" },
	{ 42,"Wide Target Man" },
	{ 45,"Raumdeuter" },
	{ 9,"Attacking Midfielder" },
	{ 37,"Enganche" },
	{ 41,"Shadow Striker" },
	{ 32,"Trequartista" },
	{ 31,"Pressing Forward" },
	{ 10,"Deep Lying Forward" },
	{ 40,"False Nine" },
	{ 11,"Advanced Forward" },
	{ 18,"Target Man" },
	{ 19,"Poacher" },
	{ 20,"Complete Forward" },
	{ 47,"Mezzala" },
	{ 50,"Segundo Volante" },
	{ 48,"Carrilero" },
};

const static std::map<int, std::string> mapRoleUsedToFillEmptyAttributes = {
	{ 0,"Not Set" },
	{ 1,"Right" },
	{ 2,"Left" },
	{ 3,"Right Or Central When Three" },
	{ 4,"Left Or Central When Three" },
	{ 5,"Central When Three" },
	{ 6,"Right Of Two Or Right / Central When Three" },
	{ 7,"Left Of Two Or Left / Central When Three" },
};

#endif