#pragma once
#include <vector>
#include "Region.h"

class Player
{
private:
	string name;

	vector<Region*> ownedRegions;
	
public:
	Player();
	~Player();
};

