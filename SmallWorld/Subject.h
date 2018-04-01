#pragma once
#include <vector>
#include "Observer.h"
using namespace std;

class Observer;

class Subject
{
public:
	void attach(Observer *observer);
	void detach(Observer *observer);
	vector<Observer*> getObservers() { return observers;  }
	void notify();
	Subject();
	~Subject();
protected:
	vector<Observer*> observers;
};

