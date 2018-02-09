#pragma once
#include <vector>
#include <string>
#include "Region.h"

using namespace std;

class Map
{
private:
	vector<Region> regions;
	vector<string> visited;
public:
	void addRegion(Region r);
	void traversal(Region & currentNode);
	bool isConnected();
	Map();
	~Map();
};

