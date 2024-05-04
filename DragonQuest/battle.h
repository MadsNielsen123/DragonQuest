#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "terminal.h"

class Battle
{
public:
    Battle(Character& ch1, Character& ch2);
    void start();

private:
    Character& mCh1, mCh2;

    unsigned int mRound = 0;
    Terminal mT;
};

#endif // BATTLE_H
