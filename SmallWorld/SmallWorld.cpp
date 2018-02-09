// SmallWorld.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Map.h"
#include "Region.h"

using namespace std;

int main()
{
	Map map;
	Region r1("R1");
	Region r2("R2");
	Region r3("R3");
	Region r4("R4");
	Region r5("R4");

	Region* r1p = &r1;
	Region* r2p = &r2;
	Region* r3p = &r3;
	Region* r4p = &r4;
	Region* r5p = &r5;

	(*r1p).addNeighbor(r2p);
	(*r2p).addNeighbor(r1p);
	(*r1p).addNeighbor(r3p);
	(*r3p).addNeighbor(r1p);
	(*r1p).addNeighbor(r4p);
	(*r4p).addNeighbor(r1p);
	(*r2p).addNeighbor(r5p);
	(*r5p).addNeighbor(r2p);

	cout << r1p << endl;
	cout << r2p << endl;
	cout << r3p << endl;
	cout << r4p << endl;


	map.addRegion(*r1p);
	map.addRegion(*r2p);
	map.addRegion(*r3p);
	map.addRegion(*r4p);
	map.addRegion(*r5p);

	map.traversal(*r3p);
	map.isConnected();

    return 0;
}

