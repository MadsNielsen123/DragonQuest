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

private:
    unsigned int mXP;
};

#endif // HERO_H
