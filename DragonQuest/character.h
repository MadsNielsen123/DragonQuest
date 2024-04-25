#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{

public:
    Character();
    std::string getName() const;
    unsigned int getHP() const;
    unsigned int getAP() const;
    unsigned int getLevel() const;
    unsigned int getHealth() const;


protected:
    unsigned int mHP, mAP, mLevel, mHealth;
    std::string mName;
};

#endif // CHARACTER_H
