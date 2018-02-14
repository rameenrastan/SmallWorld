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

bool Player::checkRegionAdjacency(Region * region)
{
	for (int i = 0; i < ownedRegions.size(); i++)
	{
		for (int j = 0; j < (*(ownedRegions[i])).getNeighbors().size(); j++)
		{
			
			if ((*(*(ownedRegions[i])).getNeighbors()[j]).getRegionName() == (*region).getRegionName())
			{
				cout << "This region is adjacent to one of this players owned regions" << endl;
				return true;
			}

		}
	}

	cout << "This region is not adjacent to one of this players owned regions" << endl;
	return false;
}

void Player::picks_race(Banner banner, Badge bad)
{
	race.push_back(banner);
	badge.push_back(bad);
	//cout<<banner.getBanner();
	//cout<<bad.getBadge();
}

void Player::conquers(Region* &region)
{
	ownedRegions.push_back(region);
	regionCount++;
}
