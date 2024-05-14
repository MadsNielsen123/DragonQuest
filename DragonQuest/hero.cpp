#include "hero.h"

Hero::Hero()
{
    mTypes.push_back(1); //add "normal-type" to hero *optional
}

unsigned int Hero::getXP() const {return mXP;}
void Hero::setXP(unsigned int xp) {mXP = xp;}
void Hero::addXP(unsigned int xp){mXP += xp;}
void Hero::levelUp()
{
    setXP(mXP-mLevel*1000); //consume xp
    setLevel(mLevel+1); //level up
    setAP(mAP+1);
    setHP(mHP+2);
    setMP(mMP+2);
}

void Hero::setGold(int gold){mGold = gold;}
void Hero::giveGold(int gold){mGold = mGold + gold;}
void Hero::takeGold(int gold){mGold = mGold - gold;}
int Hero::getGold() const {return mGold;}
unsigned int Hero::getMP() const {return mMP;}
void Hero::setMP(unsigned int mp) {mMP = mp;}

void Hero::equipMagic(const Magic& magic)
{
    for(Magic m: mEquippedMagics)
    {
        if(m.getID() == magic.getID())
            return; //Already equipped
    }

    mEquippedMagics.push_back(magic);
}

void Hero::unequipMagic(const Magic& magic)
{
    for(int i = 0; i<mEquippedMagics.size(); ++i)
    {
        if(magic.getID() == mEquippedMagics[i].getID())
        {
            mEquippedMagics[i] = mEquippedMagics.back();
            mEquippedMagics.pop_back();
        }
    }
}

bool Hero::magicIsEquiped(unsigned int id) const
{
    for(Magic m: mEquippedMagics)
    {
        if(m.getID() == id)
            return true; //Equipped
    }
    return false;
}

bool Hero::hasMagicEquipped() const
{
    return !mEquippedMagics.empty();
}

Magic& Hero::getMagic(unsigned int index)
{
    return mEquippedMagics[index];
}

unsigned int Hero::magicsEquippedCount() const
{
    return mEquippedMagics.size();
}
