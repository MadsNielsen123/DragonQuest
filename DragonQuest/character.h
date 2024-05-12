#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

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

    virtual void addElement(unsigned int elemID, std::string name, unsigned int R, unsigned int G, unsigned int B);
    virtual void deleteElements();
    virtual std::string getElementName(unsigned int index) const;
    virtual unsigned int getElementR(unsigned int index) const;
    virtual unsigned int getElementG(unsigned int index) const;
    virtual unsigned int getElementB(unsigned int index) const;
    virtual unsigned int getElementCount() const;

    virtual void heal(unsigned int procent = 100);

protected:
    unsigned int mHP = 10, mAP = 2, mLevel = 1, mHealth = 0, mID = 0;
    std::string mName = "";
    std::vector<unsigned int> mTypes, mTypeRed, mTypeGreen, mTypeBlue;
    std::vector<std::string> mTypeNames;
};

#endif // CHARACTER_H
