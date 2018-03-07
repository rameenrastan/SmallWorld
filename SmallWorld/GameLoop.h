#pragma once
#include <iostream>
#include <string>
#include "MapLoader.h"
#include "Player.h"
#include "Map.h"

using namespace std;

class GameLoop
{
private:
	int gameTurnMarker;
	Map gameMap;
	GameDeck gameDeck;
	vector<Player*> players;
public:
	void initializeGame();
	void placeMountainAndLostTribe();
	GameLoop();
	~GameLoop();
};

