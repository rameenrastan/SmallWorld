#include "stdafx.h"
#include "GameStatisticsObserver.h"


GameStatisticsObserver::GameStatisticsObserver()
{
}


GameStatisticsObserver::~GameStatisticsObserver()
{
}

GameStatisticsObserver::GameStatisticsObserver(GameLoop * subj)
{
	subject = subj;
	subject->attach(this);
}

void GameStatisticsObserver::update()
{

	//Basic (Undecorated) Game Statistics Observer functionality: displays Turn Number

	int turnNumber = subject->getTurn();

	cout << "Turn Number: " << turnNumber << endl;
	
}

void GameStatisticsObserver::display()
{

}
