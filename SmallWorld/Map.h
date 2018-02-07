#pragma once
#include <vector>
#include <string>
using namespace std;

class Map
{
public:
	class Region
	{
	private:
		vector<Region> neighbors;
		string owner;
		string regionName;
		int numTokens;
	public:
		void setOwner(string playerName);
		void setRegionName(string name);
		void setNumTokens(int num);
		void addNeighbor(Region r);
		string getOwner() const;
		string getRegionName() const;
		int getNumTokens() const;	
		Region();
		Region(string regionName);
		~Region();
	};
	vector<Region> regions;
	void addRegion(Region r);
	void setBorder(Region r1, Region r2);
	bool isConnected();

	Map();
	~Map();
};

