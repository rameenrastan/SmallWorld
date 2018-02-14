#pragma once

class GameDeck
{
private:
	int amazonToken = 8, dwarfToken, elfToken, ghoulToken, ratToken, skeletonToken, sorcererToken, tritonToken, giantToken, halflingToken, humanToken, orcToken, trollToken, wizardToken;

public:
	GameDeck();
	~GameDeck();
	
	int getAmazonToken();
	int getDwarfToken();

};

