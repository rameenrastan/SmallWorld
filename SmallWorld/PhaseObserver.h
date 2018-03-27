#pragma once
#include "Observer.h"
#include "GameLoop.h"

class PhaseObserver : public Observer
{
public:
	~PhaseObserver();
	PhaseObserver();
	PhaseObserver(GameLoop* subj);
	void update();
private:
	GameLoop* subject;

};

