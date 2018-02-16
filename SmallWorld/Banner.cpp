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



