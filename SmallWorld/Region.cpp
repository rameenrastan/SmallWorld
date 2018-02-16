#include "stdafx.h"
#include "Region.h"

Region::Region()
{
}

Region::Region(string name)
{
	regionName = name;
	numTokens = 0;

}

Region::~Region()
{
}

string Region::getRegionName() const{
	return regionName;
}

int Region::getNumTokens() const{
	return numTokens;
}

bool Region::hasMountain(){
	return mountain;
}

bool Region::hasLostTribe(){
	return lostTribe;
}

bool Region::hasMine(){
	return mine;
}

void Region::setMine(bool mineReg){
	mine = mineReg;
}

bool Region::isFarmland(){
	return farmland;
}

void Region::setFarmland(bool farm){
	farmland = farm;
}

bool Region::isMagic(){
	return magic;
}

void Region::setMagic(bool magicReg){
	magic = magicReg;
}

bool Region::isForest(){
	return forest;
}

void Region::setForest(bool forestReg){
	forest = forestReg;
}

void Region::setOwned(bool o){
	owned = o;
}

bool Region::isFortress(){
	return fortress;
}

void Region::setFortress(bool fort){
	fortress = fort;
}

bool Region::isHill(){
	return hill;
}

void Region::setHill(bool hillReg){
	hill = hillReg;
}

bool Region::isSwamp(){
	return swamp;
}

void Region::setSwamp(bool swampReg){
	swamp = swampReg;
}

bool Region::isOwned(){
	return owned;
}

void Region::setRegionName(string name){
	regionName = name;
}

void Region::setNumTokens(int num){
	numTokens = num;
}

void Region::addNeighbor(Region* &r){
	neighbors.push_back(r);
}

void Region::eliminateMountain(){
	mountain = false;
}

void Region::eliminateLostTribe(){
	lostTribe = false;
}

void Region::setOwner(Player* const & player){
	owner = player;
}

vector<Region*> Region::getNeighbors() const{
	return neighbors;
}

Player* Region::getOwner() const{
	return owner;
}