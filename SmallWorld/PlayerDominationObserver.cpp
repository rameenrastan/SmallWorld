#include "stdafx.h"
#include "PlayerDominationObserver.h"


PlayerDominationObserver::PlayerDominationObserver()
{
}


PlayerDominationObserver::~PlayerDominationObserver()
{
}

void PlayerDominationObserver::update()
{

	GameStatisticsObserverDecorator::update();

	//Player Domination Observer Decorator: Display percentage of regions owned by each player

	GameLoop* subject = decoratedObserver->getSubject();
	vector<Player*> players = subject->getPlayers();

	int numRegions = ((subject->gameMap).regions).size();

	//updates vector of owned region percentages and checks if a view update is required (if a player conquered or lost a region)
	for (int i=0; i<players.size(); i++)
	{
		int ownedRegions = (players[i]->ownedRegions).size();
		double percent = round(((double)ownedRegions / (double)numRegions) * 100);
		if (percent != regionsOwnedPercentages[i])
		{
			regionsOwnedPercentages[i] = percent;
			updateRequired = true;
		}
	}

	//if user(s) conquered/lost a region: must update the view
	if (updateRequired)
	{
		cout << "Players Domination View: Percentage of World controlled by each player" << endl;
		for (int i = 0; i < players.size(); i++)
		{
			cout << players[i]->getPlayerName() << ":";

			if (regionsOwnedPercentages[i] != 0) {
				int numStars = round(regionsOwnedPercentages[i] / 10);

				for (int j = 0; j < numStars; j++)
				{
					cout << "*";
				}
			}
			cout << "(" << regionsOwnedPercentages[i] << "%)" << endl;
		}
		updateRequired = false;
	}
}
