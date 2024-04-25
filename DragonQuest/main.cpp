#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <string>
#include "terminal.h" //Uses ANSI to enable color ect. in the terminal
#include <vector>


int main()
{
    Terminal t;
    t.hideCursor();
    t.setTerminalSize(100,30);

    //Start Screen
    t.printStartScreen();
    std::cin.ignore();      //Wait for ENTER-press
    t.clear();              //Clear Terminal

    std::vector<std::string> heroes;

    heroes.push_back("Arnold");
    heroes.push_back("Ole");
    heroes.push_back("Svend");
    heroes.push_back("Rolf");
    heroes.push_back("Bjarne");
    heroes.push_back("Mads");
    heroes.push_back("Jonas");
    heroes.push_back("Nils");
    heroes.push_back("Kurt");
    heroes.push_back("Viktor");
    heroes.push_back("Ronald");
    heroes.push_back("Skrald");
    heroes.push_back("Mari");

    //Load Character Screen
    t.printList(heroes, -2, true, 12);
    t.printHeroLogo();
    std::cin.ignore();
    t.clear();

    return 0;
}

