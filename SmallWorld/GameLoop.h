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
	int numTurns;
	Map gameMap;
	GameDeck gameDeck;
public:
	vector<Player*> players;
	void initializeGame();
	void placeMountainAndLostTribe();
	void startUpPhase();
	void distributeInitialVictoryCoins();
	void determineTurnOrder();
	void mainLoop();
	void followingTurn(Player* player);
	GameLoop();
	~GameLoop();
};

