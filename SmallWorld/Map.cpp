#include "stdafx.h"
#include "Map.h"


void Map::addRegion(Region r)
{
	regions.push_back(r);
}

void Map::setBorder(Region r1, Region r2)
{
	r1.addNeighbor(r2);
	r2.addNeighbor(r1);
}

bool Map::isConnected()
{
	vector<Region> visited;
	Region *currentRegion = &regions.front();
	visited.push_back(*currentRegion);


	return false;
}

Map::Map()
{
}


Map::~Map()
{
}

Map::Region::Region()
{
}

Map::Region::Region(string name)
{
	regionName  = name;
	owner = "none";
	numTokens = 0;
}

Map::Region::~Region()
{
}

void Map::Region::setOwner(string playerName)
{
	playerName = owner;
}

string Map::Region::getRegionName() const
{
	return regionName;
}

int Map::Region::getNumTokens() const
{
	return numTokens;
}

void Map::Region::setRegionName(string name)
{
	regionName = name;
}

void Map::Region::setNumTokens(int num)
{
	numTokens = num;
}

void Map::Region::addNeighbor(Region r)
{
	neighbors.push_back(r);
}

string Map::Region::getOwner() const
{
	return owner;
}
