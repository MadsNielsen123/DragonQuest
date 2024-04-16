#include <QCoreApplication>
#include <iostream>
#include <iomanip>
#include <string>
#include "terminal.h" //Uses ANSI to enable color ect. in the terminal

int main(int argc, char *argv[])
{
    Terminal t;

    t.setTextColor().red();
    t.setBackgroundColor().green();
    std::cout << "hej" << std::endl;
    t.resetStyle();
    return 0;
}

