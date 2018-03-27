#pragma once
#include "GameStatisticsObserverDecorator.h"

class PlayerHandsObserver : public GameStatisticsObserverDecorator
{
public:
	PlayerHandsObserver(GameStatisticsObserver *decoratedObserver) : GameStatisticsObserverDecorator(decoratedObserver) {};
	PlayerHandsObserver();
	~PlayerHandsObserver();
	void update();
};

