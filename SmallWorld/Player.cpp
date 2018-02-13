#include "stdafx.h"
#include "Player.h"
#include <iostream>
#include "Banner.h"


Player::Player()
{
}

Player::Player(string name)
{
	playerName = name;
	regionCount = 0;
	tokenCount = 0;
	coinCount = 5;
}

Player::~Player()
{
}

string Player::getPlayerName()
{
	return playerName;
}

int Player::getRegionCount()
{
	return regionCount;
}

int Player::getTokenCount()
{
	return tokenCount;
}

int Player::getcoinCount()
{
	return coinCount;
}

void Player::picks_race(Banner banner, Badge bad)
{
	race.push_back(banner);
	badge.push_back(bad);
	//cout<<banner.getBanner();
	//cout<<bad.getBadge();
}

void Player::conquers(Region region)
{
	ownedRegions.push_back(region);
	regionCount++;
}
