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
	void setMine(bool m);
	bool isFarmland();
	void setFarmland(bool f);
	bool isMagic();
	void setMagic(bool mag);
	bool isForest();
	void setForest(bool fo);
	void setOwned(bool o);
	bool isFortress();
	void setFortress(bool fort);
	bool isHill();
	void setHill(bool h);
	bool isSwamp();
	void setSwamp(bool s);
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

