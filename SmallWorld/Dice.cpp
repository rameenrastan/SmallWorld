#include "stdafx.h"
#include "Dice.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>


Dice::Dice()
{
	value = 0;
}


Dice::~Dice()
{
}

int Dice::reinforcementRoll()
{
	/* initialize random seed: */
	srand(time(NULL));  //

	/* generate number between 1 and 10: */
	value = rand() % 6 + 1;
	if (value == 3) {
		return value;
	}
	else 
		return 0;
		
		
}
