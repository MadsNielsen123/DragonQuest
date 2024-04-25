#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>
#include "textcolor.h"
#include "backgroundcolor.h"
#include "format.h"
#include <vector>

class Terminal
{
public:
    Terminal();

    void setTerminalSize(unsigned int width, unsigned int height);
    void print(const std::string &text);
    void println(const std::string &text);
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
    void printHeroLogo();
    void printList(const std::vector<std::string> &items, int printAmount = -1, bool withArrow = false, unsigned int arrowIndex = 0);

private:

    TextColor mTextColor;
    BackgroundColor mBackgroundColor;
    Format mFormat;
    unsigned int mTerminalSizeY, mTerminalSizeX;
};

#endif // TERMINAL_H
