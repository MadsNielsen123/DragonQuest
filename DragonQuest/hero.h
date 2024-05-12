#ifndef HERO_H
#define HERO_H
#include "character.h"
#include "magic.h"

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

    void equipMagic(const Magic& magic);
    void unequipMagic(const Magic& magic);
    bool magicIsEquiped(unsigned int id) const;
    bool hasMagicEquipped() const;
    Magic& getMagic(unsigned int index);
    unsigned int magicsEquippedCount() const;

    void setMP(unsigned int mp);
    unsigned int getMP() const;

private:
    unsigned int mXP = 0, mMP = 0;
    int mGold;
    std::vector<Magic> mEquippedMagics;
};

#endif // HERO_H
