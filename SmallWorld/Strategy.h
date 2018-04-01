#pragma once
#include <string>
#include "Player.h"
#include "Map.h"

using namespace std;


class GameLoop;
class Strategy
{
public:
	Strategy();
	~Strategy();
	virtual void execute(Map* gameMap, Player* player, string phase, GameLoop* gl, GameDeck* gd) = 0;
};

