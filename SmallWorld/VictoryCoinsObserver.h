#pragma once
#include "GameStatisticsObserverDecorator.h"

class VictoryCoinsObserver : public GameStatisticsObserverDecorator
{
public:
	VictoryCoinsObserver(GameStatisticsObserver *decoratedObserver) : GameStatisticsObserverDecorator(decoratedObserver) {};
	VictoryCoinsObserver();
	~VictoryCoinsObserver();
	void update();
};

