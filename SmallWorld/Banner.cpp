#include "stdafx.h"
#include "Banner.h"


Banner::Banner()
{
}

Banner::Banner(Race race)
{

	raceType = race;
}


Banner::~Banner()
{
}

int Banner::getRaceType()
{

	return raceType;
}

string Banner::getRaceName()
{
	switch (getRaceType()) {
	case 0: //AMAZONS
		return "AMAZONS";
		break;
	case 1: //DWARVES
		return "DWARVES";
		break;
	case 2: //ELVES
		return "ELVES";
		break;
	case 3: //GHOULS
		return "GHOULS";
		break;
	case 4: //RATMEN	
		return "RATMEN";
		break;
	case 5: //SKELETONS
		return "SKELETONS";
		break;
	case 6: //SORCERERS
		return "SORCERORS";
		break;
	case 7: //TRITONS
		return "TRITONS";
		break;
	case 8: //GIANTS
		return "GIANTS";
		break;
	case 9: //HALFLINGS
		return "HALFLINGS";
		break;
	case 10: //HUMANS
		return "HUMANS";
		break;
	case 11: //ORCS
		return "ORCS";
		break;
	case 12: //TROLLS
		return "TROLLS";
		break;
	case 13: //WIZARDS
		return "WIZARDS";
		break;
	}
}

