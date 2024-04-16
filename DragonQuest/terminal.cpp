#include "terminal.h"
#include <iostream>
#include <iomanip>

Terminal::Terminal()
{

}

TextColor Terminal::setTextColor()
{
    return mTextColor;
}

BackgroundColor Terminal::setBackgroundColor()
{
    return mBackgroundColor;
}

void Terminal::resetStyle()
{
    std::cout << "\033[0m";
}
