#include "hero.h"

Hero::Hero()
{

}

unsigned int Hero::getXP() const {return mXP;}
void Hero::setXP(unsigned int xp) {mXP = xp;}
void Hero::addXP(unsigned int xp){mXP += xp;}
