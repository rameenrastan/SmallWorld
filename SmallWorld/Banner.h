#pragma once
#include <string>

using namespace std;

class Banner
{
	

public:
	enum Race {AMAZONS,DWARVES,ELVES,GHOULS,RATMEN,SKELETONS,SORCERERS,TRITONS,GIANTS,HALFLINGS,HUMANS,ORCS,TROLLS,WIZARDS};
	
	Banner();
	Banner(string, Race);
	~Banner();

	
	string getBanner();
	int getRaceType();

private:
	Race raceType;
	string bannerName;
};

