#ifndef BATTLE_H
#define BATTLE_H

#include "character.h"
#include "hero.h"
#include "monster.h"
#include "terminal.h"
#include <string>
#include <vector>
#include <unistd.h>

class Battle
{
public:
    Battle(Character& ch1, Character& ch2);
    void start();

private:
    Character& mCh1;
    Character& mCh2;

    unsigned int mRound = 0;
    Terminal mT;
    std::vector<std::string> mBattleLog;
};

#endif // BATTLE_H
