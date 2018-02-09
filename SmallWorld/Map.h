#pragma once
#include <vector>
#include <string>
#include "Region.h"

using namespace std;

class Map
{
private:
	vector<Region*> regions;
	vector<string> visited;
public:
	void addBorder(Region* r1, Region* r2);
	void addRegion(Region* r);
	void dfsTraversal(Region & currentNode);
	bool isConnected();
	Map();
	~Map();
};

