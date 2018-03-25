#pragma once
#include <vector>
#include "Observer.h"
using namespace std;

class Subject
{
public:
	void attach(Observer *observer);
	void detach(Observer *observer);
	void notify();
	Subject();
	~Subject();
private:
	vector<Observer*> observers;
};

