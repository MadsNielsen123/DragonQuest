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
    setCursor(0,0);
    for(int y = 0; y< mTerminalSizeY-1; ++y)
    {
        for(int x = 0; x<mTerminalSizeX; ++x)
        {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    for(int x = 0; x<mTerminalSizeX; ++x)
    {
        std::cout << " ";
    }
    setCursor(0,0);
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
    mTerminalSizeX = width; mTerminalSizeY = height;
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
        usleep(5000);
    }
    mTextColor.blue();
    println("							                           - BY MADS");
    resetStyle();
    println("");
    println("");
    print("█████████████████████████████████████ ");
    mFormat.blink();
    print("PRESS ENTER TO BEGIN");
    mFormat.noBlink();
    println(" █████████████████████████████████████████");

}

void Terminal::printHeroLogo()
{
    unsigned int x = 50, y=0;
    mTextColor.RGB(200, 200, 200);
    mFormat.inverse();
    setCursor(x, y+1);
    println("████████████████                  █████████████████");
    setCursor(x, y+2);
    println("██████████████  ██████████████████  ███████████████");
    setCursor(x, y+3);
    println("█████████████ ██▒▒▒▒▒▒▒           ██   ████████████");
    setCursor(x, y+4);
    println("█████████████ ██▒▒▒▒▒▒▒▒▒▒          ██ ████████████");
    setCursor(x, y+5);
    println("█████████████ ██▒▒▒▒▒▒▒▒▒▒          ██ ████████████");
    setCursor(x, y+6);
    println("█████████████ ██▒▒▒▒██████████████  ██ ████████████");
    setCursor(x, y+7);
    println("█████████████ ██▒▒▒▒██████████████  ██ ████████████");
    setCursor(x, y+8);
    println("█████████████ ██▒▒▒▒▒▒▒▒░░████▒▒░░  ██ ████████████");
    setCursor(x, y+9);
    println("█████████████ ██▒▒▒▒▒▒    ████      ██ ████████████");
    setCursor(x, y+10);
    println("████          ██░░░░▒▒    ████      ██     ████████");
    setCursor(x, y+11);
    println("███  ███████████    ▒▒    ████      ██████   ██████");
    setCursor(x, y+12);
    println("███ ██  ▒▒    ▒▒██████████████████████▒▒▒▒██ ██████");
    setCursor(x, y+13);
    println("███ ██  ▒▒    ▒▒██▒▒▒▒████████████████▒▒  ██ ██████");
    setCursor(x, y+14);
    println("███ ████  ▒▒▒▒██    ██    ░░░░▒▒▒▒████████   ██████");
    setCursor(x, y+15);
    println("█ ████░░████████    ██    ░░░░▒▒▒▒████     ████████");
    setCursor(x, y+16);
    println("█ █████████░██████▒▒▒▒██    ░░▒▒████████        ███");
    setCursor(x, y+17);
    println("█ ██  █████░███████████████████████████████████    ");
    setCursor(x, y+18);
    println("██ ██░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████");
    setCursor(x, y+19);
    println("███ ███░░██░███████████████████████████████████    ");
    setCursor(x, y+20);
    println("█████ ██░░█░██████▒▒▒▒██▒▒▒▒▒▒██▒▒████          ███");
    setCursor(x, y+21);
    println("███████ █████ ██░░░░████  ░░████  ░░██ ████████████");
    setCursor(x, y+22);
    println("███████████ ██████████      ██████████ ████████████");
    setCursor(x, y+23);
    println("███████████ ████░░██ ████████ ████  ██ ████████████");
    setCursor(x, y+24);
    println("███████████ ██████ ████████████ ██████ ████████████");
    setCursor(x, y+25);
    println("██████████ ██████ ████████████████ ████ ███████████");
    setCursor(x, y+26);
    println("█████████ ██▒▒▒▒ ████████████████ ██▒▒▒▒ ██████████");
    resetStyle();

}

void Terminal::printList(const std::vector<std::string> &items, int printAmount, bool withArrow, unsigned int arrowIndex)
{
    if(printAmount < 0)
        printAmount = items.size();

    if (arrowIndex >= items.size())
        arrowIndex = items.size()-1;

    unsigned int i = 0, printCount = 0;
    if(printAmount < items.size())
    {
        if(printAmount/2 >arrowIndex)
            i = 0;
        else
            i = arrowIndex-(printAmount/2);
    }


    for( ; i<items.size(); ++i)
    {
        if(withArrow && i == arrowIndex)
            std::cout << "-> ";
        std::cout << items[i];
        std::cout << std::endl;
        printCount++;
            if(printCount == printAmount)
                break;
    }
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
