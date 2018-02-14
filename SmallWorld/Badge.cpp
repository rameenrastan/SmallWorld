#include "stdafx.h"
#include "Badge.h"


Badge::Badge()
{
}

Badge::Badge(string name, Power power)
{
	badgeName = name;
	badgeType = power;
}


Badge::~Badge()
{
}

string Badge::getBadge()
{
	return badgeName;
}

int Badge::getBadgeType()
{
	return badgeType;
}
