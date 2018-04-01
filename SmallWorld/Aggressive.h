#pragma once
#include <string>
#include "Strategy.h"


using namespace std;

class GameLoop;
 
class Aggressive : public Strategy
{
public:
	Aggressive();
	~Aggressive();
	void execute(Map* gameMap, Player* player, string phase, GameLoop* gl, GameDeck* gd);
};

