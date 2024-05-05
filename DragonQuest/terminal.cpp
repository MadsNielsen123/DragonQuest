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

void Terminal::print(const std::string &text, int x, int y)
{
    if(x >= 0 && y >= 0)
        setCursor(x,y);
    std::cout << text << std::flush;
}

void Terminal::println(const std::string &text, int x, int y)
{
    if(x >= 0 && y >= 0)
        setCursor(x,y);
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

void Terminal::printHeroLogo(const std::string& name, unsigned int hp, unsigned int ap)
{
    unsigned int x = 55, y=2;
    if(name != "")
    {
        mTextColor.cyan();
        std::string shortName = name;
        shortName.resize(10);
        printBigText(shortName, x-5, y);
    }

    mTextColor.RGB(200, 200, 200);
    mFormat.inverse();
    setCursor(x, y+5);
    println("████████████████                  █████████████████");
    setCursor(x, y+6);
    println("██████████████  ██████████████████  ███████████████");
    setCursor(x, y+7);
    println("█████████████ ██▒▒▒▒▒▒▒           ██   ████████████");
    setCursor(x, y+8);
    println("█████████████ ██▒▒▒▒▒▒▒▒▒▒          ██ ████████████");
    setCursor(x, y+9);
    println("█████████████ ██▒▒▒▒▒▒▒▒▒▒          ██ ████████████");
    setCursor(x, y+10);
    println("█████████████ ██▒▒▒▒██████████████  ██ ████████████");
    setCursor(x, y+11);
    println("█████████████ ██▒▒▒▒██████████████  ██ ████████████");
    setCursor(x, y+12);
    println("█████████████ ██▒▒▒▒▒▒▒▒░░████▒▒░░  ██ ████████████");
    setCursor(x, y+13);
    println("█████████████ ██▒▒▒▒▒▒    ████      ██ ████████████");
    setCursor(x, y+14);
    println("████          ██░░░░▒▒    ████      ██     ████████");
    setCursor(x, y+15);
    println("███  ███████████    ▒▒    ████      ██████   ██████");
    setCursor(x, y+16);
    println("███ ██  ▒▒    ▒▒██████████████████████▒▒▒▒██ ██████");
    setCursor(x, y+17);
    println("███ ██  ▒▒    ▒▒██▒▒▒▒████████████████▒▒  ██ ██████");
    setCursor(x, y+18);
    println("███ ████  ▒▒▒▒██    ██    ░░░░▒▒▒▒████████   ██████");
    setCursor(x, y+19);
    println("█ ████░░████████    ██    ░░░░▒▒▒▒████     ████████");
    setCursor(x, y+20);
    println("█ █████████░██████▒▒▒▒██    ░░▒▒████████        ███");
    setCursor(x, y+21);
    println("█ ██  █████░███████████████████████████████████    ");
    setCursor(x, y+22);
    println("██ ██░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████");
    setCursor(x, y+23);
    println("███ ███░░██░███████████████████████████████████    ");
    setCursor(x, y+24);
    println("█████ ██░░█░██████▒▒▒▒██▒▒▒▒▒▒██▒▒████          ███");
    setCursor(x, y+25);
    println("███████ █████ ██░░░░████  ░░████  ░░██ ████████████");
    setCursor(x, y+26);
    println("███████████ ██████████      ██████████ ████████████");
    setCursor(x, y+27);
    println("███████████ ████░░██ ████████ ████  ██ ████████████");
    setCursor(x, y+28);
    println("███████████ ██████ ████████████ ██████ ████████████");
    setCursor(x, y+29);
    println("██████████ ██████ ████████████████ ████ ███████████");
    setCursor(x, y+30);
    println("█████████ ██▒▒▒▒ ████████████████ ██▒▒▒▒ ██████████");
    resetStyle();
    if(hp > 0 || ap > 0)
    {
        setCursor(x, y+32);
        std::string stats = "           [Health: " + std::to_string(hp) + "]    ";
        mTextColor.red();
        print(stats);
        mTextColor.RGB(255, 230, 0);
        stats = "[Attack: " + std::to_string(ap) + "]";
        println(stats);
        resetStyle();
    }
}

void Terminal::printList(const std::vector<std::string> &items, bool withIndex, unsigned int printX, unsigned int printY, int printAmount, bool withArrow, unsigned int arrowIndex)
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
        setCursor(printX, printY+printCount);
        if(withIndex)
            std::cout << i+1 << ". ";
        std::cout << items[i];
        if(withArrow && i == arrowIndex)
            std::cout << " <-";
        std::cout << std::endl;
        ++printCount;
            if(printCount == printAmount)
                break;
    }
}

void Terminal::setCursor(unsigned int x, unsigned int y)
{
    std::string command = "\033["+std::to_string(++y)+";"+std::to_string(++x)+"H";
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

void Terminal::saveCursorPos()
{
    std::cout << "\e 7";
}


void Terminal::gotoSavedCursorPos()
{
    std::cout << "\e 8";
}

void Terminal::printHeroNames(const std::vector<Hero> &heroes, bool withLevels, bool withIndex, unsigned int printX, unsigned int printY, int printAmount, bool withArrow, unsigned int arrowIndex)
{
    std::vector<std::string> heroNames;
    std::string temp;
    for(const Hero& hero: heroes)
    {
        temp = hero.getName();
        if(withLevels)
            temp += " (Level "+std::to_string(hero.getLevel())+ ")";
        heroNames.push_back(temp);
    }

    printList(heroNames, withIndex, printX, printY, printAmount, withArrow, arrowIndex);
}

void Terminal::printMonsterNames(const std::vector<Monster> &monsters, bool withLevels, unsigned int heroLevel, bool withIndex, unsigned int printX, unsigned int printY)
{
    for(int i = 0; i<monsters.size(); ++i)
    {
        setCursor(printX, printY+i);
        mTextColor.white(); mFormat.bold();
        if(withIndex)
        {
            print(std::to_string(i+1) + ". ");
        }
        print(monsters[i].getName());

        if(withLevels)
        {
            resetStyle();
            if(monsters[i].getLevel() < heroLevel)
                mTextColor.RGB(100, 255, 0);
            else if (monsters[i].getLevel() == heroLevel)
                mTextColor.RGB(220, 255, 0);
            else if (monsters[i].getLevel() <= heroLevel+2)
                mTextColor.RGB(255, 200, 0);
            else
                mTextColor.red();

            print(" - LVL " + std::to_string(monsters[i].getLevel()));
        }
        println("");
        resetStyle();
    }
}

void Terminal::printBigText(const std::string &text, unsigned int x, unsigned int y)
{
    for(int i=0; i<4; ++i)
    {
        setCursor(x, y+i);
        for(int c = 0; c<text.length(); c++)
        {
            if(text.at(c) == 'a' || text.at(c) == 'A')
                print(mBT.A[i]);
            else if(text.at(c) == 'b' || text.at(c) == 'B')
                print(mBT.B[i]);
            else if(text.at(c) == 'c' || text.at(c) == 'C')
                print(mBT.C[i]);
            else if(text.at(c) == 'd' || text.at(c) == 'D')
                print(mBT.D[i]);
            else if(text.at(c) == 'e' || text.at(c) == 'E')
                print(mBT.E[i]);
            else if(text.at(c) == 'f' || text.at(c) == 'F')
                print(mBT.F[i]);
            else if(text.at(c) == 'g' || text.at(c) == 'G')
                print(mBT.G[i]);
            else if(text.at(c) == 'h' || text.at(c) == 'H')
                print(mBT.H[i]);
            else if(text.at(c) == 'i' || text.at(c) == 'I')
                print(mBT.I[i]);
            else if(text.at(c) == 'j' || text.at(c) == 'J')
                print(mBT.J[i]);
            else if(text.at(c) == 'k' || text.at(c) == 'K')
                print(mBT.K[i]);
            else if(text.at(c) == 'l' || text.at(c) == 'L')
                print(mBT.L[i]);
            else if(text.at(c) == 'm' || text.at(c) == 'M')
                print(mBT.M[i]);
            else if(text.at(c) == 'n' || text.at(c) == 'N')
                print(mBT.N[i]);
            else if(text.at(c) == 'o' || text.at(c) == 'O')
                print(mBT.O[i]);
            else if(text.at(c) == 'p' || text.at(c) == 'P')
                print(mBT.P[i]);
            else if(text.at(c) == 'q' || text.at(c) == 'Q')
                print(mBT.Q[i]);
            else if(text.at(c) == 'r' || text.at(c) == 'R')
                print(mBT.R[i]);
            else if(text.at(c) == 's' || text.at(c) == 'S')
                print(mBT.S[i]);
            else if(text.at(c) == 't' || text.at(c) == 'T')
                print(mBT.T[i]);
            else if(text.at(c) == 'u' || text.at(c) == 'U')
                print(mBT.U[i]);
            else if(text.at(c) == 'v' || text.at(c) == 'V')
                print(mBT.V[i]);
            else if(text.at(c) == 'w' || text.at(c) == 'W')
                print(mBT.W[i]);
            else if(text.at(c) == 'x' || text.at(c) == 'X')
                print(mBT.X[i]);
            else if(text.at(c) == 'y' || text.at(c) == 'Y')
                print(mBT.Y[i]);
            else if(text.at(c) == 'z' || text.at(c) == 'Z')
                print(mBT.Z[i]);
            else if(text.at(c) == '\x91' || text.at(c) == '\x92')
                print(mBT.AE[i]);
            else if(text.at(c) == '\x9B' || text.at(c) == '\x9D')
                print(mBT.OE[i]);
            else if(text.at(c) == '\x86' || text.at(c) == '\x8F')
                print(mBT.AA[i]);
            else if(text.at(c) == ' ')
                print(mBT.SPACE[i]);

        }
    }
}

void Terminal::printPageTitle(const std::string &title)
{
    setCursor(0,0);
    std::cout << std::setw(mTerminalSizeX) << std::setfill('_') << "" << std::endl;
    mTextColor.cyan();
    mFormat.bold();
    printBigText(title, 1, 1);
    resetStyle();
    println("");
    std::cout << std::setw(mTerminalSizeX) << std::setfill('_') << "" << std::endl;
}

void Terminal::printBattleBox(const Character &ch1, const Character &ch2, unsigned int x, unsigned int y)
{

    //BOX
    setCursor(x+1, y);
    std::cout << std::setw(80) << std::setfill('_') << "" << std::flush;
    for(int i = 1; i<9; ++i)
    {
        setCursor(x, y+i); std::cout << "|" << std::flush;
        if(i>1)
        {
            setCursor(x+41, y+i); std::cout << "|" << std::flush;
        }
        setCursor(x+81, y+i); std::cout << "|" << std::flush;
    }
    setCursor(x+1, y+8);
    std::cout << std::setw(80) << std::setfill('_') << "" << std::flush;

    //Characters Names
    mFormat.underline();
    setCursor(x+3, y+2);
    print(ch1.getName());
    setCursor(x+3+41, y+2);
    print(ch2.getName());
    resetStyle();

    //Character Levels
    mFormat.bold();
    setCursor(x+30, y+2);
    print("Level " + std::to_string(ch1.getLevel()));
    setCursor(x+30+41, y+2);
    print("Level " + std::to_string(ch2.getLevel()));
    resetStyle();

    //Stats
    resetStyle();    setCursor(x+3, 5);
    print(std::to_string(ch1.getAP()));
    mTextColor.yellow();
    print(" AP");

    resetStyle();
    setCursor(x+3+41, 5);
    print(std::to_string(ch2.getAP()));
    mTextColor.yellow();
    print(" AP");
    resetStyle();

    unsigned int g, r;
    //Character1 HP-Bar
    setCursor(x+3, 7);
    print(std::to_string(ch1.getHealth()) + "/" + std::to_string(ch1.getHP()));
    mTextColor.red();
    print(" HP");
    resetStyle();

    if(ch1.getHealth() > ch1.getHP()/100.*50) //over 50% health
    {
        g = 255;
        r = 255-(255/100*(100./(ch1.getHP()/2.)*(ch1.getHealth()-ch1.getHP()/2.)));
    }
    else
    {
        r = 255;
        g = 255/50*(100./ch1.getHP()*ch1.getHealth());
    }

    setCursor(x+3, 8);
    print("|");
    mTextColor.RGB(r, g, 0);
    for(int i = 0; i<30; ++i)
    {
        if(ch1.getHealth() > ch1.getHP()/100.*(100./30*i))
            print("█");
        else
            print("_");
    }
    resetStyle();
    print("|");

    //Character2 HP-Bar
    setCursor(x+3+41, 7);
    print(std::to_string(ch2.getHealth()) + "/" + std::to_string(ch2.getHP()));
    mTextColor.red();
    print(" HP");
    resetStyle();

    if(ch2.getHealth() > ch2.getHP()/100.*50) //over 50% health
    {
        g = 255;
        r = 255-(255/100*(100./(ch2.getHP()/2.)*(ch2.getHealth()-ch2.getHP()/2.)));
    }
    else
    {
        r = 255;
        g = 255/50*(100./ch2.getHP()*ch2.getHealth());
    }

    setCursor(x+3+41, 8);
    print("|");
    mTextColor.RGB(r, g, 0);
    for(int i = 0; i<30; ++i)
    {
        if(ch2.getHealth() > ch2.getHP()/100.*(100./30*i))
            print("█");
        else
            print("_");
    }
    resetStyle();
    print("|");


    resetStyle();
}
