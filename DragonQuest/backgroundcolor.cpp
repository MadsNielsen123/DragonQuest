#include "backgroundcolor.h"
#include <iostream>

BackgroundColor::BackgroundColor()
{

}


void BackgroundColor::red()
{
    std::cout << "\033[41m";
}

void BackgroundColor::yellow()
{
    std::cout << "\033[43m";
}

void BackgroundColor::green(){
    std::cout << "\033[42m";
}

void BackgroundColor::black()
{
    std::cout << "\033[40m";
}

void BackgroundColor::cyan()
{
    std::cout << "\033[46m";
}

void BackgroundColor::white()
{
    std::cout << "\033[47m";
}

void BackgroundColor::magenta()
{
    std::cout << "\033[45m";
}

void BackgroundColor::blue()
{
    std::cout << "\033[44m";
}
