#ifndef HERO_H
#define HERO_H
#include "character.h"

class Hero : public Character
{
public:
    Hero();

    void setXP(unsigned int xp);
    unsigned int getXP() const;
    void addXP(unsigned int xp);
    void levelUp();

    void setGold(int gold);
    int getGold() const;
    void giveGold(int gold);
    void takeGold(int gold);

private:
    unsigned int mXP;
    int mGold;
};

#endif // HERO_H
