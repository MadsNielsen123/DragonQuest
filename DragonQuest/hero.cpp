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
