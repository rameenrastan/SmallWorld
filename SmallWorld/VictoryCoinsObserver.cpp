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
	
	for (auto & player : players)
	{
		cout << player->getPlayerName() << " has " << player->getVictoryCoinCount() << " Victory Coins." << endl;
	}

}
