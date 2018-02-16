#pragma once
#include <string>
#include <vector>

using namespace std;

class Player;

/*
Implements the functionality of a region on the map (acts as a node on the map's graph).
*/
class Region
{
private:
	Player* owner;
	string regionName;
	int numTokens;
	
	bool owned;
	bool lostTribe;
	bool mountain;
	bool mine;
	bool farmland;
	bool magic;
	bool forest;
	bool fortress;
	bool hill;
	bool swamp;
public:
	vector<Region*> neighbors;

	bool hasMountain();
	bool hasLostTribe();
	bool hasMine();
	void setMine(bool);
	bool isFarmland();
	void setFarmland(bool);
	bool isMagic();
	void setMagic(bool);
	bool isForest();
	void setForest(bool);
	void setOwned(bool o);
	bool isFortress();
	void setFortress(bool);
	bool isHill();
	void setHill(bool);
	bool isSwamp();
	void setSwamp(bool);
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

