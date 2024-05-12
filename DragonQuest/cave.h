#ifndef CAVE_H
#define CAVE_H
#include <string>

class Cave
{
public:
    Cave();

    //getters
    unsigned int getID() const;
    unsigned int getWinGold() const;
    unsigned int getWinXP() const;
    unsigned int getLevel() const;
    std::string getName() const;
    unsigned int getHeroID() const;
    bool isConquered() const;
    //setters
    void setID(unsigned int ID);
    void setWinGold(unsigned int gold);
    void setWinXP(unsigned int xp);
    void setLevel(unsigned int level);
    void setName(std::string name);
    void setConqueredStatus(bool status);
    void setHeroID(unsigned int id);


private:
    unsigned int mID = 0, mWinGold = 0, mWinXP = 0, mLevel = 0;
    std::string mName;
    bool mConquered = false;
    unsigned int mHeroID;
};

#endif // CAVE_H
