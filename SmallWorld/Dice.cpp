#include "stdafx.h"
#include "Dice.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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

void Dice::displayRollPercentages()
{
	cout << "Roll Percentages of this dice:" << endl;
	cout << "Percent of zero value rolls (blank sides): " << percentZeroRolls << endl;
	cout << "Percent of one value rolls (side with 1 dot): " << percentOneRolls << endl;
	cout << "Percent of two value rolls (side with 2 dots): " << percentTwoRolls << endl;
	cout << "Percent of three value rolls (side with 3 dots): " << percentThreeRolls << endl;
}

int Dice::reinforcementRoll()
{

	srand(time(NULL)); 

	int value = rand() % 6 + 1;
	switch (value) {
		case 1:
			numZeroRolls++;
			numTotalRolls++;
			percentZeroRolls = ((double)numZeroRolls / (double)numTotalRolls) * 100;
			return 0;

		case 2:
			numZeroRolls++;
			numTotalRolls++;
			percentZeroRolls = ((double)numZeroRolls / (double)numTotalRolls) * 100;
			return 0;

		case 3:
			numZeroRolls++;
			numTotalRolls++;
			percentZeroRolls = ((double)numZeroRolls / (double)numTotalRolls) * 100;
			return 0;

		case 4:
			numOneRolls++;
			numTotalRolls++;
			percentOneRolls = ((double)numOneRolls / (double)numTotalRolls) * 100;
			return 1;

		case 5:
			numTwoRolls++;
			numTotalRolls++;
			percentTwoRolls = ((double)numTwoRolls / (double)numTotalRolls) * 100;
			return 2;

		case 6:
			numThreeRolls++;
			numTotalRolls++;
			percentThreeRolls = ((double)numThreeRolls / (double)numTotalRolls) * 100;
			return 3;
	}
}
