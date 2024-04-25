#ifndef HERO_H
#define HERO_H
#include "character.h"

class Hero : public Character
{
public:
    Hero();
    void setXP();
    void addXP();
    unsigned int getXP() const;

private:
    unsigned int mXP;
};

#endif // HERO_H
