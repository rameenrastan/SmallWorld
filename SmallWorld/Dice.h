#pragma once

using namespace std;


/*
This class implements the Reinforcements Die functionality.
*/
class Dice
{

private:
	int numThreeRolls;
	int numTwoRolls;
	int numOneRolls;
	int numZeroRolls;
	int numTotalRolls;
	double percentThreeRolls;
	double percentTwoRolls;
	double percentOneRolls;
	double percentZeroRolls;
public:
	Dice();
	~Dice();
	void displayRollPercentages();
	int reinforcementRoll();
};

