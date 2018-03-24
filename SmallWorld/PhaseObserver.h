#pragma once
#include "Observer.h"

class PhaseObserver : public Observer
{
public:
	PhaseObserver();
	~PhaseObserver();
	void update();
	void display();
};

