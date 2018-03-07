#include "stdafx.h"
#include "MapLoader.h"
#include <string>
#include <iostream>

/*
Loads a map object by reading a .map text file.
Checks if the map is valid (i.e. if it forms a connected map) before loading it as a map object.
*/
Map MapLoader::loadMap(string mapFileLocation)
{
	ifstream mapFile;
	mapFile.open(mapFileLocation, ios::in);
	cout << "Attempting to load file " << mapFileLocation << " as a game map..." << endl;
	int numRegions;
	mapFile >> numRegions;
	for(int i = 0; i < numRegions; i++)
	{
		string name, symbol;
		mapFile >> name;
		mapFile >> symbol;
		cout << name << " " << symbol << endl;
		regionPointers.push_back(new Region(name, symbol));
	
	}

	for(auto & region : regionPointers)
	{
		int numNeighbors;
		mapFile >> numNeighbors;
		for (int j = 0; j < numNeighbors; j++)
		{
			string neighborName;
			mapFile >> neighborName;
			for (int k = 0; k < regionPointers.size(); k++)
			{
				if ((*regionPointers[k]).getRegionName() == neighborName)
				{
					(*region).addNeighbor(regionPointers[k]);
				}
			}
		}
	}
	Map map(regionPointers);
	regionPointers.clear();
	return map;
}

MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}
