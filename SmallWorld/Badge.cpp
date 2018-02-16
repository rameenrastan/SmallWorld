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
