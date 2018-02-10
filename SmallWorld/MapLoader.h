#pragma once
#include "Map.h"
#include <fstream>

class MapLoader
{
private:
	vector<Region*> regionPointers;
public:
	Map loadMap(string mapFileLocation);
	MapLoader();
	~MapLoader();
};

