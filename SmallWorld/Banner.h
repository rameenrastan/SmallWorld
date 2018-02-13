#pragma once
#include <string>

using namespace std;

class Banner
{
private:
	string bannerName;
public:
	Banner();
	Banner(string);
	~Banner();

	string getBanner();
};

