#include "stdafx.h"
#include "Banner.h"


Banner::Banner()
{
}

Banner::Banner(string name)
{
	bannerName = name;
}


Banner::~Banner()
{
}

string Banner::getBanner()
{
	return bannerName;
}
