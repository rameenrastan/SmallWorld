#include "stdafx.h"
#include "Player.h"
#include <iostream>



Player::Player()
{
}

Player::Player(string name)
{
	Dice gameDice;
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

vector<Region*> Player::getOwnedRegions()
{
	return ownedRegions;
}

void Player::setOwnedRegions(Region* r1, Region* r2)
{
	ownedRegions.push_back(r1);
	ownedRegions.push_back(r2);

}



int Player::reinforcementRoll()
{
	return gameDice.reinforcementRoll();
}

void Player::displayRollPercentages()
{
	gameDice.displayRollPercentages();
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


/* picks_race: players pick their banner and badge, allocating 
   appropriate amount of tokens to them and updating gamedeck tokens */

void Player::picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck)
{
 
	race.push_back(banner);
	badge.push_back(bad);
	int storage = 0; // used to store token value of tokens that a badge gives out
	
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
			storage += 4;
			break;
		case 1: //BERSERK
			tokenCount += 4;
			storage += 4;
			break;
		case 2: //BIVOUACKING
			tokenCount += 5;
			storage += 5;
			break;
		case 3: //COMMANDO
			tokenCount += 4;
			storage += 4;
			break;
		case 4: //DIPLOMAT
			tokenCount += 5;
			storage += 5;
			break;
		case 5: //DRAGONMASTER
			tokenCount += 5;
			storage += 5;
			break;
		case 6: //FLYING
			tokenCount += 5;
			storage += 5;
			break;
		case 7: //FOREST
			tokenCount += 4;
			storage += 4;
			break;
		case 8: //FORTIFIED
			tokenCount += 3;
			storage += 3;
			break;
		case 9: //HEROIC
			tokenCount += 5;
			storage += 5;
			break;
		case 10: //HILL
			tokenCount += 5;
			storage += 5;
			break;
		case 11: //MERCHANT
			tokenCount += 2;
			storage += 2;
			break;
		case 12: //MOUNTED
			tokenCount += 5;
			storage += 5;
			break;
		case 13: //PILLAGING
			tokenCount += 5;
			storage += 5;
			break;
		case 14: //SEAFARING
			tokenCount += 5;
			storage += 5;
			break;
		case 15: //SPIRIT
			tokenCount += 5;
			storage += 5;
			break;
		case 16: //STOUT
			tokenCount += 4;
			storage += 4;
			break;
		case 17: //SWAMP
			tokenCount += 4;
			storage += 4;
			break;
		case 18: //UNDERWORLD
			tokenCount += 5;
			storage += 5;
			break;
		case 19: //WEALTHY
			tokenCount += 4;
			storage += 4;
			break;
		}
	switch (banner.getRaceType()) {
		case 0: //AMAZONS
			(*gamedeck).setAmazonToken(storage);
			break;
		case 1: //DWARVES
			(*gamedeck).setDwarfToken(storage);
			break;
		case 2: //ELVES
			(*gamedeck).setElfToken(storage);
			break;
		case 3: //GHOULS
			(*gamedeck).setGhoulToken(storage);
			break;
		case 4: //RATMEN	
			(*gamedeck).setRatToken(storage);
			break;
		case 5: //SKELETONS
			(*gamedeck).setSkeletonToken(storage);
			break;
		case 6: //SORCERERS
			(*gamedeck).setSorcererToken(storage);
			break;
		case 7: //TRITONS
			(*gamedeck).setTritonToken(storage);
			break;
		case 8: //GIANTS
			(*gamedeck).setGiantToken(storage);
			break;
		case 9: //HALFLINGS
			(*gamedeck).setHalflingToken(storage);
			break;
		case 10: //HUMANS
			(*gamedeck).setHumanToken(storage);
			break;
		case 11: //ORCS
			(*gamedeck).setOrcToken(storage);
			break;
		case 12: //TROLLS
			(*gamedeck).setTrollToken(storage);
			break;
		case 13: //WIZARDS
			(*gamedeck).setWizardToken(storage);
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

//allocates victory coins to players based on number of regions owned and race abilities

void Player::scores(Banner banner, Badge bad, GameDeck*const &gamedeck)
{
	for (int i = 0; i < ownedRegions.size(); i++) {
		coinCount++;
		(*gamedeck).setGameCoin(1);
		switch (banner.getRaceType()) {
			case 1: //DWARVES
				if ((*ownedRegions[i]).hasMine()) {   //give 1 extra coin for each mine region a dwarf owns
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
				break;
			case 10: //HUMANS
				if ((*ownedRegions[i]).isFarmland()) { //give 1 extra coin for each farm region a human owns
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
				break;
			case 11: //ORCS
				//1 extra coin for each non empty region conquered
				break;
			case 13: //WIZARDS
				if ((*ownedRegions[i]).isMagic()) { //give 1 extra coin for each magic region a wizard owns
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
		}
	}
	switch (bad.getBadgeType()) {
		case 0: //ALCHEMIST
			coinCount += 2;   //gives 2 extra coins per turn 
			(*gamedeck).setGameCoin(2);
			break;
		case 6: //FLYING
			tokenCount += 5;
			break;
		case 7: //FOREST
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isForest()) { //give 1 extra coin for each forest region owned
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 8: //FORTIFIED
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isFortress()) { //give 1 extra coin for each fortress on a region owned
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 10: //HILL
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isHill()) { //give 1 extra coin for each hill region owned
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 11: //MERCHANT
			for (int i = 0; i < ownedRegions.size(); i++) {  //give 1 extra coin for each region owned
				coinCount++;
			}
			break;
		case 13: //PILLAGING
			//1 extra coin for each non empty region conquered
			break;
		case 17: //SWAMP
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isSwamp()) { //give 1 extra coin for every swamp region owned
					coinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 19: //WEALTHY
			//should receive 7 extra coins on only first round active
			break;
	}
}
