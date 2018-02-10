// SmallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Map.h"
#include "Region.h"
#include "MapLoader.h"

using namespace std;

int main()
{
	//Map map;
	//Region r1("Region 1");
	//Region r2("Region 2");
	//Region r3("Region 3");
	//Region r4("Region 4");
	//Region r5("Region 5");
	//Region r6("Region 6");
	//Region r7("Region 7");
	//Region r8("Region 8");
	//Region r9("Region 9");
	//Region r10("Region 10");

	//Region* r1p = &r1;
	//Region* r2p = &r2;
	//Region* r3p = &r3;
	//Region* r4p = &r4;
	//Region* r5p = &r5;
	//Region* r6p = &r6;
	//Region* r7p = &r7;
	//Region* r8p = &r8;
	//Region* r9p = &r9;
	//Region* r10p = &r10;


	////adds Regions to the map (Regions are Nodes/Vertices on the Graph)
	//map.addRegion(r1p);
	//map.addRegion(r2p);
	//map.addRegion(r3p);
	//map.addRegion(r4p);
	//map.addRegion(r5p);
	//map.addRegion(r6p);
	//map.addRegion(r7p);
	//map.addRegion(r8p);
	//map.addRegion(r9p);
	//map.addRegion(r10p);

	////adds borders between Regions (Edges between Nodes on the graph)
	//map.addBorder(r1p, r2p);
	//map.addBorder(r2p, r3p);
	//map.addBorder(r1p, r4p);
	//map.addBorder(r1p, r5p);
	//map.addBorder(r4p, r5p);
	//map.addBorder(r5p, r6p);
	//map.addBorder(r2p, r7p);
	//map.addBorder(r7p, r8p);
	//map.addBorder(r8p, r9p);
	//map.addBorder(r9p, r10p);

	////performs depth-first search on the graph to check if its connected (from a starting node)
	//map.isConnected();

	MapLoader ml;
	Map map = ml.loadMap("map.txt");
	map.isConnected();

    return 0;
}

