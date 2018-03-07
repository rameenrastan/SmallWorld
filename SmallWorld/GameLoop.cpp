#include "stdafx.h"
#include "GameLoop.h"


void GameLoop::initializeGame()
{
	int numPlayers;
	string mapFileName; 
	MapLoader ml;

	cout << "Starting a &game of Small World!" << endl;
	cout << "Please enter the name of the map:" << endl;
	cin >> mapFileName;

	while (!ml.loadMap(mapFileName).isConnected())
	{
	cout << "This map is invalid! Please enter a valid map:" << endl;
	cin >> mapFileName;
	}
	gameMap = ml.loadMap(mapFileName);
	cout << "Please enter the number of players in the game:" << endl;
	cin >> numPlayers;

	switch (numPlayers)
	{
	case 2: 
		cout << "2 Player Mode Selected." << endl;
 		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		break;
	case 3:
		cout << "3 Player Mode Selected." << endl;
		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		players.push_back(new Player("Player3"));
		break;
	case 4:
		cout << "4 Player Mode Selected." << endl;
		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		players.push_back(new Player("Player3"));
		players.push_back(new Player("Player4"));
		break;
	case 5:
		cout << "5 Player Mode Selected." << endl;
		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		players.push_back(new Player("Player3"));
		players.push_back(new Player("Player4"));
		players.push_back(new Player("Player5"));
		break;
	}

	cout << "Initializing all game pieces..." << endl;
	gameDeck = GameDeck();
	gameDeck.showDeckInfo();
	
}

void GameLoop::placeMountainAndLostTribe()
{
	for (auto & region : gameMap.regions)
	{
		if ((*region).getSymbol() == "lost_tribe")
		{	
			if (gameDeck.getNumLostTribe() > 0)
			{
				cout << "Placing a Lost Tribe token on region " << (*region).getRegionName() << endl;
				(*region).placeLostTribe();
				gameDeck.decrementLostTribes();
			}
			else {
				cout << "There are no more remaining Lost Tribe pieces!" << endl;
			}

		}
		else if ((*region).getSymbol() == "mountain")
		{
			if (gameDeck.getNumMountain() > 0)
			{
				cout << "Placing a Mountain token on region " << (*region).getRegionName() << endl;
				(*region).placeMountain();
				gameDeck.decrementLostTribes();
			}
			else {
				cout << "There are no more remaining Lost Tribe pieces!" << endl;
			}
		}
	}

}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}


