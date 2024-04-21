#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>
#include "textcolor.h"
#include "backgroundcolor.h"
#include "format.h"

class Terminal
{
public:
    Terminal();

    void setTerminalSize(unsigned int width, unsigned int height);
    void printStartScreen();
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

private:

    TextColor mTextColor;
    BackgroundColor mBackgroundColor;
    Format mFormat;
};

#endif // TERMINAL_H
