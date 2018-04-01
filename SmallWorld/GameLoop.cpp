#include "stdafx.h"
#include "GameLoop.h"
#include "Aggressive.h"

//initializes a game based on user input settings (map name, number of players, etc.)
void GameLoop::initializeGame()
{
	phase = "Initializing Game";

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
	phase = "Start Up Phase";

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

			
				playerPicksRace(player);    // <------ UNCOMMENT THIS AFTER FOR NON STRATEGY GAME
				//	notify();					<----THIS TOO

				phase = "Conquer Regions";
				cout << (*player).getPlayerName() << " must conquer some regions." << endl;

				gameMap.displayRegionList();

				//	currentPlayer->executeStrategy(&gameMap, player, phase, this, &gameDeck);



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
				//	notify();

			//		phase = "Scores";
				(*player).scores(&gameDeck);
				//		notify();
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
				}
			}
			
		}
		cout << "First Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	//FOLLOWING TURNS
	while (gameTurnMarker <= numTurns)
	{
		for (auto & player : players)
		{
				followingTurn(player);
				player->scores(&gameDeck);
			
		}

		cout << "Turn finished... Game Turn Marker is moving to position " << ++gameTurnMarker << endl;
	}

	cout << "Game Finished! The player with the highest number of Victory Coins is the winner!" << endl;
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
							(*player).abandonRegion(region);
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
					playerInDecline(player);
					playerTurn = false;
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

GameLoop::GameLoop()
{
}

GameLoop::~GameLoop()
{
}


