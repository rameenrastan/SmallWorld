#pragma once


using namespace std;

class GameDeck
{
private:
	int gameCoin;
	int amazonToken, dwarfToken , elfToken, ghoulToken, ratToken, skeletonToken, sorcererToken, tritonToken, giantToken, halflingToken, humanToken, orcToken, trollToken, wizardToken;

public:
	GameDeck();

	~GameDeck();

	int getGameCoin();
	void setGameCoin(int);
	
	int getAmazonToken();
	void setAmazonToken(int);
	int getDwarfToken();
	void setDwarfToken(int);
	int getElfToken();
	void setElfToken(int);
	int getGhoulToken();
	void setGhoulToken(int);
	int getRatToken();
	void setRatToken(int);
	int getSkeletonToken();
	void setSkeletonToken(int);
	int getSorcererToken();
	void setSorcererToken(int);
	int getTritonToken();
	void setTritonToken(int);
	int getGiantToken();
	void setGiantToken(int);
	int getHalflingToken();
	void setHalflingToken(int);
	int getHumanToken();
	void setHumanToken(int);
	int getOrcToken();
	void setOrcToken(int);
	int getTrollToken();
	void setTrollToken(int);
	int getWizardToken();
	void setWizardToken(int);
	
};

