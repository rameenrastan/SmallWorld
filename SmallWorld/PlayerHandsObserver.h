#pragma once
#include "GameStatisticsObserverDecorator.h"
#include <string>

class PlayerHandsObserver : public GameStatisticsObserverDecorator
{
private:
	vector<string> playerHands;
	bool updateRequired;
public:
	PlayerHandsObserver(GameStatisticsObserver *decoratedObserver) : GameStatisticsObserverDecorator(decoratedObserver) {
		for (int i = 0; i < 4; i++)
		{
			playerHands.push_back("");
		}
	};
	PlayerHandsObserver();
	~PlayerHandsObserver();
	void update();
};

