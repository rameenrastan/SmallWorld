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
		string name;
		mapFile >> name;
		regionPointers.push_back(new Region(name));
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
	/*if (map.isConnected())
	{
		cout << "The map was loaded successfully and is a valid map!" << endl;*/
		return map;
	/*}
	else {
		cout << "This map was not loaded successfully, it is an invalid map!" << endl;
	}*/
}

MapLoader::MapLoader()
{
}


MapLoader::~MapLoader()
{
}
