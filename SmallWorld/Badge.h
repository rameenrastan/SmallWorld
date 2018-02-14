#pragma once
#include <string>

using namespace std;

class Badge
{

public:
	enum Power {ALCHEMIST, BERSERK, BIVOUACKING, COMMANDO, DIPLOMAT, DRAGONMASTER, FLYING, FOREST, FORTIFIED, HEROIC, HILL, MERCHANT, MOUNTED,PILLAGING,SEAFARING,SPIRIT,STOUT,SWAMP,UNDERWORLD,WEALTHY};
	Badge();
	Badge(string, Power);
	~Badge();

	string getBadge();
	int getBadgeType();

private:
	Power badgeType;
	string badgeName;
};


