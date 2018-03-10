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

using namespace std;

/*
Implements the functionality of a player playing the Small World game.
*/
class Player
{
private:
	string playerName;
	vector<Badge> badge;
	vector<Banner> race;
	Dice dice;
	int regionCount;
	int tokenCount;
	int victoryCoinCount;
	
public:
	Player();
	Player(string);
	~Player();
	vector<Region*> ownedRegions;
	string getPlayerName();
	int reinforcementRoll(Dice* dice);
	void displayRollPercentages(Dice* dice);
	int getRegionCount();
	int getTokenCount();
	int getVictoryCoinCount();
	void setVictoryCoinCount(int v);
	bool checkRegionAdjacency(Region* region);
	void picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void conquers(Region* &region, bool finalConquest);
	void scores(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void summarySheet(Banner banner, Badge bad);
	void redeployTroops(Region* r1, Region* r2, int tokens);
	void readyTroops();
	void abandonRegion(Region* r);
	void redeployTroops();
};

