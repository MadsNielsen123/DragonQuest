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
