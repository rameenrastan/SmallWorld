#include "stdafx.h"
#include "GameStatisticsObserverDecorator.h"


GameStatisticsObserverDecorator::GameStatisticsObserverDecorator()
{
}


GameStatisticsObserverDecorator::GameStatisticsObserverDecorator(GameStatisticsObserver *decoratedObserver)
{
	this->decoratedObserver = decoratedObserver;
	Subject* subj = decoratedObserver->getSubject();
	subj->detach(decoratedObserver);
	subj->attach(this);
}

GameStatisticsObserverDecorator::~GameStatisticsObserverDecorator()
{
}

void GameStatisticsObserverDecorator::update()
{
	decoratedObserver->update();
}
