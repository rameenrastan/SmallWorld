#include "stdafx.h"
#include "Subject.h"


void Subject::attach(Observer * observer)
{
	observers.push_back(observer);
}

void Subject::detach(Observer * observer)
{
	for (int i = 0; i < observers.size(); i++)
	{
		if (observers[i] == observer) {
			observers.erase(observers.begin() + i);
		}
	}
}

void Subject::notify()
{
	for (auto & observer : observers)
	{
		observer->update();
	}
}

Subject::Subject()
{
}


Subject::~Subject()
{
}
