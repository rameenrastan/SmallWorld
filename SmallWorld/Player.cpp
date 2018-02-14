#include "stdafx.h"
#include "Player.h"
#include <iostream>



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

void Player::picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck)
{
	race.push_back(banner);
	badge.push_back(bad);
	switch (banner.getRaceType()) {  
		case 0: //AMAZONS
			tokenCount+=6;
			(*gamedeck).setAmazonToken(6);
			break;
		case 1: //DWARVES
			tokenCount += 3;
			(*gamedeck).setDwarfToken(3);
			break;
		case 2: //ELVES
			tokenCount += 6;
			(*gamedeck).setElfToken(6);
			break;
		case 3: //GHOULS
			tokenCount += 5;
			(*gamedeck).setGhoulToken(5);
			break;
		case 4: //RATMEN
			tokenCount += 8;
			(*gamedeck).setRatToken(8);
			break;
		case 5: //SKELETONS
			tokenCount += 6;
			(*gamedeck).setSkeletonToken(6);
			break;
		case 6: //SORCERERS
			tokenCount += 5;
			(*gamedeck).setSorcererToken(5);
			break;
		case 7: //TRITONS
			tokenCount += 6;
			(*gamedeck).setTritonToken(6);
			break;
		case 8: //GIANTS
			tokenCount += 6;
			(*gamedeck).setGiantToken(6);
			break;
		case 9: //HALFLINGS
			tokenCount += 6;
			(*gamedeck).setHalflingToken(6);
			break;
		case 10: //HUMANS
			tokenCount += 5;
			(*gamedeck).setHumanToken(5);
			break;
		case 11: //ORCS
			tokenCount += 5;
			(*gamedeck).setOrcToken(5);
			break;
		case 12: //TROLLS
			tokenCount += 5;
			(*gamedeck).setTrollToken(5);
			break;
		case 13: //WIZARDS
			tokenCount += 5;
			(*gamedeck).setWizardToken(5);
			break;
	}
	switch (bad.getBadgeType()) {
		case 0: //ALCHEMIST
			tokenCount += 4;
			break;
		case 1: //BERSERK
			tokenCount += 4;
			break;
		case 2: //BIVOUACKING
			tokenCount += 5;
			break;
		case 3: //COMMANDO
			tokenCount += 4;
			break;
		case 4: //DIPLOMAT
			tokenCount += 5;
			break;
		case 5: //DRAGONMASTER
			tokenCount += 5;
			break;
		case 6: //FLYING
			tokenCount += 5;
			break;
		case 7: //FOREST
			tokenCount += 4;
			break;
		case 8: //FORTIFIED
			tokenCount += 3;
			break;
		case 9: //HEROIC
			tokenCount += 5;
			break;
		case 10: //HILL
			tokenCount += 5;
			break;
		case 11: //MERCHANT
			tokenCount += 2;
			break;
		case 12: //MOUNTED
			tokenCount += 5;
			break;
		case 13: //PILLAGING
			tokenCount += 5;
			break;
		case 14: //SEAFARING
			tokenCount += 5;
			break;
		case 15: //SPIRIT
			tokenCount += 5;
			break;
		case 16: //STOUT
			tokenCount += 4;
			break;
		case 17: //SWAMP
			tokenCount += 4;
			break;
		case 18: //UNDERWORLD
			tokenCount += 5;
			break;
		case 19: //WEALTHY
			tokenCount += 4;
			break;

	}
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
