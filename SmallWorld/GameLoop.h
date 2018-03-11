#pragma once
#include <iostream>
#include <string>
#include "MapLoader.h"
#include "Player.h"
#include "Map.h"
#include "Banner.h"
#include "Badge.h"
#include <algorithm>

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
	void generateRaceCombo();
	void playerPicksRace(Player* player);
	void playerInDecline(Player* player);
	vector <pair<Banner, Badge>> pairs;
	void mainLoop();
	void followingTurn(Player* player);
	GameLoop();
	~GameLoop();
};

