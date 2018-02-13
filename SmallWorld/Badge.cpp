#include "stdafx.h"
#include "Badge.h"


Badge::Badge()
{
}

Badge::Badge(string name)
{
	badgeName = name;
}


Badge::~Badge()
{
}

string Badge::getBadge()
{
	return badgeName;
}
