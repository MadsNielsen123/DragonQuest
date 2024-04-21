#include "textcolor.h"
#include <iostream>
#include <string>

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

void TextColor::green()
{
    std::cout << "\033[32m";
}

void TextColor::black()
{
    std::cout << "\033[30m";
}

void TextColor::cyan()
{
    std::cout << "\033[36m";
}

void TextColor::white()
{
    std::cout << "\033[37m";
}

void TextColor::magenta()
{
    std::cout << "\033[35m";
}

void TextColor::blue()
{
    std::cout << "\033[34m";
}

void TextColor::RGB(unsigned int red, unsigned int green, unsigned int blue)
{
    std::string command = "\033[38;2;"+std::to_string(red)+";"+std::to_string(green)+";"+std::to_string(blue)+"m";
    std::cout << command;
}
