#pragma once
#include <string>
#include <vector>

using namespace std;

class Player;

class Region
{
private:
	Player* owner;
	string regionName;
	int numTokens;
	bool owned;
	bool lostTribe;
	bool mountain;
public:
	vector<Region*> neighbors;
	bool hasMountain();
	bool hasLostTribe();
	void setOwned(bool o);
	bool isOwned();
	void setRegionName(string name);
	void setNumTokens(int num);
	void addNeighbor(Region*  &r);
	void eliminateMountain();
	void eliminateLostTribe();
	void setOwner(Player* const & player);
	vector<Region*> getNeighbors() const;
	Player* getOwner() const;
	string getRegionName() const;
	int getNumTokens() const;
	Region();
	Region(string name);
	~Region();
};

