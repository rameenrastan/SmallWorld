#include "stdafx.h"
#include "Badge.h"


Badge::Badge()
{
}

Badge::Badge(Power power)
{
	badgeType = power;
}


Badge::~Badge()
{
}


int Badge::getBadgeType()
{
	return badgeType;
}

string Badge::getBadgeName()
{
	switch (getBadgeType()) {
	case 0: //ALCHEMIST
		return "ALCHEMIST";
		break;
	case 1: //BERSERK
		return "BERSERK";
		break;
	case 2: //BIVOUACKING
		return "BIVOUACKING";
		break;
	case 3: //COMMANDO
		return "COMMANDO";
		break;
	case 4: //DIPLOMAT
		return "DIPLOMAT";
		break;
	case 5: //DRAGONMASTER
		return "DRAGONMASTER";
		break;
	case 6: //FLYING
		return "FLYING";
		break;
	case 7: //FOREST
		return "FOREST";
		break;
	case 8: //FORTIFIED
		return "FORTIFIED";
		break;
	case 9: //HEROIC
		return "HEROIC";
		break;
	case 10: //HILL
		return "HILL";
		break;
	case 11: //MERCHANT
		return "MERCHANT";
		break;
	case 12: //MOUNTED
		return "MOUNTED";
		break;
	case 13: //PILLAGING
		return "PILLAGING";
		break;
	case 14: //SEAFARING
		return "SEAFARING";
		break;
	case 15: //SPIRIT
		return "SPIRIT";
		break;
	case 16: //STOUT
		return "STOUT";
		break;
	case 17: //SWAMP
		return "SWAMP";
		break;
	case 18: //UNDERWORLD
		return "UNDERWORLD";
		break;
	case 19: //WEALTHY
		return "WEALTHY";
		break;
	}
}
