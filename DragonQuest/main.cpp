#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "terminal.h" //Uses ANSI to enable color ect. in the terminal
#include "databasehandler.h"
#include "character.h"
#include "hero.h"

int main()
{
    DatabaseHandler DH("root", "mads");
    Terminal t;
    std::string input;
    t.hideCursor();
    t.setTerminalSize(120,40);


    //Start Screen
    //t.printStartScreen();



    //std::cin.ignore();      //Wait for ENTER-press
    t.clear();              //Clear Terminal

    //Load Character Screen
    std::vector<Hero> heroes = DH.getHeroes();
    unsigned int heroSelected = 0;
    bool startNewHero = false;

    while(true)
    {
        t.clear();
        if(heroes.size() > 0)
        {
            if(heroSelected > 0)
                t.printHeroLogo(heroes[heroSelected-1].getName(), heroes[heroSelected-1].getHP(), heroes[heroSelected-1].getAP());
            else
                t.printHeroLogo("", 0, 0);
        }

        t.setTextColor().cyan();
        t.println("-------------- Heroes --------------", 3,1);
        t.setTextColor().green();
        t.println("0. Start New Hero", 3,3);
        t.resetStyle();
        t.printHeroNames(heroes, true, 1, 3, 4);
        t.setTextColor().cyan();
        t.println("   ------------------------------------");
        t.setTextColor().white();
        t.setFormat().bold();
        t.showCursor();
        t.print("   Select your hero: ");
        std::getline(std::cin, input);
        try
        {
           heroSelected = stoi(input);
           if(heroSelected == 0)
           {
                startNewHero = true;
                break;
           }
        }
        catch(std::exception e)
        {
            heroSelected = 0;
        }

        if(heroSelected > heroes.size())
            heroSelected = 0;

    }

    return 0;
}

