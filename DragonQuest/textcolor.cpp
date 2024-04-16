#include "textcolor.h"
#include <iostream>

TextColor::TextColor()
{

}


void TextColor::red()
{
    std::cout << "\033[31m";
}

void TextColor::yellow()
{
    std::cout << "\033[33m";
}

void TextColor::green(){
    std::cout << "\033[32m";
}
