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
#include "Strategy.h"


using namespace std;

class Aggresive;
/*
This class is the body of the program: it contains the logic of the Game Loop (from initializing/starting a game to handling all turn-based logic)
*/
class GameLoop : public Subject
{
private:
	int gameTurnMarker;
	int numTurns;
	string phase;
	GameDeck gameDeck;
	Player* currentPlayer;
	bool decoratorRequest;
public:
	void addDecorator();
	Map gameMap;
	Player* getCurrentPlayer() { return currentPlayer; };
	vector<Player*> players;
	vector<Player*> getPlayers() { return players; };
	int getTurn() { return gameTurnMarker; };
	string getPhase() { return phase; };
	void initializeGame();
	void placeMountainAndLostTribe();
	void startUpPhase();
	void startUpPhaseTournament();
	void distributeInitialVictoryCoins();
	void determineTurnOrder();
	void generateRaceCombo();
	void playerPicksRace(Player* player);
	void playerInDecline(Player* player);
	vector <pair<Banner, Badge>> pairs;
	void mainLoop();
	void followingTurn(Player* player);
	void mainLoopTournament();
	void twoPlayerTournament();
	void threePlayerTournament();
	void fourPlayerTournament();
	void fivePlayerTournament();
	GameLoop();
	~GameLoop();
};

