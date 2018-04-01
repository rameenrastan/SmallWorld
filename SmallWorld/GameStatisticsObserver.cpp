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

	int currentTurn = subject->getTurn();

	//checks if turn number has increased (update the view to display the current turn number if so)
	if (currentTurn > turnNumber)
	{
		cout << "Turn Number: " << currentTurn << endl;
		turnNumber = currentTurn;
	}
	
}

void GameStatisticsObserver::display()
{

}
