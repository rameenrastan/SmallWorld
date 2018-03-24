#include "stdafx.h"
#include "GameLoop.h"


//initializes a game based on user input settings (map name, number of players, etc.)
void GameLoop::initializeGame()
{
	int numPlayers;
	string mapFileName; 
	MapLoader ml;

	cout << "Starting a game of Small World!" << endl;
	cout << "Please enter the name of the map:" << endl;
	cin >> mapFileName;

	while (!ml.loadMap(mapFileName).isConnected())
	{
	cout << "This map is invalid! Please enter a valid map:" << endl;
	cin >> mapFileName;
	}
	gameMap = ml.loadMap(mapFileName);
	cout << "Please enter the number of players in the game (2 to 5):" << endl;
	cin >> numPlayers;
	while (numPlayers < 2 || numPlayers > 5)
	{
		cout << "Invalid player count, please select 2 to 5 Players:" << endl;
		cin >> numPlayers;
	}
	switch (numPlayers)
	{
	case 2: 
		cout << "2 Player Mode Selected." << endl;
 		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		numTurns = 10;
		break;
	case 3:
		cout << "3 Player Mode Selected." << endl;
		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		players.push_back(new Player("Player3"));
		numTurns = 10;
		break;
	case 4:
		cout << "4 Player Mode Selected." << endl;
		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		players.push_back(new Player("Player3"));
		players.push_back(new Player("Player4"));
		numTurns = 9;
		break;
	case 5:
		cout << "5 Player Mode Selected." << endl;
		players.push_back(new Player("Player1"));
		players.push_back(new Player("Player2"));
		players.push_back(new Player("Player3"));
		players.push_back(new Player("Player4"));
		players.push_back(new Player("Player5"));
		numTurns = 8;
		break;
	}

	cout << "Initializing all game pieces..." << endl;
	gameDeck = GameDeck();
	//gameDeck.showDeckInfo();
	
}

//Places Mountain and Lost Tribe tokens on all regions on the game map containing these symbols
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

//Start Up Phase (places turn marker to start, places mountain/lost tribe tokens, distributes victory coins, determines turn order, generates 6 race/power combos)
void GameLoop::startUpPhase()
{
	cout << "Placing the Game Turn Marker to the starting position." << endl;
	gameTurnMarker = 1;

	placeMountainAndLostTribe();
	distributeInitialVictoryCoins();
	determineTurnOrder();
	generateRaceCombo();
}

//distributes 5 victory coins to all players on start up
void GameLoop::distributeInitialVictoryCoins()
{
	cout << "Distributing initial victory coins to all players..." << endl;
	for (auto & player : players)
	{
		cout << "Distributing 5 Victory Coins to player " << (*player).getPlayerName() << endl;
		(*player).setVictoryCoinCount(5);
	}
}

//determines the turn order of the game (based on whoever has the most pointed ears)
void GameLoop::determineTurnOrder()
{
	string playerName;
	cout << "\nWhich player has the most pointed ears?" << endl;
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

//generates 6 Race/Power combos
void GameLoop::generateRaceCombo()
{
	vector<Banner> banners;
		
	banners.push_back(Banner(Banner::AMAZONS));
	banners.push_back(Banner(Banner::DWARVES));
	banners.push_back(Banner(Banner::ELVES));
	banners.push_back(Banner(Banner::GHOULS));
	banners.push_back(Banner(Banner::RATMEN));
	banners.push_back(Banner(Banner::SKELETONS));
	banners.push_back(Banner(Banner::SORCERERS));
	banners.push_back(Banner(Banner::TRITONS));
	banners.push_back(Banner(Banner::GIANTS));
	banners.push_back(Banner(Banner::HALFLINGS));
	banners.push_back(Banner(Banner::HUMANS));
	banners.push_back(Banner(Banner::ORCS));
	banners.push_back(Banner(Banner::TROLLS));
	banners.push_back(Banner(Banner::WIZARDS));

	vector<Badge> badges;

	badges.push_back(Badge(Badge::ALCHEMIST));
	badges.push_back(Badge(Badge::BERSERK));
	badges.push_back(Badge(Badge::BIVOUACKING));
	badges.push_back(Badge(Badge::COMMANDO));
	badges.push_back(Badge(Badge::DIPLOMAT));
	badges.push_back(Badge(Badge::DRAGONMASTER));
	badges.push_back(Badge(Badge::FLYING));
	badges.push_back(Badge(Badge::FOREST));
	badges.push_back(Badge(Badge::FORTIFIED));
	badges.push_back(Badge(Badge::HEROIC));
	badges.push_back(Badge(Badge::HILL));
	badges.push_back(Badge(Badge::MERCHANT));
	badges.push_back(Badge(Badge::MOUNTED));
	badges.push_back(Badge(Badge::PILLAGING));
	badges.push_back(Badge(Badge::SEAFARING));
	badges.push_back(Badge(Badge::SPIRIT));
	badges.push_back(Badge(Badge::STOUT));
	badges.push_back(Badge(Badge::SWAMP));
	badges.push_back(Badge(Badge::UNDERWORLD));
	badges.push_back(Badge(Badge::WEALTHY));

	srand(time(0));
	random_shuffle(begin(banners), end(banners));
	random_shuffle(begin(badges), end(badges));

	pair <Banner, Badge> combo;
	cout << "\nRace/Power combos available:" << endl;
	for (int i = 0; i < 14; i++) {
		combo = make_pair(banners[i], badges[i]);
		pairs.push_back(combo);
	}
	for (int i = 0; i < 6; i++){
		cout << i << ". " << pairs[i].second.getBadgeName() << " " << pairs[i].first.getRaceName() << endl;
		}


}

//allows a user to select a Race/Power combo (which then calls picks_race in player class)
void GameLoop::playerPicksRace(Player* player)
{
	cout << "\nPlease type the number of the race power combo you would like to select:" << endl;
	int option;
	cin >> option;
	switch (option) {
		case 0:
			player->picks_race(pairs[0].first, pairs[0].second, &gameDeck);
			cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 0);
			break;
		case 1:
			player->picks_race(pairs[1].first, pairs[1].second, &gameDeck);
			cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 1);
			break;
		case 2:
			player->picks_race(pairs[2].first, pairs[2].second, &gameDeck);
			cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 2);
			break;
		case 3:
			player->picks_race(pairs[3].first, pairs[3].second, &gameDeck);
			cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 3);
			break;
		case 4:
			player->picks_race(pairs[4].first, pairs[4].second, &gameDeck);
			cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 4);
			break;
		case 5:
			player->picks_race(pairs[5].first, pairs[5].second, &gameDeck);
			cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 5);
			break;
	}
	cout << "\nUpdated list of race power combos: " << endl;
	for (int i = 0; i < 6; i++) {
		cout << i << ". " << pairs[i].second.getBadgeName() << " " << pairs[i].first.getRaceName() << endl;
	}
}

//allows a player to go In Decline and select a new Power/Race combo
void GameLoop::playerInDecline(Player * player)
{
	cout << "\nIn Decline: Please type the number of the new race power combo you would like to select:" << endl;
	int option;
	for (int i = 0; i < 6; i++) {
		cout << i << ". " << pairs[i].second.getBadgeName() << " " << pairs[i].first.getRaceName() << endl;
	}
	cin >> option;
	switch (option) {
	case 0:
		player->decline(pairs[0].first, pairs[0].second, &gameDeck);
		cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
		pairs.erase(pairs.begin() + 0);
		break;
	case 1:
		player->decline(pairs[1].first, pairs[1].second, &gameDeck);
		cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
		pairs.erase(pairs.begin() + 1);
		break;
	case 2:
		player->decline(pairs[2].first, pairs[2].second, &gameDeck);
		cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
		pairs.erase(pairs.begin() + 2);
		break;
	case 3:
		player->decline(pairs[3].first, pairs[3].second, &gameDeck);
		cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
		pairs.erase(pairs.begin() + 3);
		break;
	case 4:
		player->decline(pairs[4].first, pairs[4].second, &gameDeck);
		cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
		pairs.erase(pairs.begin() + 4);
		break;
	case 5:
		player->decline(pairs[5].first, pairs[5].second, &gameDeck);
		cout << "You have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
		pairs.erase(pairs.begin() + 5);
		break;
	}
	cout << "Updated list of race power combos: " << endl;
	for (int i = 0; i < 6; i++) {
		cout << i << ". " << pairs[i].second.getBadgeName() << " " << pairs[i].first.getRaceName() << endl;
	}
}

//main game loop (logic of looping for first turn and following turns)
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
			cout << (*player).getPlayerName() << " must pick a race/power combo." << endl;
			playerPicksRace(player);
			cout << (*player).getPlayerName() << " must conquer some regions." << endl;

			gameMap.displayRegionList();

			while ((*player).getTokenCount() > 0)
			{
				string choice;
				cout << "Which region would you like to conquer? (type N to end conquest)" << endl;
				cin >> choice;

				if (choice == "N")
				{
					cout << "Conquest ended!" << endl;
					break;
				}
				else {
					for (auto & region : gameMap.regions)
					{
						if (region->getRegionName() == choice)
						{
							(*player).conquers(region, true);
						}
					}
				}

			}
			(*player).scores(&gameDeck);
		}
		cout << "First Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	//FOLLOWING TURNS
	while (gameTurnMarker <= numTurns)
	{
		for (auto & player : players)
		{
			followingTurn(player);
		}
		cout << "Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	cout << "Game Finished! The player with the highest number of Victory Coins is the winner!" << endl;
}

//gives user options in following turns
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
			//conquer options

			break;

		case 2:
			//put in decline
			break;
	}

}

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}


