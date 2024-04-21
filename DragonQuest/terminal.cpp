#include "terminal.h"
#include <iostream>
#include <iomanip>
#include <unistd.h>

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

Format Terminal::setFormat()
{
    return mFormat;
}

void Terminal::resetStyle()
{
    std::cout << "\033[0m";
}

void Terminal::clear()
{
    std::cout << "\033[2J\033[1;1H";
}

void Terminal::print(const std::string &text)
{
    std::cout << text;
}

void Terminal::println(const std::string &text)
{
    std::cout << text << std::endl;
}

void Terminal::setTerminalSize(unsigned int width, unsigned int height)
{
    std::cout << "\e[8;" + std::to_string(height) + ";"+ std::to_string(width) + "t";
}

void Terminal::printStartScreen()
{
    println(" _       __       __                                 __       ");
    println("| |     / /___   / /_____ ____   ____ ___   ___     / /_ ____ ");
    println("| | /| / // _ \\ / // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\");
    println("| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /");
    println("|__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ ");
    println("");
    println("");
    for(int i = 0; i<255; ++i)
    {
        setCursor(0, 7);
        mTextColor.RGB(i, 0, 0);
        println("██████╗ ██████╗  █████╗  ██████╗  ██████╗ ███╗   ██╗ ██████╗ ██╗   ██╗███████╗███████╗████████╗");
        println("██╔══██╗██╔══██╗██╔══██╗██╔════╝ ██╔═══██╗████╗  ██║██╔═══██╗██║   ██║██╔════╝██╔════╝╚══██╔══╝");
        println("██║  ██║██████╔╝███████║██║  ███╗██║   ██║██╔██╗ ██║██║   ██║██║   ██║█████╗  ███████╗   ██║   ");
        println("██║  ██║██╔══██╗██╔══██║██║   ██║██║   ██║██║╚██╗██║██║▄▄ ██║██║   ██║██╔══╝  ╚════██║   ██║");
        println("██████╔╝██║  ██║██║  ██║╚██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝╚██████╔╝███████╗███████║   ██║");
        println("╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝  ╚═▀▀═╝  ╚═════╝ ╚══════╝╚══════╝   ╚═╝");
        usleep(2000);
    }
    println("");
    mTextColor.blue();
    println("							                           - BY MADS");
    println("");
    resetStyle();

    println("");
    println("");
    print("█████████████████████████████████████ ");
    mFormat.blink();
    print("PRESS ENTER TO BEGIN");
    mFormat.noBlink();
    println(" █████████████████████████████████████████");

}

void Terminal::setCursor(unsigned int x, unsigned int y)
{
    std::string command = "\033["+std::to_string(y)+";"+std::to_string(x)+"H";
    std::cout << command;
}

void Terminal::hideCursor()
{
    std::cout << "\e[?25l";
}

void Terminal::showCursor()
{
    std::cout << "\e[?25h";
}
