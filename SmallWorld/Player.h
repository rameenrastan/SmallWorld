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
	int reinforcementRoll(Dice* dice);
	void displayRollPercentages(Dice* dice);
	int getRegionCount();
	int getTokenCount();
	int getcoinCount();
	bool checkRegionAdjacency(Region* region);
	

	void picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck);
	void conquers(Region* &region);
	void scores(Banner banner, Badge bad, GameDeck*const &gamedeck);
};

