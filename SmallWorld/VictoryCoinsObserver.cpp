#include "stdafx.h"
#include "VictoryCoinsObserver.h"


VictoryCoinsObserver::VictoryCoinsObserver()
{
}


VictoryCoinsObserver::~VictoryCoinsObserver()
{
}

void VictoryCoinsObserver::update()
{

	//Victory Coins Observer Decorator: Displays the Victory Coins earned by each player

	GameStatisticsObserverDecorator::update();
	

	GameLoop* subject = decoratedObserver->getSubject();
	vector<Player*> players = subject->getPlayers();

	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getVictoryCoinCount() > victoryCoins[i])
		{
			cout << players[i]->getPlayerName() << " has scored " << players[i]->getVictoryCoinCount() - victoryCoins[i] << " Victory Coins." << endl;
			victoryCoins[i] = players[i]->getVictoryCoinCount();
		}
	}

}
