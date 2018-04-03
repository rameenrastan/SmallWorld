#pragma once
#include <string>
#include "Strategy.h"


using namespace std;

class GameLoop;

class Moderate : public Strategy
{
public:
	Moderate();
	~Moderate();
	void execute(Map* gameMap, Player* player, string phase, GameLoop* gl, GameDeck* gd);
};
