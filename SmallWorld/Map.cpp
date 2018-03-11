#include "stdafx.h"
#include "Map.h"
#include <algorithm>
#include <iostream>

/*
Adds a border between two regions (i.e. connects two regions by forming an edge between them on the graph)
*/
void Map::addBorder(Region * r1, Region * r2)
{
	(*r1).addNeighbor(r2);
	(*r2).addNeighbor(r1);
}

/*
Adds a region (node) to  the map (graph).
*/
void Map::addRegion(Region* r)
{
	regions.push_back(r);
}

/*
Performs a Depth-First Search on the map using recursion  to verify if the map (graph) is connected.
*/
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


/*
Checks if the given Map is connected by performing a DFS using the dfsTraversal function (starts at the first node on the graph).
*/
bool Map::isConnected()
{
	cout << "Verifying if map is valid (if its a connected graph) ..." << endl;
	dfsTraversal(*regions[0]);
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

void Map::displayRegionList()
{
	for (auto & region : regions)
	{
		cout << "Region name: " << (*region).getRegionName() << " Type: ";
		if ((*region).hasMountain())
		{
			cout << " (Mountain) " << endl;
		}
		else if ((*region).hasLostTribe())
		{
			cout << " (Lost Tribe) " << endl;
		}
		else
		{
			cout << "Current Number of Tokens: " << (*region).getNumTokens() << endl;
		}
		
	}

}

Map::Map(vector<Region*> r)
{
	regions = r;
}


Map::Map()
{
}


Map::~Map()
{
}
