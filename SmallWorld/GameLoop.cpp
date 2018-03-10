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

void GameLoop::startUpPhase()
{
	cout << "Placing the Game Turn Marker to the starting position." << endl;
	gameTurnMarker = 1;

	placeMountainAndLostTribe();
	distributeInitialVictoryCoins();
}

void GameLoop::distributeInitialVictoryCoins()
{
	cout << "Distributing initial victory coins to all players..." << endl;
	for (auto & player : players)
	{
		cout << "Distributing 5 Victory Coins to player " << (*player).getPlayerName() << endl;
		(*player).setVictoryCoinCount(5);
	}
}

void GameLoop::determineTurnOrder()
{
	string playerName;
	cout << "Which player has the most pointed ears?" << endl;
	cin >> playerName;

	for (int i = 0; i < players.size(); i++)
	{
		if ((*players[i]).getPlayerName() == playerName)
		{
			rotate(players.begin(), players.begin() + i, players.end());
		}
	}

	cout << playerName << " has the most pointed ears, and therefore starts each turn!" << endl;
	cout << "This is the determined turn order:" << endl;

	for (int i = 0; i < players.size(); i++)
	{
		cout << i+1 << " " << (*players[i]).getPlayerName() << endl;
	}

}

void GameLoop::mainLoop()
{
	//FIRST TURN
	if (gameTurnMarker == 1)
	{
		cout << "First Turn: Each Player will pick a Race/Special Power Combo, Conquer Some Regions, and score some Victory Coins." << endl;
		for (auto & player : players)
		{
			cout << (*player).getPlayerName() << "'s turn." << endl;
			//hard coded empty behavior for picking race/power combo, conquering regions, and gaining victory coins.
			cout << (*player).getPlayerName() << " picks a race/power combo." << endl;
			cout << (*player).getPlayerName() << " conquers some regions." << endl;
			cout << (*player).getPlayerName() << " scores some Victory coins." << endl;
		}
		cout << "First Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	//FOLLOWING TURNS
	while (gameTurnMarker <= 8)
	{
		for (auto & player : players)
		{
			//followingTurn(*player)
		}
		cout << "Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}
}

void GameLoop::followingTurn(Player* player)
{
	cout << "Select an option:" << endl;
	cout << "1. Expand the reach of your race through new conquests." << endl;
	cout << "2. Put your race In Decline to select a new one." << endl;

	int choice;
	cin >> choice;

	string regionName;

	switch(choice)
	{
		case 1:
			cout << "You currently have " << (*player).getTokenCount() << endl;
			cout << (*player).getPlayerName() << endl;
			cout << "Please write the name of the region you wish to conquer from the list:" << endl;
			gameMap.displayRegionList();
			cin >> regionName;

			for (auto & region : gameMap.regions)
			{
				if ((*region).getRegionName() == regionName)
				{
					(*player).conquers(region, false);
				}
			}

			break;

		case 2:
			break;
	}

}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}


