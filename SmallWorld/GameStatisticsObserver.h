#pragma once
#include "GameLoop.h"

class GameStatisticsObserver : public Observer
{
public:
	GameStatisticsObserver();
	~GameStatisticsObserver();
	GameStatisticsObserver(GameLoop* subj);
	void update();
	void display();
	GameLoop* getSubject() { return subject; }
protected:
	GameLoop * subject;
private:
	int turnNumber;
};

