#include "stdafx.h"
#include "PhaseObserver.h"

PhaseObserver::PhaseObserver()
{

}

PhaseObserver::PhaseObserver(GameLoop * subj)
{
	subject = subj;
	subject->attach(this);
}


PhaseObserver::~PhaseObserver()
{
}

void PhaseObserver::update()
{
	string phase = subject->getPhase();
	int turnNumber = subject->getTurn();
	Player* player = subject->getCurrentPlayer();

	cout << "Turn " << turnNumber << ": " << player->getPlayerName() << " " << phase << endl;
	
	if (phase == "Picks Race")
	{
		cout << player->getPlayerName() << " updated race/power combo: " << endl; 
	}
	else if (phase == "Conquer Regions")
	{
		cout << player->getPlayerName() << " updated list of conquered regions: " << endl;
		for (auto & region : player->ownedRegions)
		{
			cout << region->getRegionName() << " ";
		}

		cout << endl;
	}
	else if (phase == "Scores")
	{
		cout << player->getPlayerName() << " updated number of Victory Coins: " << player->getVictoryCoinCount() << endl;
 	}
	
}

