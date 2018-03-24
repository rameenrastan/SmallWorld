#pragma once
#include <vector>
#include "Observer.h"
using namespace std;

class Subject
{
public:
	virtual void attach(Observer *observer);
	virtual void detach(Observer *observer);
	virtual void notify();
	Subject();
	~Subject();
private:
	vector<Observer*> observers;
};

