#pragma once
#include <string>
#include "Player.h"
#include "Map.h"
using namespace std;

class Strategy
{
public:
	Strategy();
	~Strategy();
	virtual void execute(Map* gameMap, Player* player, string phase) = 0;
};

