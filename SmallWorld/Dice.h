#pragma once

using namespace std;

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

