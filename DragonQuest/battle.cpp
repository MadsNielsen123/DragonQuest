#include "battle.h"

Battle::Battle(Character& ch1, Character& ch2) : mCh1(ch1), mCh2(ch2)
{

}

void Battle::start()
{
    while(mCh1.getHealth() > 0 && mCh2.getHealth() > 0)
    {
        mT.printBattleBox(mCh1, mCh2, 0,0);
    }

}
