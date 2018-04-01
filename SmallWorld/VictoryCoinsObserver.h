#pragma once
#include "GameStatisticsObserverDecorator.h"
#include <vector>
class VictoryCoinsObserver : public GameStatisticsObserverDecorator
{
private:
	vector<int> victoryCoins;
public:
	VictoryCoinsObserver(GameStatisticsObserver *decoratedObserver) : GameStatisticsObserverDecorator(decoratedObserver) {
		for (int i = 0; i < 5; i++)
		{
			victoryCoins.push_back(0);
		}
	};
	VictoryCoinsObserver();
	~VictoryCoinsObserver();
	void update();
};

