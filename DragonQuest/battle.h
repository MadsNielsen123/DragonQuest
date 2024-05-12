#ifndef BATTLE_H
#define BATTLE_H

#include "hero.h"
#include "monster.h"
#include "terminal.h"
#include <string>
#include <vector>
#include <unistd.h>
#include <databasehandler.h>

class Battle
{
public:
    Battle(Hero& ch1, Monster& ch2, DatabaseHandler& DH);
    void start();

private:
    Hero& mHero;
    Monster& mMonster;

    unsigned int mRound = 0;
    Terminal mT;
    std::vector<std::string> mBattleLog;
    DatabaseHandler& mDH;
};

#endif // BATTLE_H
