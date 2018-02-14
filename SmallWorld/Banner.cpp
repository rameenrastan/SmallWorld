#include "stdafx.h"
#include "Banner.h"


Banner::Banner()
{
}

Banner::Banner(string name,Race race)
{
	bannerName = name;
	raceType = race;
}


Banner::~Banner()
{
}

string Banner::getBanner()
{
	return bannerName;
}

int Banner::getRaceType()
{
	return raceType;
}



