#pragma once
#include "GameStatisticsObserverDecorator.h"

class PlayerDominationObserver : public GameStatisticsObserverDecorator
{
public:
	PlayerDominationObserver();
	PlayerDominationObserver(GameStatisticsObserver *decoratedObserver) : GameStatisticsObserverDecorator(decoratedObserver) {};
	~PlayerDominationObserver();
	void update();
};

