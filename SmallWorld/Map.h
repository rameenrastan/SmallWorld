#pragma once
#include <vector>
#include <string>
#include "Region.h"

using namespace std;

class Map
{
private:
	vector<string> visited;
public:
	vector<Region*> regions;
	void addBorder(Region* r1, Region* r2);
	void addRegion(Region* r);
	void dfsTraversal(Region & currentNode);
	//bool isConnected(Region & startNode);
	bool isConnected();
	Map(vector<Region*> r);
	Map();
	~Map();
};

