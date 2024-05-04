#include "monster.h"

Monster::Monster()
{

}

void Monster::setKillXP(unsigned int xp){ mKillXP = xp;}

unsigned int Monster::getKillXP() const { return mKillXP;}
