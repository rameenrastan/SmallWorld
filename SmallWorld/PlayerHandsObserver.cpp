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

	//Player Hands Observer Decorator: Displays the cards owned by every player

	GameLoop* subject = decoratedObserver->getSubject();
	vector<Player*> players = subject->getPlayers();

	for (int i = 0; i < players.size(); i++)
	{
		//checks if player has updated their hand (Race/Power combo)
		if (players[i]->getRaceName() != "" && playerHands[i] != players[i]->getRaceName() + " " + players[i]->getBadgeName())
		{
			//if update to player's hand occurs, update the view
			playerHands[i] = players[i]->getRaceName() + " " + players[i]->getBadgeName();
			updateRequired = true;
		}
	}

	//display every player's hand when an update occurs
	if (updateRequired)
	{
		for (int i = 0; i < players.size(); i++)
		{
			//if update to player's hand occurs, update the view
			cout << players[i]->getPlayerName() << "'s hand: " << playerHands[i] << endl;
			updateRequired = false;
		}
	}
}
