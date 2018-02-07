#pragma once
#include <vector>

class Map
{
public:
	class Region
	{
	private:		
		int numTokens;
		
	};
	std::vector<Region> Regions;
	void addRegion(Region r);
	void setBorder(Region r1, Region r2);
	Map();
	~Map();
	
};

