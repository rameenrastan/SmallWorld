#pragma once
#include <string>
#include  "Player.h"

using namespace std;

class Aggressive
{
public:
	Aggressive();
	~Aggressive();
	void execute(Map* gameMap, Player* player, string phase);
};

