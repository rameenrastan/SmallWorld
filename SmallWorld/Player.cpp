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
	if (checkRegionAdjacency(region)) {
		if ((*region).hasMountain())
		{
			if (tokenCount > 2) {
				ownedRegions.push_back(region);
				tokenCount = tokenCount - 3;
				(*region).eliminateMountain();
				(*region).setOwned(true);
				(*region).setNumTokens(3);
				(*region).setOwner(this);
				regionCount++;
			}
			else {
				cout << "You do not have enough tokens to conquer this region!" << endl;
			}
		}
		else if ((*region).hasLostTribe())
		{
			if (tokenCount > 2) {
				ownedRegions.push_back(region);
				tokenCount = tokenCount - 3;
				(*region).eliminateLostTribe();
				(*region).setOwned(true);
				(*region).setNumTokens(3);
				(*region).setOwner(this);
				regionCount++;
			}
			else {
				cout << "You do not have enough tokens to conquer this region!" << endl;
			}
		}
		else if ((*region).isOwned())
		{
			if (tokenCount >= (*((*region).getOwner())).getTokenCount() + 2)
			{
				tokenCount = tokenCount - 2;
				(*region).setNumTokens((*region).getNumTokens() + 2);
				ownedRegions.push_back(region);
				(*region).setOwner(this);
			}
			else {
				cout << "You do not have enough tokens to conquer this region!" << endl;
			}
		}
		else if (!(*region).isOwned())
		{
			if (tokenCount > 1)
			{
				ownedRegions.push_back(region);
				tokenCount = tokenCount - 2;
				(*region).setOwned(true);
				(*region).setNumTokens(2);
				(*region).setOwner(this);
				regionCount++;
			}
			else {
				cout << "You do not have enough tokens to conquer this region!" << endl;
			}
		}
	}
	else {

		cout << "This region cannot be conquered by this player." << endl;
	}
}
