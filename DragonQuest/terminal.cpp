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
    mTextColor.red();
    println("██████╗ ██████╗  █████╗  ██████╗  ██████╗ ███╗   ██╗ ██████╗ ██╗   ██╗███████╗███████╗████████╗");
    println("██╔══██╗██╔══██╗██╔══██╗██╔════╝ ██╔═══██╗████╗  ██║██╔═══██╗██║   ██║██╔════╝██╔════╝╚══██╔══╝");
    println("██║  ██║██████╔╝███████║██║  ███╗██║   ██║██╔██╗ ██║██║   ██║██║   ██║█████╗  ███████╗   ██║   ");
    println("██║  ██║██╔══██╗██╔══██║██║   ██║██║   ██║██║╚██╗██║██║▄▄ ██║██║   ██║██╔══╝  ╚════██║   ██║");
    println("██████╔╝██║  ██║██║  ██║╚██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝╚██████╔╝███████╗███████║   ██║");
    println("╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝  ╚═▀▀═╝  ╚═════╝ ╚══════╝╚══════╝   ╚═╝");
    println("");
    mTextColor.green();
    println("							                           - BY MADS");
    println("");
    resetStyle();
    println("████████████████████████████████████████████████████████████████████████████████████████████████████");
    println("████████████████████████████████████████████████████████████████████████████████████████████████████");
    println("█████████████████████████████████████ PRESS ENTER TO BEGIN █████████████████████████████████████████");
    println("████████████████████████████████████████████████████████████████████████████████████████████████████");
    println("████████████████████████████████████████████████████████████████████████████████████████████████████");
    std::cout << "\033[19;59H"; //Set cursor
}
