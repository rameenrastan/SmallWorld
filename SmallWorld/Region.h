#pragma once
#include <string>
#include <vector>
using namespace std;

class Region
{
private:
	string owner;
	string regionName;
	int numTokens;
public:
	vector<Region*> neighbors;
	void setOwner(string playerName);
	void setRegionName(string name);
	void setNumTokens(int num);
	void addNeighbor(Region*  &r);
	vector<Region*> getNeighbors() const;
	string getOwner() const;
	string getRegionName() const;
	int getNumTokens() const;
	Region();
	Region(string name);
	~Region();
	
};

