#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{

public:
    Character();
    virtual std::string getName() const;
    virtual unsigned int getHP() const;
    virtual unsigned int getAP() const;
    virtual unsigned int getLevel() const;
    virtual unsigned int getHealth() const;
    virtual unsigned int getID() const;

    virtual void setName(std::string name);
    virtual void setHP(unsigned int hp);
    virtual void setAP(unsigned int ap);
    virtual void setLevel(unsigned int level);
    virtual void setHealth(unsigned int health);
    virtual void setID(unsigned int id);

    virtual void heal(unsigned int procent = 100);

protected:
    unsigned int mHP = 10, mAP = 2, mLevel = 1, mHealth = 0, mID = 0;
    std::string mName = "";
};

#endif // CHARACTER_H
