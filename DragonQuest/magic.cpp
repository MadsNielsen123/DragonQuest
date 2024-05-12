#include "magic.h"

Magic::Magic()
{

}

int Magic::getDamage() const {return mDamage;}
int Magic::getSelfDamage() const {return mSelfDamage;}
unsigned int Magic::getID() const  {return mID;}
unsigned int Magic::getRequiredID() const {return mRequiredID;}
unsigned int Magic::getBuyPrice() const {return mBuyPrice;}
std::string Magic::getName() const {return mName;}
unsigned int Magic::getElement() const {return mElement;}
std::string Magic::getElementName() const {return mElementName;}
unsigned int Magic::getR() const {return mR;}
unsigned int Magic::getG() const {return mG;}
unsigned int Magic::getB() const {return mB;}

void Magic::setDamage(int damage) {mDamage = damage;}
void Magic::setSelfDamage(int selfDamage) {mSelfDamage = selfDamage;}
void Magic::setID(unsigned int id) {mID = id;}
void Magic::setRequiredID(unsigned int id) {mRequiredID = id;}
void Magic::setPrice(unsigned int price) {mBuyPrice = price;}
void Magic::setName(std::string name) {mName = name;}
void Magic::setElement(unsigned int id) {mElement = id;}
void Magic::setElementName(std::string name) {mElementName = name;}
void Magic::setR(unsigned int R) {mR = R;}
void Magic::setG(unsigned int G) {mG = G;}
void Magic::setB(unsigned int B) {mB = B;}
