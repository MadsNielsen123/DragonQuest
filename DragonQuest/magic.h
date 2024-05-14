#ifndef MAGIC_H
#define MAGIC_H
#include <string>

class Magic
{
public:
    Magic();

    //getters/setters
    double getDamage() const;
    int getSelfDamage() const;
    unsigned int getID() const;
    unsigned int getRequiredID() const;
    unsigned int getBuyPrice() const;
    std::string getName() const;
    unsigned int getElement() const;
    std::string getElementName() const;
    unsigned int getR() const;
    unsigned int getG() const;
    unsigned int getB() const;

    void setDamage(double damage);
    void setSelfDamage(int selfDamage);
    void setID(unsigned int id);
    void setRequiredID(unsigned int id);
    void setPrice(unsigned int price);
    void setName(std::string name);
    void setElement(unsigned int id);
    void setElementName(std::string name);
    void setR(unsigned int R);
    void setG(unsigned int G);
    void setB(unsigned int B);

private:

    double mDamage = 0;
    int mSelfDamage = 0;
    unsigned int mID = 0, mRequiredID = 0, mBuyPrice = 0;
    std::string mName;
    unsigned int mElement;
    std::string mElementName;
    unsigned int mR = 255, mG = 255, mB = 255;
};

#endif // MAGIC_H
