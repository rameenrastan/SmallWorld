#pragma once
#include "GameStatisticsObserver.h"

class GameStatisticsObserverDecorator : public GameStatisticsObserver  
{
protected:
	GameStatisticsObserver * decoratedObserver;
public:
	GameStatisticsObserverDecorator();
	GameStatisticsObserverDecorator(GameStatisticsObserver *decoratedObserver);
	~GameStatisticsObserverDecorator();
	void update();
};

