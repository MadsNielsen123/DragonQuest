#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "terminal.h" //Uses ANSI to enable color ect. in the terminal
#include "databasehandler.h"
#include "character.h"
#include "hero.h"
#include "monster.h"
#include "battle.h"

int main()
{
    DatabaseHandler DH("root", "mads");
    Terminal t;
    std::string input;
    t.hideCursor();
    t.setTerminalSize(120,40);


    // ************* Start Screen
    //t.printStartScreen();
    //std::cin.ignore();      //Wait for ENTER-press
    t.clear();              //Clear Terminal

    // ************* Load Hero Screen
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

        t.setTextColor().green();
        t.println("[n] Start New Hero", 3,1);
        t.setTextColor().red();
        t.println("[x] Exit", 3,2);
        t.setTextColor().cyan();
        t.println("-------------- Heroes --------------", 3,4);
        t.resetStyle();
        t.printHeroNames(heroes, true, 1, 3, 5);
        t.setTextColor().cyan();
        t.println("   ------------------------------------");
        if(heroSelected > 0)
        {
            t.setTextColor().green();
            t.println("   [s] Start Game With Selected Hero");
        }
        t.setTextColor().white();
        t.setFormat().bold();
        t.showCursor();
        t.print("   Select your hero: ");
        t.resetStyle();
        std::getline(std::cin, input);

        try
        {
           heroSelected = stoi(input);          
        }
        catch(std::exception e)
        {
            if(heroSelected > 0 && (input == "s" || input == "S"))
            {
                break;
            }
            heroSelected = 0;
            if(input == "n" || input == "N")
            {
                 startNewHero = true;
                 break;
            }
            else if (input == "x" || input == "X")
            {
                 exit(0);
            }
        }

        if(heroSelected > heroes.size())
            heroSelected = 0;
    }
    t.clear();

    // ************* Load Hero
    Hero hero;
    if(startNewHero)
    {
        t.printHeroLogo(hero.getName(), hero.getHP(), hero.getAP()); //Default values
        t.setFormat().bold();
        t.print("Enter New Hero's Name: ", 3,1);
        std::getline(std::cin, input);
        hero.setName(input);
        t.clear();
        hero.setID(DH.addHero(hero));
        hero.heal();
    }
    else
    {
        hero = heroes[heroSelected-1];
    }

    // ************* Game Running
    std::vector<Monster> monsters;
    enum class GameState
    {
            MENU,
            HERO_INFO,
            MONSTER_PICK,
            MONSTER_BATTLE,
            GAME_OVER
    };

    GameState currentState = GameState::MENU;
    unsigned int monsterPicked = 0;

    while(currentState != GameState::GAME_OVER)
    {
        switch(currentState)
        {
            case GameState::MENU:

                while(true)
                {
                    //Print options
                    t.clear();
                    t.printPageTitle("Menu");
                    t.setFormat().underline();
                    t.println("Options", 5, 7);
                    t.resetStyle();
                    t.setTextColor().RGB(255, 150, 0);
                    t.println("[H] Hero Info", 5, 9);
                    t.setTextColor().RGB(255, 100, 0);
                    t.println("[B] Battle monster", 5, 10);
                    t.setTextColor().RGB(255, 0, 0);
                    t.println("[X] Exit", 5, 11);
                    t.resetStyle();
                    t.print("Select option: ", 5, 13);
                    std::getline(std::cin, input);

                    if(input == "x" || input == "X")
                    {
                        currentState = GameState::GAME_OVER;
                        break;
                    }
                    else if (input == "h" || input == "H")
                    {
                        currentState = GameState::HERO_INFO;
                        break;
                    }
                    else if (input == "b" || input == "B")
                    {
                        currentState = GameState::MONSTER_PICK;
                        break;
                    }

                }
                break;

            case GameState::HERO_INFO:
                //Print info
                t.clear();
                t.printPageTitle("Hero Info");
                t.printHeroLogo();
                t.setTextColor().RGB(255, 150, 0); t.setFormat().underline(); t.println(hero.getName(), 5, 8);
                t.resetStyle();

                t.println("Hero Stats:", 5, 10);
                t.resetStyle();
                t.setTextColor().yellow(); t.print("Level: ", 5, 11);
                t.setTextColor().white(); t.println(std::to_string(hero.getLevel()));
                t.setTextColor().yellow(); t.print("XP: ", 5, 12);
                t.setTextColor().white(); t.println(std::to_string(hero.getXP()));
                t.setTextColor().red(); t.print("HP: ", 5, 13);
                t.setTextColor().white(); t.println(std::to_string(hero.getHP()));
                t.setTextColor().RGB(255, 230, 0); t.print("AP: ", 5, 14);
                t.setTextColor().white(); t.println(std::to_string(hero.getAP()));

                t.setTextColor().yellow(); t.print("Level up in: ", 5, 16);
                t.setTextColor().white(); t.println(std::to_string(1000*hero.getLevel() - hero.getXP())+" XP");

                t.setFormat().blink();
                t.print("Press Enter to Return ...", 5, 32);
                t.hideCursor();
                std::cin.ignore();
                t.resetStyle();
                t.showCursor();
                currentState = GameState::MENU;

                break;

            case GameState::MONSTER_PICK:

                while(currentState == GameState::MONSTER_PICK)
                {
                    //Print info
                        t.clear();
                        t.printPageTitle("Pick A Battle");

                        t.setTextColor().RGB(255, 0, 0);
                        t.println("[X] Return to Menu", 5, 8);
                        t.resetStyle();

                        monsters = DH.getMonsters(); //Load monsters
                        t.printMonsterNames(monsters, true, hero.getLevel(), true, 5, 10);
                        t.println("");
                        t.print("     Select option: ");
                        std::getline(std::cin, input);

                        try
                        {
                           monsterPicked = stoi(input);
                        }
                        catch(std::exception e)
                        {
                            monsterPicked = 0;

                            if (input == "x" || input == "X")
                            currentState = GameState::MENU;
                        }

                        if(monsterPicked > monsters.size())
                            monsterPicked = 0;

                        if(monsterPicked > 0)
                            currentState = GameState::MONSTER_BATTLE;
                }

                break;

                case GameState::MONSTER_BATTLE:
                    {
                        t.clear();
                        t.hideCursor();
                        Battle battle(hero, monsters[monsterPicked-1]);
                        battle.start();

                        hero.heal();
                        monsters[monsterPicked-1].heal();


                        DH.saveHero(hero);
                        t.setFormat().blink();
                        t.print("Press Enter to continue ...", 5, 32);

                        std::cin.ignore();
                        t.resetStyle();
                        t.showCursor();
                        currentState = GameState::MONSTER_PICK;
                    }

                break;
            default:
                //do nothing
                break;
        }
    }

    // ************* Game OVER
    DH.saveHero(hero);
    return 0;
}

