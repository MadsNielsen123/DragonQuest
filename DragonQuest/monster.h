#ifndef MONSTER_H
#define MONSTER_H
#include "character.h"

class Monster : public Character
{
public:
    Monster();

    void setKillXP(unsigned int xp);
    unsigned int getKillXP() const;

private:
    unsigned int mKillXP = 0;
};

#endif // MONSTER_H
