#pragma once
#include <iostream>
#include <string>
#include "MapLoader.h"
#include "Player.h"
#include "Map.h"
#include "Banner.h"
#include "Badge.h"
#include <algorithm>
#include "Subject.h"

using namespace std;

/*
This class is the body of the program: it contains the logic of the Game Loop (from initializing/starting a game to handling all turn-based logic)
*/
class GameLoop : public Subject
{
private:
	int gameTurnMarker;
	int numTurns;
	Map gameMap;
	GameDeck gameDeck;
public:
	vector<Player*> players;
	int getTurn() { return gameTurnMarker; };
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

