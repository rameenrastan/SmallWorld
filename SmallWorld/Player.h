#pragma once
#include <vector>
#include "Region.h"
#include "Token.h"
#include "Badge.h"
#include "Banner.h"
#include "VictoryCoin.h"

using namespace std;

class Player
{
private:
	string playerName;
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
	int getRegionCount();
	int getTokenCount();
	int getcoinCount();
	bool checkRegionAdjacency(Region* region);

	void picks_race(Banner banner, Badge bad);
	void conquers(Region* &region);
	void scores();
};

