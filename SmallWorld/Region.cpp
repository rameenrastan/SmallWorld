#include "stdafx.h"
#include "Region.h"


Region::Region()
{
}

Region::Region(string name)
{
	regionName = name;
	owner = "none";
	numTokens = 0;
}

Region::~Region()
{
}

void Region::setOwner(string playerName)
{
	playerName = owner;
}

string Region::getRegionName() const
{
	return regionName;
}

int Region::getNumTokens() const
{
	return numTokens;
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

vector<Region*> Region::getNeighbors() const
{
	return neighbors;
}

string Region::getOwner() const
{
	return owner;
}