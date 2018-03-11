#pragma once
#include <vector>
#include <iostream>
#include "Region.h"
#include "Token.h"
#include "Badge.h"
#include "Banner.h"
#include "VictoryCoin.h"
#include "Dice.h"
#include "GameDeck.h"
#include "GameLoop.h"

using namespace std;

/*
Implements the functionality of a player playing the Small World game.
*/
class Player
{
private:
	string playerName;
	vector<Region*> ownedRegions;
	Badge badge;
	Banner race;
	int regionCount;
	int tokenCount;
	int victoryCoinCount;
	
public:
	Player();
	Player(string);
	~Player();

	string getPlayerName();
	int reinforcementRoll(Dice* dice);
	void displayRollPercentages(Dice* dice);
	int getRegionCount();
	int getTokenCount();
	int getVictoryCoinCount();
	void setVictoryCoinCount(int v);
	bool checkRegionAdjacency(Region* region);
	

	void picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void conquers(Region* &region);
	void scores(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void summarySheet(Banner banner, Badge bad);
};

