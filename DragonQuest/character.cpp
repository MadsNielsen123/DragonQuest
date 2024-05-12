#include "character.h"

Character::Character()
{

}

std::string Character::getName() const {return mName;}
unsigned int Character::getHP() const {return mHP;}
unsigned int Character::getHealth() const {return mHealth;}
unsigned int Character::getAP() const {return mAP;}
unsigned int Character::getLevel() const {return mLevel;}
unsigned int Character::getID() const {return mID;}


void Character::setName(std::string name){mName = name;}
void Character::setHP(unsigned int hp){mHP = hp;}
void Character::setAP(unsigned int ap){mAP = ap;}
void Character::setLevel(unsigned int level){mLevel = level;}
void Character::setHealth(unsigned int health){mHealth = health;}
void Character::setID(unsigned int id){mID = id;}

void Character::heal(unsigned int procent)
{
    mHealth += mHP*(procent/100);
    if(mHealth > mHP)
        mHealth = mHP;
}

void Character::addElement(unsigned int elemID, std::string name, unsigned int R, unsigned int G, unsigned int B)
{
    mTypes.push_back(elemID);
    mTypeNames.push_back(name);
    mTypeRed.push_back(R);
    mTypeGreen.push_back(G);
    mTypeBlue.push_back(B);
}
void Character::deleteElements() {mTypes.clear();}

std::string Character::getElementName(unsigned int index) const
{
    if(index >= mTypes.size())
        return "255";
    else
        return mTypeNames[index];
}

unsigned int Character::getElementR(unsigned int index) const
{
    if(index >= mTypes.size())
        return 255;
    else
        return mTypeRed[index];
}

unsigned int Character::getElementG(unsigned int index) const
{
    if(index >= mTypes.size())
        return 255;
    else
        return mTypeGreen[index];
}

unsigned int Character::getElementB(unsigned int index) const
{
    if(index >= mTypes.size())
        return 255;
    else
        return mTypeBlue[index];
}

unsigned int Character::getElementCount() const {return mTypes.size();}
