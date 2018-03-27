#pragma once
#include "Subject.h"

class Subject;

class Observer
{
public:
	Observer();
	~Observer();
	Subject* subject;
	virtual void update() = 0;
};

