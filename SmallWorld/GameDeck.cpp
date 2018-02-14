#include "stdafx.h"
#include "GameDeck.h"



GameDeck::GameDeck()
{
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