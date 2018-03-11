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
	Map gameMap;
	GameDeck gameDeck;
	
	
public:
	void initializeGame();
	void placeMountainAndLostTribe();
	void startUpPhase();
	void distributeInitialVictoryCoins();
	void determineTurnOrder();
	void generateRaceCombo();
	void playerPicksRace(Player* player);
	vector <pair<Banner, Badge>> pairs;
	vector<Player*> players;
	void mainLoop();
	GameLoop();
	~GameLoop();
};

