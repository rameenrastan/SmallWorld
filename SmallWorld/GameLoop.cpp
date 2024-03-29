#include "stdafx.h"
#include "GameLoop.h"
#include "GameStatisticsObserver.h"
#include "PlayerDominationObserver.h"
#include "PlayerHandsObserver.h"
#include "VictoryCoinsObserver.h"
#include "Aggressive.h"
#include "Defensive.h"
#include "Moderate.h"
#include "Random.h"

void GameLoop::addDecorator()
{
	cout << "Would you like to add a decorator to the Game Statistics Observer?" << endl;
	cout << "1. Add Player Domination Observer Decorator" << endl;
	cout << "2. Add Player Hands  Observer Decorator" << endl;
	cout << "3. Add Victory Coins Observer Decorator" << endl;
	cout << "4. Remove Current Decorator" << endl;
	cout << "5. No." << endl;
	cout << "6. No (and don't ask again!)" << endl;

	int choice;
	cin >> choice;

	if (choice == 1)
	{
		//decorates Game Statistics Observer with Player Domination Observer
		observers[1] = new GameStatisticsObserver(this);
		observers[1] = new PlayerDominationObserver(dynamic_cast<GameStatisticsObserver*>(observers[1]));
	}
	else if(choice == 2)
	{
		//decorates Game Statistics Observer with Player Hands Observer
		observers[1] = new GameStatisticsObserver(this);
		observers[1] = new PlayerHandsObserver(dynamic_cast<GameStatisticsObserver*>(observers[1]));
	}
	else if (choice == 3)
	{
		//decorates Game Statistics Observer with Victory Coins Observer
		observers[1] = new GameStatisticsObserver(this);
		observers[1] = new VictoryCoinsObserver(dynamic_cast<GameStatisticsObserver*>(observers[1]));
	}
	else if (choice == 4)
	{
		//removes current decoration of Game Statistics Observer
		observers[1] = new GameStatisticsObserver(this);
	}
	else if (choice == 6)
	{
		//will not ask user if they wish to decorate the Game Statistics Observer anymore
		decoratorRequest = false;
	}

}

//initializes a game based on user input settings (map name, number of players, etc.)
void GameLoop::initializeGame()
{
	phase = "Initializing Game";

	int numPlayers;
	string mapFileName;
	MapLoader ml;


	cout << "Starting a game of Small World!" << endl;
	cout << "Please enter the name of the map: \n(valid.map for 2 players, 3pvalid.map for 3 players, 4pvalid.map for 4 players, 5pvalid.map for 5 players)" << endl;
	cin >> mapFileName;
	
	/*	Exception handling, throws error here if map file name is not valid. Try/Catch block in main method (SmallWorld.cpp) to prevent program from terminating 
		after throwing exception.(else statement is where error is thrown ) */

	if (mapFileName == "valid.map" || mapFileName == "2pvalid.map" || mapFileName == "3pvalid.map" || mapFileName == "4pvalid.map" || mapFileName == "5pvalid.map") {

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
	else {
		throw "Error";
	}
	
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
	phase = "Start Up Phase";

	cout << "Placing the Game Turn Marker to the starting position." << endl;
	gameTurnMarker = 1;

	placeMountainAndLostTribe();
	distributeInitialVictoryCoins();
	determineTurnOrder();
	generateRaceCombo();
}


//Start Up Phase for Tournament 
void GameLoop::startUpPhaseTournament()
{

	cout << "Placing the Game Turn Marker to the starting position." << endl;
	gameTurnMarker = 1;

	placeMountainAndLostTribe();
	distributeInitialVictoryCoins();
	gameMap.displayRegionList();

	cout << "\nPlayer1 will start each turn!" << endl;
	cout << "This is the determined turn order:" << endl;

	for (int i = 0; i < players.size(); i++)
	{
		cout << i + 1 << " " << (*players[i]).getPlayerName() << endl;
	}

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
			cout << "\nYou have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 0);
			break;
		case 1:
			player->picks_race(pairs[1].first, pairs[1].second, &gameDeck);
			cout << "\nYou have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 1);
			break;
		case 2:
			player->picks_race(pairs[2].first, pairs[2].second, &gameDeck);
			cout << "\nYou have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 2);
			break;
		case 3:
			player->picks_race(pairs[3].first, pairs[3].second, &gameDeck);
			cout << "\nYou have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 3);
			break;
		case 4:
			player->picks_race(pairs[4].first, pairs[4].second, &gameDeck);
			cout << "\nYou have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
			pairs.erase(pairs.begin() + 4);
			break;
		case 5:
			player->picks_race(pairs[5].first, pairs[5].second, &gameDeck);
			cout << "\nYou have chosen: " << pairs[option].second.getBadgeName() << " " << pairs[option].first.getRaceName() << endl;
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
			if (decoratorRequest)
			{
				addDecorator();
			}

			char strategyChoice;
			currentPlayer = player;

			cout << player->getPlayerName() << "'s turn." << endl;
			cout << "Please select a strategy for " << player->getPlayerName() << " to automatically execute. Type N if you do not want to execute any strategies." << endl;
			cout << "  1. Aggressive Strategy (chooses power combo and conquers as many regions as possible)" << endl;
			cout << "  2. Defensive Strategy (chooses power combo and conquers regions owned by other players)" << endl;
			cout << "  3. Moderate Strategy (chooses power combo and plays a mix of aggressive and defensive strategy)" << endl;
			cout << "  4. Random Strategy (chooses power combo and randomly conquers regions/randomly puts race in decline)" << endl;

			cin >> strategyChoice;

			if (strategyChoice == 'N' || strategyChoice == 'n') {
				cout << "No strategy selected for " << player->getPlayerName() << ", the game will be played manually." << endl;

				cout << (*player).getPlayerName() << " must pick a race/power combo." << endl;

				phase = "Picks Race";
	
				playerPicksRace(player); 
				notify();

				phase = "Conquer Regions";
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
								notify();
							}
						}
					}

				}
				notify();

			    phase = "Scores";
				(*player).scores(&gameDeck);
				notify();
			}
			else {
				switch (strategyChoice)
				{
				case '1': //Aggressive
					player->setStrategy(new Aggressive());
					cout << "Aggressive strategy chosen..." << endl;
					player->setHasStrategy(true);
					player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
					player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
					break;
				case '2': //Defensive
					player->setStrategy(new Defensive());
					cout << "Defensive strategy chosen..." << endl;
					player->setHasStrategy(true);
					player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
					player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
					break;
				case '3': //Moderate
					player->setStrategy(new Moderate());
					cout << "Moderate strategy chosen..." << endl;
					player->setHasStrategy(true);
					player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
					player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
					break;
				case '4': //Random
					player->setStrategy(new Random());
					cout << "Random strategy chosen..." << endl;
					player->setHasStrategy(true);
					srand(time(0));
					player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
					player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
					break;
				}
			}
			
		}
		cout << "First Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	//FOLLOWING TURNS
	while (gameTurnMarker <= numTurns)
	{
		notify();
		for (auto & player : players)
		{
			if (decoratorRequest)
			{
				addDecorator();
			}
			followingTurn(player);
			player->scores(&gameDeck);
			notify();
			
		}

		cout << "Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	int max=0;
	string winner = "";

	for (auto & player : players)
	{
		if (player->getVictoryCoinCount() > max)
		{
			max = player->getVictoryCoinCount();
			winner = player->getPlayerName();
		}
	}

	cout << "Game Finished! " << winner << " is the winner with " << max << " victory coins!" << endl; 
}

//gives user options in following turns
void GameLoop::followingTurn(Player* player)
{
	cout << (*player).getPlayerName() << "'s turn:" << endl;
	player->readyTroops();
	if (player->getHasStrategy()){
		player->executeStrategy(&gameMap, player, "Following Turn", this, &gameDeck);
	}
	else {
		bool playerTurn = true;
		while (playerTurn) {
			cout << "Please choose what you would like to do:" << endl;
			cout << "1. Conquer new regions." << endl;
			cout << "2. Abandon regions." << endl;
			cout << "3. Put your race in decline and select a new one (ends your turn)." << endl;
			cout << "4. Redeploy your troops (ends your turn)." << endl;
			cout << "5. Consult summary sheet." << endl;

			char choice;
			string regionName;
			string redeploy;
			string decline;

			cin >> choice;

			switch (choice)
			{
			case '1': //conquer
				phase = "Conquer Regions";
				cout << "You currently have " << (*player).getTokenCount() << " tokens." << endl;
				cout << "Please write the name of the region you wish to conquer from the list: (type N to cancel)" << endl;
				gameMap.displayRegionList();
				cin >> regionName;
				
				if (regionName == "N")
				{
					cout << "Conquest cancelled..." << endl;
					break;
				}
				else {
					for (auto & region : gameMap.regions)
					{
						if (region->getRegionName() == regionName)
						{
							(*player).conquers(region, true);
							notify();
						}
					}
				}
				break;

			case '2': //abandon
				
				if (player->ownedRegions.empty()) {
					cout << "You currently do not own any regions. Abandoning cancelled..." << endl;
					break;
				}
				cout << "Please write the name of the region you wish to abandon? (type N to cancel)" << endl;
				player->displayOwnedRegions();
				cin >> regionName;
				if (regionName == "N")
				{
					cout << "Abandoning cancelled..." << endl;
					break;
				}
				else {
					for (auto & region : player->ownedRegions)
					{
						if (region->getRegionName() == regionName)
						{
							phase = "Abandon Region";
							(*player).abandonRegion(region);
							notify();
						}
					}
				}

				break;

			case '3': //decline
				cout << "You have chosen to decline your race, this action cannot be reversed." << endl;
				cout << "Press any key to proceed, type N to cancel." << endl;
				cin >> decline;
				if (decline == "N") {
					cout << "Decline cancelled..." << endl;
					break;
				}
				else {
					phase = "decline";
					playerInDecline(player);
					playerTurn = false;
					notify();
				}
				break;

			case '4':  //redeploy here/end turn
				cout << "You have chosen to redeploy your troops, your turn will end once you are done." << endl;
				cout << "Press any key to proceed, type N to cancel." << endl;
				cin >> redeploy;
				if (redeploy == "N") {
					cout << "Redeployment cancelled..." << endl;
					break;
				}
				else {
					player->redeployTroops();
					while (playerTurn) {
						cout << "To finish redeploying and end your turn, type Y." << endl;
						cout << "To continue redeploying, press any key." << endl;
						cin >> redeploy;
						if (redeploy == "Y") {
							playerTurn = false;
						}
						else {
							player->redeployTroops();
						}
					}
				}
				break;

			case '5':  //display summary sheet
				player->summarySheet();
				break;
			default:
				cout << "Invalid input, please select again." << endl;
				break;
			}
		}
	}
}

/* Main Loop for tournament (same as MainLoop method above but gets rid of user input) */

void GameLoop::mainLoopTournament()
{
	
	//FIRST TURN
	srand(time(NULL));
	if (gameTurnMarker == 1)
	{

		cout << "\nFirst Turn: Each Player will pick a Race/Special Power Combo, Conquer Some Regions, and score some Victory Coins." << endl;
		for (auto & player : players)
		{
			
			currentPlayer = player;

			cout << player->getPlayerName() << "'s turn." << endl;
			cout << "\nAutomatically selecting a strategy for " << player->getPlayerName() << " at random." << endl;

		
			int x = rand() % 4;
			
			if (x == 0) {  //Aggressive
				player->setStrategy(new Aggressive());
				cout << "Aggressive Strategy chosen..." << endl;
				player->setHasStrategy(true);
				player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
				player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
			}
			else if (x == 1) {  //Defensive
				player->setStrategy(new Defensive());
				cout << "Defensive strategy chosen..." << endl;
				player->setHasStrategy(true);
				player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
				player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
			}
			else if (x == 2) { //Moderate
				player->setStrategy(new Moderate());
				cout << "Moderate Strategy chosen..." << endl;
				player->setHasStrategy(true);
				player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
				player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
			}
			else if (x == 3) { //Random
				player->setStrategy(new Random());
				cout << "Random Strategy chosen..." << endl;
				player->setHasStrategy(true);
				srand(time(0));
				player->executeStrategy(&gameMap, player, "Picks Race", this, &gameDeck);
				player->executeStrategy(&gameMap, player, "Conquer Regions", this, &gameDeck);
			}
			
			

		}
		cout << "First Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}
	//FOLLOWING TURNS
	while (gameTurnMarker <= numTurns)
	{
		notify();
		for (auto & player : players)
		{
			
			followingTurn(player);
			player->scores(&gameDeck);
			notify();

		}

		cout << "Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	int max = 0;
	string winner = "";

	for (auto & player : players)
	{
		if (player->getVictoryCoinCount() > max)
		{
			max = player->getVictoryCoinCount();
			winner = player->getPlayerName();
		}
	}

	cout << "Game Finished! " << winner << " is the winner with " << max << " victory coins!" << endl;

}

/* Two Player tournament executing strategies*/

void GameLoop::twoPlayerTournament()
{
	
	cout << "Two Player Tournament:\nAdding 2 Players to the game..." << endl;
	players.push_back(new Player("Player1"));
	players.push_back(new Player("Player2"));
	numTurns = 10;

	MapLoader ml;
	gameMap = ml.loadMap("valid.map");
	gameDeck = GameDeck();

	startUpPhaseTournament();
	mainLoopTournament();
	
}

/* Three Player tournament executing strategies*/

void GameLoop::threePlayerTournament()
{
	cout << "Three Player Tournament:\nAdding 3 Players to the game..." << endl;
	players.push_back(new Player("Player1"));
	players.push_back(new Player("Player2"));
	players.push_back(new Player("Player3"));
	numTurns = 10;

	MapLoader ml;
	gameMap = ml.loadMap("3pvalid.map");
	gameDeck = GameDeck();

	startUpPhaseTournament();
	mainLoopTournament();
}

/* Four Player tournament executing strategies*/

void GameLoop::fourPlayerTournament()
{
	cout << "Four Player Tournament:\nAdding 4 Players to the game..." << endl;
	players.push_back(new Player("Player1"));
	players.push_back(new Player("Player2"));
	players.push_back(new Player("Player3"));
	players.push_back(new Player("Player4"));
	numTurns = 9;

	MapLoader ml;
	gameMap = ml.loadMap("4pvalid.map");
	gameDeck = GameDeck();

	startUpPhaseTournament();
	mainLoopTournament();
}


/* Five Player tournament executing strategies*/

void GameLoop::fivePlayerTournament()
{
	cout << "Fiver Player Tournament:\nAdding 5 Players to the game..." << endl;
	players.push_back(new Player("Player1"));
	players.push_back(new Player("Player2"));
	players.push_back(new Player("Player3"));
	players.push_back(new Player("Player4"));
	players.push_back(new Player("Player5"));
	numTurns = 8;

	MapLoader ml;
	gameMap = ml.loadMap("5pvalid.map");
	gameDeck = GameDeck();

	startUpPhaseTournament();
	mainLoopTournament();
}

GameLoop::GameLoop()
{
	decoratorRequest = true;
}

GameLoop::~GameLoop()
{
}


