#include "stdafx.h"
#include "Region.h"

Region::Region()
{
}

Region::Region(string name)
{
	regionName = name;
	numTokens = 0;
}

Region::~Region()
{
}

string Region::getRegionName() const
{
	return regionName;
}

int Region::getNumTokens() const
{
	return numTokens;
}

bool Region::hasMountain()
{
	return mountain;
}

bool Region::hasLostTribe()
{
	return lostTribe;
}

void Region::setOwned(bool o)
{
	owned = o;
}

bool Region::isOwned()
{
	return owned;
}

void Region::setRegionName(string name)
{
	regionName = name;
}

void Region::setNumTokens(int num)
{
	numTokens = num;
}

void Region::addNeighbor(Region* &r)
{
	neighbors.push_back(r);
}

void Region::eliminateMountain()
{
	mountain = false;
}

void Region::eliminateLostTribe()
{
	lostTribe = false;
}

void Region::setOwner(Player* const & player)
{
	owner = player;
}

vector<Region*> Region::getNeighbors() const
{
	return neighbors;
}

Player* Region::getOwner() const
{
	return owner;
}