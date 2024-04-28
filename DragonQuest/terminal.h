#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>
#include "textcolor.h"
#include "backgroundcolor.h"
#include "format.h"
#include <vector>
#include "hero.h"
#include "bigtext.h"

class Terminal
{
public:
    Terminal();

    void setTerminalSize(unsigned int width, unsigned int height);
    void print(const std::string &text, int x = -1, int y = -1);
    void println(const std::string &text, int x = -1, int y = -1);
    void setCursor(unsigned int x, unsigned int y);
    void hideCursor();
    void showCursor();
    void clear();

    //Font
    TextColor setTextColor();
    BackgroundColor setBackgroundColor();
    Format setFormat();
    void resetStyle();

    //Special Prints
    void printStartScreen();
    void printHeroLogo(const std::string& name, unsigned int hp, unsigned int ap);
    void printList(const std::vector<std::string> &items, bool withIndex = false, unsigned int printX = 0, unsigned int printY = 0 , int printAmount = -1, bool withArrow = false, unsigned int arrowIndex = 0);
    void printHeroNames(const std::vector<Hero> &heroes, bool withLevels = false, bool withIndex = false, unsigned int printX = 0, unsigned int printY = 0 , int printAmount = -1, bool withArrow = false, unsigned int arrowIndex = 0);
    void printBigText(const std::string &text, unsigned int x, unsigned int y);

private:

    TextColor mTextColor;
    BackgroundColor mBackgroundColor;
    Format mFormat;
    BigText mBT;
    unsigned int mTerminalSizeY, mTerminalSizeX;

};

#endif // TERMINAL_H
