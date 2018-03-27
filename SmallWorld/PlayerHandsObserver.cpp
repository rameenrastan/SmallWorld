#include "stdafx.h"
#include "PlayerHandsObserver.h"


PlayerHandsObserver::PlayerHandsObserver()
{
}


PlayerHandsObserver::~PlayerHandsObserver()
{
}

void PlayerHandsObserver::update()
{
	GameStatisticsObserverDecorator::update();
	cout << "Player Hands TEST" << endl;
	//Player Hands Observer Decorator: Displays the cards owned by every player

	//GameLoop* subject = decoratedObserver->getSubject();
	//vector<Player*> players = subject->getPlayers();

	//for (auto & player : players)
	//{
	//	cout << player->getPlayerName() << " has " << player->getVictoryCoinCount() << " Victory Coins." << endl;
	//}
}
