#include "stdafx.h"
#include "Map.h"
#include <algorithm>
#include <iostream>


void Map::addRegion(Region r)
{
	regions.push_back(r);
}

void Map::traversal(Region & currentNode)
{
	visited.push_back(currentNode.getRegionName());
	Region* current = &currentNode;
	cout << (*current).getRegionName() << " loc: " << current << endl;
	vector<Region*> neighbors = (*current).getNeighbors();
	for (auto & neighbor : neighbors)
	{
		if (std::find(visited.begin(), visited.end(), (*neighbor).getRegionName()) != visited.end()) {
		}
		else {
			cout << (*neighbor).getRegionName() << " neighbors: " << (*neighbor).getNeighbors().size() << " location: " << neighbor << endl;
			traversal(*neighbor);
		}
	}
}

bool Map::isConnected()
{
	cout << visited.size() << endl;
	cout << regions.size() << endl;
	vector<string> regionList;

	for (int i = 0; i < regions.size(); i++)
	{
		regionList.push_back(regions[i].getRegionName());
	}
	if (visited.size() == regionList.size())
	{
		return true;
	}
	else
	{
		return false;
	}

}

Map::Map()
{
}


Map::~Map()
{
}
