#pragma once
#include <string>

using namespace std;

class Badge
{
private:
	string badgeName;
public:
	Badge();
	Badge(string);
	~Badge();

	string getBadge();
};

