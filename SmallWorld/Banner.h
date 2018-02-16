#pragma once
#include <string>

using namespace std;

/*
This class creates the race types
*/

class Banner
{
	

public:
	enum Race {AMAZONS,DWARVES,ELVES,GHOULS,RATMEN,SKELETONS,SORCERERS,TRITONS,GIANTS,HALFLINGS,HUMANS,ORCS,TROLLS,WIZARDS};  //enum to create races
	
	Banner();
	Banner(Race);
	~Banner();

	int getRaceType();

private:
	Race raceType;
};

