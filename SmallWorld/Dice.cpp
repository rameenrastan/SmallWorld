#include "stdafx.h"
#include "Dice.h"
#include <stdlib.h>     
#include <time.h>       
#include <iostream>


Dice::Dice()
{
	numZeroRolls = 0;
	numOneRolls = 0;
	numTwoRolls = 0;
	numThreeRolls = 0;
	numTotalRolls = 0;
	percentZeroRolls = 0;
	percentOneRolls = 0;
	percentTwoRolls = 0;
	percentThreeRolls = 0;
}


Dice::~Dice()
{
}

/*
Displays the percentages of all the individual values rolled up to now.
*/
void Dice::displayRollPercentages()
{
	cout << "Roll Percentages of this dice:" << endl;
	cout << "Percent of zero value rolls (blank sides): " << percentZeroRolls << endl;
	cout << "Percent of one value rolls (side with 1 dot): " << percentOneRolls << endl;
	cout << "Percent of two value rolls (side with 2 dots): " << percentTwoRolls << endl;
	cout << "Percent of three value rolls (side with 3 dots): " << percentThreeRolls << endl;
}

/*
Rolls a dice returning values 0 to 3 (0 has 3 sides, 1 to 3 each have 1 side, out of 6 possible sides). 
Used for reinforcement during the final conquest attempt in a turn.
*/
int Dice::reinforcementRoll()
{

	srand(time(NULL)); 

	switch (rand() % 6 + 1) {
		case 1:
			numZeroRolls++;
			numTotalRolls++;
			percentZeroRolls = ((double)numZeroRolls / (double)numTotalRolls) * 100;
			cout << "Player rolled a 0." << endl;
			return 0;

		case 2:
			numZeroRolls++;
			numTotalRolls++;
			percentZeroRolls = ((double)numZeroRolls / (double)numTotalRolls) * 100;
			cout << "Player rolled a 0." << endl;
			return 0;

		case 3:
			numZeroRolls++;
			numTotalRolls++;
			percentZeroRolls = ((double)numZeroRolls / (double)numTotalRolls) * 100;
			cout << "Player rolled a 0." << endl;
			return 0;

		case 4:
			numOneRolls++;
			numTotalRolls++;
			percentOneRolls = ((double)numOneRolls / (double)numTotalRolls) * 100;
			cout << "Player rolled a 1." << endl;
			return 1;

		case 5:
			numTwoRolls++;
			numTotalRolls++;
			percentTwoRolls = ((double)numTwoRolls / (double)numTotalRolls) * 100;
			cout << "Player rolled  a 2." << endl;
			return 2;

		case 6:
			numThreeRolls++;
			numTotalRolls++;
			percentThreeRolls = ((double)numThreeRolls / (double)numTotalRolls) * 100;
			cout << "Player rolled a 3." << endl;
			return 3;
	}
}

