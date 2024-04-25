#include "character.h"

Character::Character()
{

}

std::string Character::getName() const {return mName;}
unsigned int Character::getHP() const {return mHP;}
unsigned int Character::getHealth() const {return mHealth;}
unsigned int Character::getAP() const {return mAP;}
unsigned int Character::getLevel() const {return mLevel;}
