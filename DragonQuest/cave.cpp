#include "cave.h"

Cave::Cave()
{

}


//Getters
unsigned int Cave::getID() const{return mID;}
unsigned int Cave::getWinGold() const{return mWinGold;}
unsigned int Cave::getWinXP() const{return mWinXP;}
unsigned int Cave::getLevel() const{return mLevel;}
std::string Cave::getName() const{return mName;}
unsigned int Cave::getHeroID() const {return mHeroID;}
bool Cave::isConquered() const{return mConquered;}
//Setters
void Cave::setID(unsigned int ID) {mID = ID;}
void Cave::setWinGold(unsigned int gold){mWinGold = gold;}
void Cave::setWinXP(unsigned int xp){mWinXP = xp;}
void Cave::setLevel(unsigned int level){mLevel = level;}
void Cave::setName(std::string name){mName = name;}
void Cave::setConqueredStatus(bool status){mConquered = status;}
void Cave::setHeroID(unsigned int id) {mHeroID = id;}
