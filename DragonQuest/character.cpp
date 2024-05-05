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
