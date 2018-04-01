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

class Region;
/*
Implements the functionality of a player playing the Small World game.
*/
class Player
{
private:
	Badge badge;
	Banner race;
	Dice dice;
	int regionCount;
	int tokenCount;
	int victoryCoinCount;
	bool raceInDecline;
	
public:
	Player();
	Player(string);
	~Player();
	string playerName;
	vector<Region*> ownedRegions;
	string getPlayerName();
	int reinforcementRoll(Dice* dice);
	void displayRollPercentages(Dice* dice);
	int getRegionCount();
	int getTokenCount();
	int getVictoryCoinCount();
	void setVictoryCoinCount(int v);
	bool getRaceInDecline();
	string getRaceName() { if (race.getRaceName() == "AMAZONS" && badge.getBadgeName() == "ALCHEMIST") { return ""; } else { return race.getRaceName(); } }
	string getBadgeName() { if (race.getRaceName() == "AMAZONS" && badge.getBadgeName() == "ALCHEMIST") { return ""; } else { return badge.getBadgeName(); } }
	bool checkRegionAdjacency(Region* region);
	void picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void conquers(Region* &region, bool finalConquest);
	void displayOwnedRegions();
	void scores(GameDeck*const &gamedeck);
	void summarySheet();
	void redeployTroops(Region* r1, Region* r2, int tokens);
	void readyTroops();
	void abandonRegion(Region* r);
	void redeployTroops();
	void decline(Banner, Badge, GameDeck* const & gameDeck);
};

