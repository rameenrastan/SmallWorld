#pragma once
#include <vector>
#include "Region.h"
#include "Token.h"
#include "Badge.h"
#include "Banner.h"
#include "VictoryCoin.h"
#include "Dice.h"
#include "GameDeck.h"

using namespace std;

class Player
{
private:
	string playerName;
	Dice gameDice;
	vector<Region*> ownedRegions;
	vector<Token*> ownedTokens;
	vector<VictoryCoin*> ownedCoins;
	vector<Badge> badge;
	vector<Banner> race;
	int regionCount;
	int tokenCount;
	int coinCount;

	//SummarySheet
	//DiceRoller
	
public:
	Player();
	Player(string);
	~Player();

	string getPlayerName();
	vector<Region*> getOwnedRegions();
	void setOwnedRegions(Region* r1,Region* r2);
	int reinforcementRoll();
	void displayRollPercentages();
	int getRegionCount();
	int getTokenCount();
	int getcoinCount();
	bool checkRegionAdjacency(Region* region);
	

	void picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void conquers(Region* &region);
	void scores(Banner banner, Badge bad, GameDeck*const &gamedeck);
};

