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

void Terminal::printCaveNames(const std::vector<Cave> &caves, unsigned int heroLevel, bool withIndex, unsigned int printX, unsigned int printY)
{
    for(int i = 0; i<caves.size(); ++i)
    {
        setCursor(printX, printY+i);
        mTextColor.white(); mFormat.bold();
        if(withIndex)
        {
            print(std::to_string(i+1) + ". ");
        }

        if(caves[i].isConquered())
           mFormat.strikeThrough();

        print(caves[i].getName());

        resetStyle();
        if(caves[i].isConquered())
        {
            print(" - CONQUERED ");
        }
        else if(caves[i].getLevel() < heroLevel)
        {
            mTextColor.RGB(50, 255, 0);
            print(" - Easy");
        }
        else if (caves[i].getLevel() == heroLevel || caves[i].getLevel() == heroLevel+1)
        {
            mTextColor.RGB(255, 255, 0);
            print(" - Intermediate");
        }
        else if (caves[i].getLevel() < heroLevel+3)
        {
            mTextColor.RGB(255, 150, 0);
            print(" - HARD");
        }
        else
        {
            mTextColor.red();
            print(" - Impossible");
        }
        resetStyle();
        println("");

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
            else if(text.at(c) == '.')
                print(mBT.DOT[i]);
            else if(text.at(c) == '!')
                print(mBT.EXC[i]);

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
    for(int i = 1; i<10; ++i)
    {
        setCursor(x, y+i); std::cout << "|" << std::flush;
        if(i>1)
        {
            setCursor(x+41, y+i); std::cout << "|" << std::flush;
        }
        setCursor(x+81, y+i); std::cout << "|" << std::flush;
    }
    setCursor(x+1, y+9);
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

    //Monster Type
    print("Type:", x+3+41, 5);
    for(int i = 0; i<ch2.getElementCount(); ++i)
    {
        mTextColor.RGB(ch2.getElementR(i), ch2.getElementG(i), ch2.getElementB(i));
        print(" " + ch2.getElementName(i));
    }



    //Stats
    resetStyle();    setCursor(x+3, 7);
    print(std::to_string(ch1.getAP()));
    mTextColor.yellow();
    print(" AP");

    resetStyle();
    setCursor(x+3+41, 7);
    print(std::to_string(ch2.getAP()));
    mTextColor.yellow();
    print(" AP");
    resetStyle();

    unsigned int g, r;
    //Character1 HP-Bar
    setCursor(x+3, 8);
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

    setCursor(x+3, 9);
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
    setCursor(x+3+41, 8);
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

    setCursor(x+3+41, 9);
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

void Terminal::printCaveEntry(const Cave &cave)
{
    hideCursor();

    for(int i = 0; i<220; ++i)
    {
        mTextColor.RGB(i, i/2, 0);
        printBigText("You Enter...", 20, 10);
        usleep(5000);
    }

    usleep(500000);

    for(int i = 220; i>0; --i)
    {
        mTextColor.RGB(i, i/2, 0);
        printBigText("You Enter...", 20, 10);
        usleep(2000);
    }

    clear();
    mTextColor.RGB(0, 0, 0);

    for(int i = 0; i<250; ++i)
    {
        mTextColor.RGB(i, 0, 0);
        printBigText(cave.getName(), 50-2.5*cave.getName().length(), 10);
        usleep(5000);
    }

    mTextColor.RGB(0, 0, 0);
    usleep(2000000);

    for(int i = 250; i>0; --i)
    {
        mTextColor.RGB(i, 0, 0);
        printBigText(cave.getName(), 50-2.5*cave.getName().length(), 10);
        usleep(2000);
    }
    showCursor();
}

void Terminal::printCaveReward(const Hero &hero, const Cave& cave)
{
    for(int i = 0; i<220; ++i)
    {
        mTextColor.RGB(i, i/2, 0);
        printBigText(cave.getName(), 50-2.5*cave.getName().length(), 5);
        usleep(5000);
    }

    for(int i = 0; i<220; ++i)
    {
        mTextColor.RGB(0, i, 0);
        printBigText("conquered!", 30, 9);
        usleep(1000);
    }

    resetStyle();
    print(hero.getName() + " receives: ", 5, 15);

    print(std::to_string(cave.getWinGold()), 5, 17);
    mTextColor.RGB(255, 220, 0);
    print(" GOLD");
    resetStyle();

    print(std::to_string(cave.getWinXP()), 5, 18);
    mTextColor.yellow();
    print(" Bonus XP");
    resetStyle();
}

void Terminal::printShop(const Hero &hero, std::vector<Magic> buyAbleMagics)
{
    //Print Hero cash
    mTextColor.RGB(255, 220, 0);
    printBigText("GOLD", 80, 9);
    resetStyle();
    mTextColor.RGB(255, 100, 0);
    print("   _....._", 78, 15);
    print("  ';-.--';'", 78, 16);
    print("    }===={       _.---.._", 78, 17);
    print("  .'      '.    ';-..--';", 78, 18);
    print(" /::        \\    `}===={", 78, 19);
    print("|::   $      :   '      '.", 78, 20);
    print("\\::.        _.---_        \\", 78, 21);
    print(" '::_     _`---..-';  $    |", 78, 22);
    print("     `````  }====={        /", 78, 23);
    print("          .'       '.   _.'", 78, 24);
    print("         /::         \\ `", 78, 25);
    print("        |::    $      |", 78, 26);
    print("        \\::.          /", 78, 27);
    print("         '::_      _.'", 78, 28);
    print("             ``````", 78, 29);
    print("-----------", 94, 14);
    print("-----------", 94, 16);
    mTextColor.RGB(255, 220, 0);
    print(std::to_string(hero.getGold()), 95, 15);
    resetStyle();


    //Print List
    unsigned int longestName = 0;

    for(Magic magic: buyAbleMagics)
    {
        if(longestName < magic.getName().length())
            longestName = magic.getName().length();
    }

    for(int i = 0; i<buyAbleMagics.size(); ++i)
    {
        print(std::to_string(i+1)+".", 5, 10+i);
        mTextColor.RGB(buyAbleMagics[i].getR(), buyAbleMagics[i].getG(), buyAbleMagics[i].getB());
        print(buyAbleMagics[i].getName(), 10, 10+i);
        resetStyle();
        print("[", 13+longestName, 10+i);
        mTextColor.RGB(buyAbleMagics[i].getR(), buyAbleMagics[i].getG(), buyAbleMagics[i].getB());
        print(buyAbleMagics[i].getElementName());
        resetStyle();
        print("]");
        print(std::to_string(buyAbleMagics[i].getBuyPrice()), 13+longestName+10, 10+i);
        mTextColor.RGB(255, 220, 0);
        print(" GOLD");
        if(buyAbleMagics[i].getRequiredID() > 0)
        {
            mTextColor.RGB(255, 50, 0);
            print("|UPGRADE|", 13+longestName+10+12, 10+i);
        }
        resetStyle();
    }
}

void Terminal::printEquipedMagics(const Hero &hero, std::vector<Magic> magics)
{
    //BOXES
    print("___________________ Not Equipped __________________", 6, 10);
    for(int i = 0; i<25; i++)
    {
        print("|", 5, 11+i);
        print("|", 57, 11+i);
    }
    print("___________________________________________________", 6, 35);

    print("____________________ Equipped _____________________", 60, 10);
    for(int i = 0; i<25; i++)
    {
        print("|", 59, 11+i);
        print("|", 111, 11+i);
    }
    print("___________________________________________________", 60, 35);

    //Print magics
    unsigned int eqCount = 0, ueqCount = 0;
    for(int i = 0; i<magics.size(); ++i)
    {

        if(!hero.magicIsEquiped(magics[i].getID()))
        {
            eqCount++;
            if(eqCount < 24) //print left
            {
                print(std::to_string(magics[i].getID())+". ", 7 ,11+eqCount);
                mTextColor.RGB(magics[i].getR(), magics[i].getG(), magics[i].getB());
                print(magics[i].getName());
                if(magics[i].getDamage() > 0)
                    print(" (" + std::to_string(magics[i].getDamage()).substr(0, std::to_string(magics[i].getDamage()).find(".") + 1 + 1) + "*MP)");
            }
            else //print right
            {
                print(std::to_string(magics[i].getID())+". ", 35 ,11+eqCount-23);
                mTextColor.RGB(magics[i].getR(), magics[i].getG(), magics[i].getB());
                print(magics[i].getName());
                if(magics[i].getDamage() > 0)
                    print(" (" + std::to_string(magics[i].getDamage()).substr(0, std::to_string(magics[i].getDamage()).find(".") + 1 + 1) + "*MP)");
            }

        }
        else
        {
            ueqCount++;
            if(ueqCount < 24) //print left
            {
                print(std::to_string(magics[i].getID())+". ", 61 , 11+ueqCount);
                mTextColor.RGB(magics[i].getR(), magics[i].getG(), magics[i].getB());
                print(magics[i].getName());
                if(magics[i].getDamage() > 0)
                    print(" (" + std::to_string(magics[i].getDamage()).substr(0, std::to_string(magics[i].getDamage()).find(".") + 1 + 1) + "*MP)");
            }
            else //print right
            {
                print(std::to_string(magics[i].getID())+". ", 88 , 11+ueqCount-23);
                mTextColor.RGB(magics[i].getR(), magics[i].getG(), magics[i].getB());
                print(magics[i].getName());
                if(magics[i].getDamage() > 0)
                    print(" (" + std::to_string(magics[i].getDamage()).substr(0, std::to_string(magics[i].getDamage()).find(".") + 1 + 1) + "*MP)");
            }
        }

        resetStyle();
    }

}
