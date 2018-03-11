#pragma once
#include <string>
#include <iostream>

using namespace std;

/*
This class creates the badge types.
*/

class Badge
{

public:
	enum Power {
		ALCHEMIST, BERSERK, BIVOUACKING, COMMANDO, DIPLOMAT, DRAGONMASTER, FLYING, FOREST, FORTIFIED,
		HEROIC, HILL, MERCHANT, MOUNTED, PILLAGING, SEAFARING, SPIRIT, STOUT, SWAMP, UNDERWORLD, WEALTHY
	};   //enum to create badge powers
	Badge();
	Badge(Power);
	~Badge();

	int getBadgeType();
	string getBadgeName();

private:
	Power badgeType;
};


