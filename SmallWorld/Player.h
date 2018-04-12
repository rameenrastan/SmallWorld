#pragma once
#include <vector>
#include <iostream>
#include "Region.h"
#include "Badge.h"
#include "Banner.h"
#include "Dice.h"
#include "GameDeck.h"
#include "GameLoop.h"

using namespace std;

class GameLoop;
class Region;
class Strategy;
/*
Implements the functionality of a player playing the Small World game.
*/
class Player
{
private:
	Strategy *strategy;
	Badge badge;
	Banner race;
	Dice dice;
	int regionCount;
	int tokenCount;
	int victoryCoinCount;
	bool raceInDecline;
	bool hasStrategy;
	
public:
	Player();
	Player(string name);

	~Player();


	void setStrategy(Strategy *newStrategy);
	void executeStrategy(Map* gameMap, Player* player, string phase, GameLoop * gl, GameDeck* gd);
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
	void setHasStrategy(bool strat);
	bool getHasStrategy();
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

