#include "hero.h"

Hero::Hero()
{

}

unsigned int Hero::getXP() const {return mXP;}
void Hero::setXP(unsigned int xp) {mXP = xp;}
void Hero::addXP(unsigned int xp){mXP += xp;}
void Hero::levelUp()
{
    setXP(mXP-mLevel*1000); //consume xp
    setLevel(mLevel+1); //level up
    setAP(mAP+1);
    setHP(mHP+2);
}

void Hero::setGold(int gold){mGold = gold;}
void Hero::giveGold(int gold){mGold = mGold + gold;}
void Hero::takeGold(int gold){mGold = mGold - gold;}
int Hero::getGold() const {return mGold;}
