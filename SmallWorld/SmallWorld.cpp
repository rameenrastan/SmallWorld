// SmallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Map.h"
#include "Region.h"
#include "MapLoader.h"
#include "Player.h"
#include "Dice.h"
#include "GameDeck.h"
#include <time.h>      
#include "GameLoop.h"
#include "PhaseObserver.h"
#include "GameStatisticsObserver.h"
#include "VictoryCoinsObserver.h"
#include "PlayerHandsObserver.h"
#include "PlayerDominationObserver.h"

using namespace std;


void gameStartDriver()
{
	GameLoop gl;
	gl.initializeGame();
}

void startUpPhaseDriver()
{
	GameLoop gl;
	gl.initializeGame();
	gl.startUpPhase();
}

void pickRaceDriver()
{
	GameLoop gl;
	gl.initializeGame();
	gl.startUpPhase();
	gl.playerPicksRace(gl.players[0]);

}

void designPatternDriver()
{
	
	GameLoop* gl = new GameLoop();
	PhaseObserver* obs = new PhaseObserver(gl);
	GameStatisticsObserver *gs = new GameStatisticsObserver(gl);
	
	gl->initializeGame();
	gl->startUpPhase();
	gl->mainLoop();
}
void tournamentDriver()
{
	
	char input;
	GameLoop* gl = new GameLoop();
	cout << "\nSmall World Tournament" << endl;
	cout << "Please choose which tournament to play:" << endl;
	cout << "2. Two Player Tournament" << endl;
	cout << "3. Three Player Tournament" << endl;
	cout << "4. Four Player Tournament" << endl;
	cout << "5. Five Player Tournament" << endl;
	cin >> input;
	switch (input)
	{
	case '2':
		gl->twoPlayerTournament();
		break;
	case '3':
		gl->threePlayerTournament();
		break;
	case '4':
		gl->fourPlayerTournament();
		break;
	case '5':
		gl->fivePlayerTournament();
		break;
	default:
		cout << "Invalid input, please select again." << endl;
		break;
	}
}

void conquersSomeRegionsDriver()
{
	MapLoader ml;

	//Load Valid (Connected) Map
	Map map = ml.loadMap("valid.map");

	//create Game Deck object
	GameDeck deck;
	GameDeck* gdeck = &deck;

	//create Player object
	Player player("player1");
	Banner banner(Banner::SKELETONS);
	Badge badge(Badge::DRAGONMASTER);

	//placing Lost Tribe and Mountain tokens (this is normally done automatically by startUpPhase in Game Loop class)
	map.regions[1]->placeLostTribe();
	map.regions[2]->placeMountain();
	map.regions[5]->placeMountain();

	//picks a race
	player.picks_race(banner, badge, gdeck);
	
	//player attempts to conquer Region 6 FIRST (invalid - region 6 is not a border region / region with a shore)  
	player.conquers(map.regions[5], false);

	//player attempts to conquer Region 1 FIRST (valid - region is on the border of the map)
	player.conquers(map.regions[0], false);

	//player attempts to conquer Region 4 next (invalid - this is not adjacent to one of his owned regions)
	player.conquers(map.regions[3], false);

	//valid
	player.conquers(map.regions[5], false);
	//valid
	player.conquers(map.regions[2], false);
	//valid
	player.conquers(map.regions[4], false);

	//player has only 1 token left, must now use reinforcement roll (final conquest attempt)
	player.conquers(map.regions[1], true);

	//conquest over: redeploy troops (invalid, too many tokens)
	player.redeployTroops(map.regions[0], map.regions[4], 2);

	//conquest over: redeploy troops (valid)
	player.redeployTroops(map.regions[0], map.regions[4], 1);
}

void scoreDriver() {
	MapLoader ml;

	//Load Valid (Connected) Map
	Map map = ml.loadMap("valid.map");

	//create Game Deck object
	GameDeck deck;
	GameDeck* gdeck = &deck;

	//create Player object
	Player player("player1");
	Banner banner(Banner::SKELETONS);
	Badge badge(Badge::DRAGONMASTER);

	//another race combo to use after declining prev race
	Banner banner1(Banner::AMAZONS);
	Badge badge2(Badge::ALCHEMIST);


	//placing Lost Tribe and Mountain tokens (this is normally done automatically by startUpPhase in Game Loop class)
	map.regions[1]->placeLostTribe();
	map.regions[2]->placeMountain();
	map.regions[5]->placeMountain();

	//picks a race
	player.picks_race(banner, badge, gdeck);
	//shows player info
	player.summarySheet();

	
	//player attempts to conquer Region 1 FIRST (valid - region is on the border of the map)
	player.conquers(map.regions[0], false);

	//valid
	player.conquers(map.regions[5], false);
	
	//socre vicotry coins
	player.scores(gdeck);
	
	
	player.decline(banner1,badge2,gdeck);  //player declines current race and chooses new race
	//valid
	player.conquers(map.regions[2], false); 
	//valid
	player.conquers(map.regions[4], false);

	//socre vicotry coins and show player info
	player.scores(gdeck);
	player.summarySheet();

}
void followingTurnsDriver()
{
	MapLoader ml;

	//Load Valid (Connected) Map
	Map map = ml.loadMap("valid.map");

	//create Game Deck object
	GameDeck deck;
	GameDeck* gdeck = &deck;

	//create Player object
	Player player("player1");
	Banner banner(Banner::SKELETONS);
	Badge badge(Badge::DRAGONMASTER);

	//placing Lost Tribe and Mountain tokens (this is normally done automatically by startUpPhase in Game Loop class)
	map.regions[1]->placeLostTribe();
	map.regions[2]->placeMountain();
	map.regions[5]->placeMountain();

	//picks a race
	player.picks_race(banner, badge, gdeck);

	//player attempts to conquer Region 6 FIRST (invalid - region 6 is not a border region / region with a shore)  
	player.conquers(map.regions[5], false);

	//player attempts to conquer Region 1 FIRST (valid - region is on the border of the map)
	player.conquers(map.regions[0], false);

	//player attempts to conquer Region 4 next (invalid - this is not adjacent to one of his owned regions)
	player.conquers(map.regions[3], false);

	//valid
	player.conquers(map.regions[5], false);
	//valid
	player.conquers(map.regions[2], false);
	//valid
	player.conquers(map.regions[4], false);

	//conquest over: redeploy troops (invalid, too many tokens)
	player.redeployTroops(map.regions[0], map.regions[4], 2);

	//conquest over: redeploy troops (valid)
	player.redeployTroops(map.regions[0], map.regions[4], 1);

	//abandoning a region
	player.abandonRegion(map.regions[2]);

	//ready troops
	player.readyTroops();

	//player in decline
	player.decline(Banner::RATMEN, Badge::BERSERK, gdeck);
}

void mapDriver()
{
	cout << "Executing map driver:\n" << endl;
	//Case 1: Valid (Connected) Map

	//create Map object
	Map map1;

	//create region objects
	Region r1("Region 1");
	Region r2("Region 2");
	Region r3("Region 3");
	Region r4("Region 4");
	Region r5("Region 5");
	Region r6("Region 6");
	Region r7("Region 7");
	Region r8("Region 8");
	Region r9("Region 9");
	Region r10("Region 10");

	//create region pointers
	Region* r1p = &r1;
	Region* r2p = &r2;
	Region* r3p = &r3;
	Region* r4p = &r4;
	Region* r5p = &r5;
	Region* r6p = &r6;
	Region* r7p = &r7;
	Region* r8p = &r8;
	Region* r9p = &r9;
	Region* r10p = &r10;


	//adds Regions to the map (Regions are Nodes/Vertices on the Graph)
	map1.addRegion(r1p);
	map1.addRegion(r2p);
	map1.addRegion(r3p);
	map1.addRegion(r4p);
	map1.addRegion(r5p);
	map1.addRegion(r6p);
	map1.addRegion(r7p);
	map1.addRegion(r8p);
	map1.addRegion(r9p);
	map1.addRegion(r10p);

	//adds borders between Regions (Edges between Nodes on the graph)
	map1.addBorder(r1p, r2p);
	map1.addBorder(r2p, r3p);
	map1.addBorder(r1p, r4p);
	map1.addBorder(r1p, r5p);
	map1.addBorder(r4p, r5p);
	map1.addBorder(r5p, r6p);
	map1.addBorder(r2p, r7p);
	map1.addBorder(r7p, r8p);
	map1.addBorder(r8p, r9p);
	map1.addBorder(r9p, r10p);

	//performs depth-first search on the graph to check if its connected (from a starting node) 
	map1.isConnected();

	map1.displayRegionList();
}


void mapLoaderDriver()
{
	cout << "\nExecuting map loader driver:\n" << endl;
	MapLoader ml1, ml2;

	//Load Valid (Connected) Map
	Map map1 = ml1.loadMap("valid.map");

	//Load Invalid (Unconnected) Map
	Map map2 = ml2.loadMap("invalid.map");
}

void playerDiceRollDriver()
{
	cout << "\nExecuting player dice roller driver:\n" << endl;
	Dice dice;
	Player player;
	player.reinforcementRoll(&dice);
	player.displayRollPercentages(&dice);
}

void playerDriver()
{
	cout << "\nExecuting player driver:\n" << endl;
	//create Map object
	Map map1;

	//create region objects
	Region r1("Region 1");
	Region r2("Region 2");
	Region r3("Region 3");
	Region r4("Region 4");

	//create region pointers
	Region* r1p = &r1;
	Region* r2p = &r2;
	Region* r3p = &r3;
	Region* r4p = &r4;

	//adds Regions to the map (Regions are Nodes/Vertices on the Graph)
	map1.addRegion(r1p);
	map1.addRegion(r2p);
	map1.addRegion(r3p);
	map1.addRegion(r4p);

	//adds borders between Regions (Edges between Nodes on the graph)
	map1.addBorder(r1p, r2p);
	map1.addBorder(r2p, r3p);
	map1.addBorder(r3p, r4p);

	//create Game Deck object
	GameDeck deck;
	GameDeck* gdeck = &deck;

	//create Player object
	Player player("player1");
	Banner banner(Banner::SKELETONS);
	Badge badge(Badge::DRAGONMASTER);
	//picks a race
	player.picks_race(banner, badge, gdeck);
	//displays player info
	player.summarySheet();

	//player attempts to conquer Region 1 (valid)
	player.conquers(r1p, false);
	//player attempts to conquer Region 2 (invalid - region is not adjacent to one of his owned regions)
	player.conquers(r2p, false);
	player.redeployTroops(r1p, r2p, 1);
	player.abandonRegion(r1p);
	player.readyTroops();
	//player scores victory coins after conquering region
	player.scores(gdeck);
	//displaying updated player info
	cout << "\nUpdated player info:" << endl;
	player.summarySheet();
}
void gameDeckDriver() {
	cout << "\nExecuting game deck driver:\n" << endl;
	//create Game Deck object
	GameDeck deck;
	deck.showDeckInfo();
}

int main()
{
	while (true) {
		tournamentDriver();  //tournament driver 
	}
	
	/* UNCOMMENT CODE BELOW TO PLAY GAME NORMALLY (no automated tournament) */
	
	/*while (true) {   
		try {
			designPatternDriver();    
		}
		catch (...) {
			cout << "not a valid map name. please try again." << endl;
			
		}
	}*/

    return 0;
} 


