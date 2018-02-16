#pragma once


using namespace std;

/*
This class stores all the pieces of the game deck.
*/
class GameDeck
{
private:
	int gameCoin;
	int numMountain, numFortress,numLair,numEncampment,numHole,numHero,numDragon;
	int amazonToken, dwarfToken , elfToken, ghoulToken, ratToken, skeletonToken, sorcererToken, tritonToken, giantToken, halflingToken, humanToken, orcToken, trollToken, wizardToken;

public:
	GameDeck();

	~GameDeck();

	int getGameCoin();
	void setGameCoin(int);

	int getNumMountain();
	void setNumMountain(int);
	int getNumFortress();
	void setNumFortress(int);
	int getNumLair();
	void setNumLair(int);
	int getNumEncampment();
	void setNUmEncampment(int);
	int getNumHole();
	void setNumHole(int);
	int getNumHero();
	void setNumHero(int);
	int getNumDragon();
	void setNumDragon(int);
	
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

