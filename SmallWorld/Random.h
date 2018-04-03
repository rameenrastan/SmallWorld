#pragma once
#include <string>
#include "Strategy.h"


using namespace std;

class GameLoop;

class Random : public Strategy
{
public:
	Random();
	~Random();
	void execute(Map* gameMap, Player* player, string phase, GameLoop* gl, GameDeck* gd);
};

