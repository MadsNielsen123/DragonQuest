#include "format.h"
#include <iostream>

Format::Format(){}


void Format::underline()
{
    std::cout << "\033[4m";
}

void Format::noUnderline()
{
    std::cout << "\033[24m";
}

void Format::bold(){
    std::cout << "\033[1m";
}

void Format::noBold()
{
    std::cout << "\033[21m";
}


void Format::italic()
{
    std::cout << "\033[3m";
}

void Format::noItalic()
{
    std::cout << "\033[23m";
}

void Format::blink(){
    std::cout << "\033[5m";
}

void Format::noBlink()
{
    std::cout << "\033[25m";
}

void Format::dim(){
    std::cout << "\033[2m";
}

void Format::noDim()
{
    std::cout << "\033[22m";
}

void Format::strikeThrough()
{
    std::cout << "\033[9m";
}

void Format::noStrikeThrough()
{
    std::cout << "\033[29m";
}


