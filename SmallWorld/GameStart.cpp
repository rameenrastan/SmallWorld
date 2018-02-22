#include "stdafx.h"
#include "GameStart.h"


void GameStart::startGame()
{
	int numPlayers;
	string mapFileName; 
	MapLoader ml;
	Player* p1;
	Player* p2;
	Player* p3;
	Player* p4;
	Player* p5;

	cout << "Starting a &game of Small World!" << endl;
	cout << "Please enter the name of the map:" << endl;
	cin >> mapFileName;
	Map map = ml.loadMap(mapFileName);
	while (!map.isConnected())
	{
	cout << "This map is invalid! Please enter a valid map:" << endl;
	cin >> mapFileName;
	Map map = ml.loadMap(mapFileName);
	}
	cout << "Please enter the number of players in the game:" << endl;
	cin >> numPlayers;

	Map* map_ptr = &map;

	switch (numPlayers)
	{
	case 2: 
		 p1 = &Player("Player 1");
		 p2 = &Player("Player 2");
	case 3:
		 p1 = &Player("Player 1");
		 p2 = &Player("Player 2");
		 p3 = &Player("Player 3");
	case 4:
		 p1 = &Player("Player 1");
		 p2 = &Player("Player 2");
		 p3 = &Player("Player 3");
		 p4 = &Player("Player 4");
	case 5:
		 p1 = &Player("Player 1");
		 p2 = &Player("Player 2");
		 p3 = &Player("Player 3");
		 p4 = &Player("Player 4");
		 p5 = &Player("Player 5");
	}
	
}

GameStart::GameStart()
{
}


GameStart::~GameStart()
{
}


