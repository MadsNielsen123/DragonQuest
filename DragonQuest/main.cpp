#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <string>
#include "terminal.h" //Uses ANSI to enable color ect. in the terminal

int main(int argc, char *argv[])
{
    Terminal t;

    t.setTerminalSize(100,30);
    t.printStartScreen();

    std::cin.ignore();
    t.clear();
    std::cin.ignore();

    return 0;
}

