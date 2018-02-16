#include "stdafx.h"
#include "GameDeck.h"



GameDeck::GameDeck()
{
	//total victory coins
	gameCoin = 515;

	//total region pieces
	numMountain = 9;
	numFortress = 6;
	numLair = 10;
	numEncampment = 5;
	numHole = 2;
	numHero = 2;
	numDragon = 1;
	numLostTribe = 18;

	//total race tokens
	amazonToken = 15;
	dwarfToken = 8;
	elfToken = 11;
	ghoulToken = 10;
	ratToken = 13; 
	skeletonToken = 20; 
	sorcererToken = 18;
	tritonToken = 11;
	giantToken = 11;
	halflingToken = 11;
	humanToken = 10;
	orcToken = 10;
	trollToken = 10;
	wizardToken = 10;
}




GameDeck::~GameDeck()
{
}

//victory coin methods

int GameDeck::getGameCoin(){
	return gameCoin;
}
void GameDeck::setGameCoin(int decrement){
	gameCoin -= decrement;
}

//region pieces methods

int GameDeck::getNumMountain(){
	return numMountain;
}

void GameDeck::setNumMountain(int mountainCount){
	numMountain = mountainCount;
}

int GameDeck::getNumFortress()
{
	return numFortress;
}

void GameDeck::setNumFortress(int fortressCount){
	numFortress = fortressCount;
}

int GameDeck::getNumLair(){
	return numLair;
}

void GameDeck::setNumLair(int lairCount){
	numLair = lairCount;
}

int GameDeck::getNumEncampment(){
	return numEncampment;
}

void GameDeck::setNUmEncampment(int encampCount){
	numEncampment = encampCount;
}

int GameDeck::getNumHole(){
	return numHole;
}

void GameDeck::setNumHole(int holeCount){
	numHole = holeCount;
}

int GameDeck::getNumHero(){
	return numHero;
}

void GameDeck::setNumHero(int heroCount){
	numHero = heroCount;
}

int GameDeck::getNumDragon(){
	return numDragon;
}

void GameDeck::setNumDragon(int dragonCount){
	numDragon = dragonCount;
}

int GameDeck::getNumLostTribe(){
	return numLostTribe;
}

void GameDeck::setNumLostTribe(int tribeCount){
	numLostTribe = tribeCount;
}

//race tokens methods

int GameDeck::getAmazonToken() {
	return amazonToken;
}
void GameDeck::setAmazonToken(int decrement){
	amazonToken -= decrement;
}

int GameDeck::getDwarfToken(){
	return dwarfToken;
}
void GameDeck::setDwarfToken(int decrement){
	dwarfToken -= decrement;
}
int GameDeck::getElfToken() {
	return elfToken;
}
void GameDeck::setElfToken(int decrement) {
	elfToken -= decrement;
}
int GameDeck::getGhoulToken() {
	return ghoulToken;
}
void GameDeck::setGhoulToken(int decrement) {
	ghoulToken -= decrement;
}
int GameDeck::getRatToken() {
	return ratToken;
}
void GameDeck::setRatToken(int decrement) {
	ratToken -= decrement;
}
int GameDeck::getSkeletonToken() {
	return skeletonToken;
}
void GameDeck::setSkeletonToken(int decrement) {
	skeletonToken -= decrement;
}
int GameDeck::getSorcererToken() {
	return sorcererToken;
}
void GameDeck::setSorcererToken(int decrement) {
	sorcererToken -= decrement;
}
int GameDeck::getTritonToken() {
	return tritonToken;
}
void GameDeck::setTritonToken(int decrement) {
	tritonToken -= decrement;
}
int GameDeck::getGiantToken() {
	return giantToken;
}
void GameDeck::setGiantToken(int decrement) {
	giantToken -= decrement;
}
int GameDeck::getHalflingToken() {
	return halflingToken;
}
void GameDeck::setHalflingToken(int decrement) {
	halflingToken -= decrement;
}
int GameDeck::getHumanToken() {
	return humanToken;
}
void GameDeck::setHumanToken(int decrement) {
	humanToken -= decrement;
}
int GameDeck::getOrcToken() {
	return orcToken;
}
void GameDeck::setOrcToken(int decrement) {
	orcToken -= decrement;
}
int GameDeck::getTrollToken() {
	return trollToken;
}
void GameDeck::setTrollToken(int decrement) {
	trollToken -= decrement;
}
int GameDeck::getWizardToken() {
	return wizardToken;
}
void GameDeck::setWizardToken(int decrement) {
	wizardToken -= decrement;
}

//game deck information
void GameDeck::showDeckInfo()
{
	cout << "Game deck information:" << endl;
	//victory coins
	cout << "\tVictory coins currently in deck: " << getGameCoin() << endl;
	//region pieces
	cout << "\tRegion pieces currently in deck:" << endl;
	cout << "\t\tMountain pieces: " << getNumMountain() << endl;
	cout <<	"\t\tFortess pieces: " << getNumFortress() << endl;
	cout << "\t\tLair pieces: " << getNumLair() << endl;
	cout << "\t\tEncampment pieces: " << getNumEncampment() << endl;
	cout << "\t\tHole pieces: " << getNumHole() << endl;
	cout << "\t\tHero pieces: " << getNumHero() << endl;
	cout << "\t\tDragon pieces: " << getNumDragon() << endl;
	cout << "\t\tLost tribe pieces: " << getNumLostTribe() << endl;
	//race tokens
	cout << "\tRace tokens currently in deck:" << endl;
	cout << "\t\tAmazon tokens: " << getAmazonToken() << endl;
	cout << "\t\tDwarf tokens: " << getDwarfToken() << endl;
	cout << "\t\tElf tokens: " << getElfToken() << endl;
	cout << "\t\tGhoul tokens: " << getGhoulToken() << endl;
	cout << "\t\tRat tokens: " << getRatToken() << endl;
	cout << "\t\tSkeleton tokens: " << getSkeletonToken() << endl;
	cout << "\t\tSorcerer tokens: " << getSorcererToken() << endl;
	cout << "\t\tTriton tokens: " << getTritonToken() << endl;
	cout << "\t\tGiant tokens: " << getGiantToken() << endl;
	cout << "\t\tHalfling tokens: " << getHalflingToken() << endl;
	cout << "\t\tHuman tokens: " << getHumanToken() << endl;
	cout << "\t\tOrc tokens: " << getOrcToken() << endl;
	cout << "\t\tTroll tokens: " << getTrollToken() << endl;
	cout << "\t\tWizard tokens: " << getWizardToken() << endl;
}
