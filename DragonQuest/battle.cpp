#include "battle.h"
#include <random>

Battle::Battle(Hero& hero, Monster& monster, DatabaseHandler& dh) : mHero(hero), mMonster(monster), mDH(dh)
{
    mT.setTerminalSize(120,40);
}

void Battle::start()
{
    srand((unsigned int)time(NULL));
    bool herosTurn = true; //ch1 starts
    bool magicTime = true;
    int dmg = 0;
    double modifier = 0;
    Magic currentMagic;

    mT.resetStyle();
    mT.printBattleBox(mHero, mMonster, 20,1);

    mBattleLog.push_back("Battle Ready to begin");
    mT.printList(mBattleLog, false, 5, 15, 13, false, mBattleLog.size()-1);
    usleep(200000);
    mBattleLog.push_back("1..");
    mT.printList(mBattleLog, false, 5, 15, 13, false, mBattleLog.size()-1);
    usleep(600000);
    mBattleLog.push_back("2..");
    mT.printList(mBattleLog, false, 5, 15, 13, false, mBattleLog.size()-1);
    usleep(600000);
    mBattleLog.push_back("3..");
    mT.printList(mBattleLog, false, 5, 15, 13, false, mBattleLog.size()-1);
    usleep(600000);
    mBattleLog.push_back("FIGHT!");
    mT.printList(mBattleLog, false, 5, 15, 13, false, mBattleLog.size()-1);
    usleep(200000);


    //Battle ON
    while(mHero.getHealth() > 0 && mMonster.getHealth() > 0)
    {

        if(herosTurn)
        {
            if(magicTime && mHero.hasMagicEquipped()) //Use spell
            {
                currentMagic = mHero.getMagic(rand() % mHero.magicsEquippedCount());
                modifier = mDH.getDamageModifier(currentMagic, mMonster);
                dmg = (mHero.getMP()+currentMagic.getDamage()) * modifier;
                mBattleLog.push_back(mHero.getName() + " uses " + currentMagic.getName());
                if(modifier > 1)
                    mBattleLog.push_back("It's efficient! " + mMonster.getName() + " takes " + std::to_string(dmg) + " DMG!");
                else if(modifier < 1 && modifier > 0.3)
                    mBattleLog.push_back("It's not very efficient... " +mMonster.getName() + " takes " + std::to_string(dmg) + " DMG!");
                else if(modifier < 1)
                    mBattleLog.push_back("Its sucks! " +mMonster.getName() + " only takes " + std::to_string(dmg) + " DMG!");
                else
                    mBattleLog.push_back(mMonster.getName() + " takes " + std::to_string(dmg) + " DMG!");

            }
            else
            {
                dmg = mHero.getAP();

                mBattleLog.push_back(mHero.getName() + " attacks!");
                mBattleLog.push_back(mMonster.getName() + " takes " + std::to_string(dmg) + " DMG!");

            }

            if(dmg > mMonster.getHealth())
                mMonster.setHealth(0);
            else
                mMonster.setHealth(mMonster.getHealth()-dmg);
            magicTime = !magicTime;
        }
        else
        {
            dmg = mMonster.getAP();

            mBattleLog.push_back(mMonster.getName() + " attacks!");
            mBattleLog.push_back(mHero.getName() + " takes " + std::to_string(dmg) + " DMG!");

            if(dmg > mHero.getHealth())
                mHero.setHealth(0);
            else
                mHero.setHealth(mHero.getHealth()-dmg);
        }


        mT.clear();
        mT.printBattleBox(mHero, mMonster, 20,1);
        mT.printList(mBattleLog, false, 5, 15, 13, false, mBattleLog.size()-1);
        usleep(800000); //Wait a bit before next attack
        herosTurn = !herosTurn;
    }   

    //Battle DONE

    mT.setTextColor().red();
    mT.setFormat().bold();
    if(mHero.getHealth() == 0)
        mT.println("     " + mHero.getName() + " has been slain");
    else
        mT.println("     " + mMonster.getName() + " has been slain");

    mT.resetStyle();




    //If win: gain XP
    if(mMonster.getHealth() == 0)
    {

        mT.println("");
        mT.print("     " + mHero.getName() + " receives ");
        mT.setTextColor().yellow(); mT.print(std::to_string(mMonster.getKillXP()) + "XP ");
        mT.resetStyle(); mT.println("for winning");
        mHero.addXP(mMonster.getKillXP());

        while(true)
        {
            if(mHero.getXP() >= mHero.getLevel()*1000) //level up
            {
                mHero.levelUp();
                mT.setTextColor().green();
                mT.println("     " + mHero.getName() + " has reached level " + std::to_string(mHero.getLevel()) + "!");
                mT.resetStyle();
            }
            else
            {
                break;
            }
        }
    }
}
