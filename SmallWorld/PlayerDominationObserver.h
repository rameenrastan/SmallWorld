#pragma once
#include "GameStatisticsObserverDecorator.h"
#include <vector>
#include <xtgmath.h>

class PlayerDominationObserver : public GameStatisticsObserverDecorator
{
private:
	vector<double> regionsOwnedPercentages;
	bool updateRequired;
public:
	PlayerDominationObserver();
	PlayerDominationObserver(GameStatisticsObserver *decoratedObserver) : GameStatisticsObserverDecorator(decoratedObserver) {
		for (int i = 0; i < 4; i++)
		{
			regionsOwnedPercentages.push_back(0);
		}
	};
	~PlayerDominationObserver();
	void update();
};

