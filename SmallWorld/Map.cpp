#include "stdafx.h"
#include "Map.h"
#include <algorithm>
#include <iostream>


void Map::addBorder(Region * r1, Region * r2)
{
	(*r1).addNeighbor(r2);
	(*r2).addNeighbor(r1);
}

void Map::addRegion(Region* r)
{
	regions.push_back(r);
}

void Map::dfsTraversal(Region & currentNode)
{
	visited.push_back(currentNode.getRegionName());
	Region* current = &currentNode;
	vector<Region*> neighbors = (*current).getNeighbors();
	for (auto & neighbor : neighbors)
	{
		if (std::find(visited.begin(), visited.end(), (*neighbor).getRegionName()) != visited.end()) {
		}
		else {
			dfsTraversal(*neighbor);
		}
	}
}

bool Map::isConnected(Region & startNode)
{

	dfsTraversal(startNode);

	cout << "Regions Visited (Connected): " << visited.size() << endl;
	cout << "Total number of regions: " << regions.size() << endl;

	if (visited.size() == regions.size())
	{
		cout << "Map Valid: This graph is connected!" << endl;
		return true;
	}
	else
	{
		cout << "Map Invalid: This graph is not connected!" << endl;
		return false;
	}
}


Map::Map()
{
}


Map::~Map()
{
}
