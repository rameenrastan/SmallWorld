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

void mainGameLoopDriver()
{
	GameLoop gl;
	gl.initializeGame();
	gl.startUpPhase();
	gl.mainLoop();
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


	//Case 2: Invalid (Unconnected) Map

	//create Map object
	Map map2;

	//create region objects
	Region r21("Region 2.1");
	Region r22("Region 2.2");
	Region r23("Region 2.3");
	Region r24("Region 2.4");
	Region r25("Region 2.5");
	Region r26("Region 2.6");
	Region r27("Region 2.7");
	Region r28("Region 2.8");
	Region r29("Region 2.9");
	Region r210("Region 2.10");

	//create region pointers
	Region* r21p = &r21;
	Region* r22p = &r22;
	Region* r23p = &r23;
	Region* r24p = &r24;
	Region* r25p = &r25;
	Region* r26p = &r26;
	Region* r27p = &r27;
	Region* r28p = &r28;
	Region* r29p = &r29;
	Region* r210p = &r210;

	//adds Regions to the map (Regions are Nodes/Vertices on the Graph)
	map2.addRegion(r21p);
	map2.addRegion(r22p);
	map2.addRegion(r23p);
	map2.addRegion(r24p);
	map2.addRegion(r25p);
	map2.addRegion(r26p);
	map2.addRegion(r27p);
	map2.addRegion(r28p);
	map2.addRegion(r29p);
	map2.addRegion(r210p);

	//adds borders between Regions (Edges between Nodes on the graph)
	map2.addBorder(r21p, r22p);
	map2.addBorder(r22p, r23p);
	map2.addBorder(r21p, r24p);
	map2.addBorder(r21p, r25p);
	map2.addBorder(r24p, r25p);
	map2.addBorder(r25p, r26p);
	map2.addBorder(r22p, r27p);
	map2.addBorder(r27p, r28p);
	//in this case, region 9 and region 10 are NOT connected to the rest of the map!
	map2.addBorder(r29p, r210p);

	//performs depth-first search on the graph to check if its connected (from a starting node) 
	map2.isConnected();
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
	//Assignment 1 Drivers
	//mapDriver();
	//mapLoaderDriver();
	//playerDiceRollDriver();
	//playerDriver();
	//gameDeckDriver();
	
	//picks a race
	GameLoop gl;
	gl.initializeGame();
	gl.startUpPhase();
	//gl.generateRaceCombo();
	gl.playerPicksRace(gl.players[0]);
	gl.playerInDecline(gl.players[0]);
//	player.picks_race(banner, badge, gdeck);
	//displays player info
//	player.summarySheet();


	//Assignment 2 Drivers
	//gameStartDriver();
	//startUpPhaseDriver();
	//mainGameLoopDriver();
	//conquersSomeRegionsDriver();
    return 0;
} 


