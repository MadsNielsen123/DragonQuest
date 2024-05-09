#include "battle.h"

Battle::Battle(Character& ch1, Character& ch2) : mCh1(ch1), mCh2(ch2)
{
    mT.setTerminalSize(120,40);
}

void Battle::start()
{

    mT.resetStyle();
    bool ch1Turn = true; //ch1 starts
    mT.printBattleBox(mCh1, mCh2, 20,1);

    mBattleLog.push_back("Battle Ready to begin");
    mT.printList(mBattleLog, false, 5, 15, 12, false, mBattleLog.size()-1);
    usleep(200000);
    mBattleLog.push_back("1..");
    mT.printList(mBattleLog, false, 5, 15, 12, false, mBattleLog.size()-1);
    usleep(800000);
    mBattleLog.push_back("2..");
    mT.printList(mBattleLog, false, 5, 15, 12, false, mBattleLog.size()-1);
    usleep(800000);
    mBattleLog.push_back("3..");
    mT.printList(mBattleLog, false, 5, 15, 12, false, mBattleLog.size()-1);
    usleep(800000);
    mBattleLog.push_back("FIGHT!");
    mT.printList(mBattleLog, false, 5, 15, 12, false, mBattleLog.size()-1);
    usleep(200000);


    //Battle ON
    while(mCh1.getHealth() > 0 && mCh2.getHealth() > 0)
    {

        if(ch1Turn)
        {
            mBattleLog.push_back(mCh1.getName() + " attacks!");
            mBattleLog.push_back(mCh2.getName() + " takes " + std::to_string(mCh1.getAP()) + " DMG!");

            if(mCh1.getAP() > mCh2.getHealth())
                mCh2.setHealth(0);
            else
                mCh2.setHealth(mCh2.getHealth()-mCh1.getAP());
        }
        else
        {
            mBattleLog.push_back(mCh2.getName() + " attacks!");
            mBattleLog.push_back(mCh1.getName() + " takes " + std::to_string(mCh2.getAP()) + " DMG!");

            if(mCh2.getAP() > mCh1.getHealth())
                mCh1.setHealth(0);
            else
                mCh1.setHealth(mCh1.getHealth()-mCh2.getAP());
        }


        mT.clear();
        mT.printBattleBox(mCh1, mCh2, 20,1);
        mT.printList(mBattleLog, false, 5, 15, 12, false, mBattleLog.size()-1);
        usleep(800000); //Wait a bit before next attack
        ch1Turn = !ch1Turn;
    }   

    //Battle DONE

    mT.setTextColor().red();
    mT.setFormat().bold();
    if(mCh1.getHealth() == 0)
        mT.println("     " + mCh1.getName() + " has been slain");
    else
        mT.println("     " + mCh2.getName() + " has been slain");

    mT.resetStyle();




    //If win: HERO VS MONSTER -> gain XP
    if(mCh2.getHealth() == 0)
    {
        Hero* hero = dynamic_cast<Hero*>(&mCh1);
        Monster* monster = dynamic_cast<Monster*>(&mCh2);

        if(hero && monster)
        {
            mT.println("");
            mT.print("     " + mCh1.getName() + " receives ");
            mT.setTextColor().yellow(); mT.print(std::to_string(monster->getKillXP()) + "XP ");
            mT.resetStyle(); mT.println("for winning");
            hero->addXP(monster->getKillXP());

            while(true)
            {
                if(hero->getXP() >= hero->getLevel()*1000) //level up
                {
                    hero->levelUp();
                    mT.setTextColor().green();
                    mT.println("     " + hero->getName() + " has reached level " + std::to_string(hero->getLevel()) + "!");
                    mT.resetStyle();
                }
                else
                {
                    break;
                }
            }
        }
    }
}
