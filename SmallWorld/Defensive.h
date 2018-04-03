#pragma once
#include <string>
#include "Strategy.h"


using namespace std;

class GameLoop;

class Defensive : public Strategy
{
public:
	Defensive();
	~Defensive();
	void execute(Map* gameMap, Player* player, string phase, GameLoop* gl, GameDeck* gd);
};

