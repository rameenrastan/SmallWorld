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

	/*GameLoop* subject = decoratedObserver->getSubject();
	vector<Player*> players = subject->getPlayers();

	int numRegions = ((subject->gameMap).regions).size();

	for (auto & player : players)
	{
		int ownedRegions = (player->ownedRegions).size();
		cout << "Percentage of the World Map owned by " << player->getPlayerName() << ": " << ((double)ownedRegions / (double)numRegions) * 100 << "%" << endl;
	}*/

}
