#include "stdafx.h"
#include "Player.h"



Player::Player()
{
}

Player::Player(string name)
{
	playerName = name;
	regionCount = 0;
	tokenCount = 0;
	victoryCoinCount = 0;
}

Player::~Player()
{
}

string Player::getPlayerName(){
	return playerName;
}


/*
Allows a player to request a reinforcement dice roll.
*/
int Player::reinforcementRoll(Dice* dice)
{
	return (*dice).reinforcementRoll();
}

/*
Displays the roll percentages of the dice rolled by a player.
*/
void Player::displayRollPercentages(Dice* dice)
{
	(*dice).displayRollPercentages();
}

int Player::getRegionCount(){
	return regionCount;
}

int Player::getTokenCount(){
	return tokenCount;
}

int Player::getVictoryCoinCount(){
	return victoryCoinCount;
}

void Player::setVictoryCoinCount(int v) {
	victoryCoinCount = v;
}

/*
Checks if a given region is adjacent to one of the player's owned regions.
*/
bool Player::checkRegionAdjacency(Region * region)
{
	for (int i = 0; i < ownedRegions.size(); i++)
	{
		for (int j = 0; j < (*(ownedRegions[i])).getNeighbors().size(); j++)
		{
			if ((*(*(ownedRegions[i])).getNeighbors()[j]).getRegionName() == (*region).getRegionName())
			{
				return true;
			}
		}
	}
	return false;
}


/* 
players pick their banner and badge, allocating appropriate 
amount of tokens to them and updating gamedeck tokens
*/

void Player::picks_race(Banner banner, Badge bad, GameDeck*const &gamedeck)
{
 
	race.push_back(banner);
	badge.push_back(bad);
	int storage = 0; // used to store token value of tokens that a badge gives out
	
	switch (banner.getRaceType()) {  //allocating tokens based on race
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
	switch (bad.getBadgeType()) {	//allocating tokens based on badge type
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
	switch (banner.getRaceType()) {  //using the stored value of the prev switch case to update game deck tokens based on race type
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

/*
Called when a player attempts to conquer a region.
Checks the type of region (if it has a lost tribe, is already conquered, etc.) and determines if the user has sufficient number of tokens to conquer it.
Also checks if the region is adjacent to one of the user's currently owned regions.
*/
void Player::conquers(Region* &region)
{
	if (checkRegionAdjacency(region) || ownedRegions.size() == 0) {
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
				cout << playerName << " has conquered region " << (*region).getRegionName() << endl;
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
				cout << playerName << " has conquered region " << (*region).getRegionName() << endl;
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
				cout << playerName << " has conquered region " << (*region).getRegionName() << endl;
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
				cout << playerName << " has conquered region " << (*region).getRegionName() << endl;
			}
			else {
				cout << "You do not have enough tokens to conquer this region!" << endl;
			}
		}
	}
	else {

		cout << (*region).getRegionName() << " cannot be conquered by this player, it is not adjacent to your regions!." << endl;
	}
}

/*
allocates victory coins to players based on number of regions owned and race abilities
*/
void Player::scores(Banner banner, Badge bad, GameDeck*const &gamedeck)
{
	for (int i = 0; i < ownedRegions.size(); i++) {   
		victoryCoinCount++;	//give 1 coin for every region owned
		(*gamedeck).setGameCoin(1);		
		switch (banner.getRaceType()) {  //allocating victory coins based on race type
			case 1: //DWARVES
				if ((*ownedRegions[i]).hasMine()) {   //give 1 extra coin for each mine region a dwarf owns
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
				break;
			case 10: //HUMANS
				if ((*ownedRegions[i]).isFarmland()) { //give 1 extra coin for each farm region a human owns
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
				break;
			case 11: //ORCS
				//1 extra coin for each non empty region conquered
				break;
			case 13: //WIZARDS
				if ((*ownedRegions[i]).isMagic()) { //give 1 extra coin for each magic region a wizard owns
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
		}
	}
	switch (bad.getBadgeType()) {  //allocating victory coins based on badge type
		case 0: //ALCHEMIST
			victoryCoinCount += 2;   //gives 2 extra coins per turn 
			(*gamedeck).setGameCoin(2);
			break;
		case 7: //FOREST
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isForest()) { //give 1 extra coin for each forest region owned
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 8: //FORTIFIED
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isFortress()) { //give 1 extra coin for each fortress on a region owned
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 10: //HILL
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isHill()) { //give 1 extra coin for each hill region owned
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 11: //MERCHANT
			for (int i = 0; i < ownedRegions.size(); i++) {  //give 1 extra coin for each region owned
				victoryCoinCount++;
			}
			break;
		case 13: //PILLAGING
			//1 extra coin for each non empty region conquered
			break;
		case 17: //SWAMP
			for (int i = 0; i < ownedRegions.size(); i++) {
				if ((*ownedRegions[i]).isSwamp()) { //give 1 extra coin for every swamp region owned
					victoryCoinCount++;
					(*gamedeck).setGameCoin(1);
				}
			}
			break;
		case 19: //WEALTHY
			//should receive 7 extra coins on only first round active
			break;
	}
}

/*
Displays the information of the player. Name,race,badge,tokens,victory coins.
*/
void Player::summarySheet(Banner banner, Badge bad)
{
	cout << "Name: " << getPlayerName() << endl;
	switch (banner.getRaceType()) {
	case 0: //AMAZONS
		cout << "Current race: AMAZONS" << endl;
		break;
	case 1: //DWARVES
		cout << "Current race: DWARVES"<<endl;
		break;
	case 2: //ELVES
		cout << "Current race: ELVES"<<endl;
		break;
	case 3: //GHOULS
		cout << "Current race: GHOULS"<<endl;
		break;
	case 4: //RATMEN	
		cout << "Current race: RATMEN" << endl;
		break;
	case 5: //SKELETONS
		cout << "Current race: SKELETONS" << endl;
		break;
	case 6: //SORCERERS
		cout << "Current race: SORCERORS" << endl;
		break;
	case 7: //TRITONS
		cout << "Current race: TRITONS" << endl;
		break;
	case 8: //GIANTS
		cout << "Current race: GIANTS" << endl;
		break;
	case 9: //HALFLINGS
		cout << "Current race: HALFLINGS" << endl;
		break;
	case 10: //HUMANS
		cout << "Current race: HUMANS" << endl;
		break;
	case 11: //ORCS
		cout << "Current race: ORCS" << endl;
		break;
	case 12: //TROLLS
		cout << "Current race: TROLLS" << endl;
		break;
	case 13: //WIZARDS
		cout << "Current race: WIZARDS" << endl;
		break;
	}
	switch (bad.getBadgeType()) {
	case 0: //ALCHEMIST
		cout << "Current badge: ALCHEMIST" << endl;
		break;
	case 1: //BERSERK
		cout << "Current badge: BERSERK" << endl;
		break;
	case 2: //BIVOUACKING
		cout << "Current badge: BIVOUACKING" << endl;
		break;
	case 3: //COMMANDO
		cout << "Current badge: COMMANDO" << endl;
		break;
	case 4: //DIPLOMAT
		cout << "Current badge: DIPLOMAT" << endl;
		break;
	case 5: //DRAGONMASTER
		cout << "Current badge: DRAGONMASTER" << endl;
		break;
	case 6: //FLYING
		cout << "Current badge: FLYING" << endl;
		break;
	case 7: //FOREST
		cout << "Current badge: FOREST" << endl;
		break;
	case 8: //FORTIFIED
		cout << "Current badge: FORTIFIED" << endl;
		break;
	case 9: //HEROIC
		cout << "Current badge: HEROIC" << endl;
		break;
	case 10: //HILL
		cout << "Current badge: HILL" << endl;
		break;
	case 11: //MERCHANT
		cout << "Current badge: MERCHANT" << endl;
		break;
	case 12: //MOUNTED
		cout << "Current badge: MOUNTED" << endl;
		break;
	case 13: //PILLAGING
		cout << "Current badge: PILLAGING" << endl;
		break;
	case 14: //SEAFARING
		cout << "Current badge: SEAFARING" << endl;
		break;
	case 15: //SPIRIT
		cout << "Current badge: SPIRIT" << endl;
		break;
	case 16: //STOUT
		cout << "Current badge: STOUT" << endl;
		break;
	case 17: //SWAMP
		cout << "Current badge: SWAMP" << endl;
		break;
	case 18: //UNDERWORLD
		cout << "Current badge: UNDERWORLD" << endl;
		break;
	case 19: //WEALTHY
		cout << "Current badge: WEALTHY" << endl;
		break;
	}
	cout << "Number of tokens available: "<< getTokenCount() << endl;
	cout << "Number of victoy coins: " << getVictoryCoinCount() << endl;
}

