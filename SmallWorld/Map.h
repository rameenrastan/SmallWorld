#pragma once
#include <vector>
#include <string>
#include "Region.h"

using namespace std;

/*
Implements the functionality of the Small World Map (functioning as a connected graph).
*/
class Map
{
private:
	vector<string> visited;
public:
	vector<Region*> regions;
	void addBorder(Region* r1, Region* r2);
	void addRegion(Region* r);
	void dfsTraversal(Region & currentNode);
	bool isConnected();
	Map(vector<Region*> r);
	Map();
	~Map();
};

