#ifndef TERMINAL_H
#define TERMINAL_H
#include <string>
#include "textcolor.h"
#include "backgroundcolor.h"

class Terminal
{
public:
    Terminal();

    void setTerminalSize(unsigned int width, unsigned int height);
    void printStartScreen();
    void print(const std::string &text);
    void println(const std::string &text);

    void clear();

    //Font
    TextColor setTextColor();
    BackgroundColor setBackgroundColor();
    void resetStyle();

private:

    TextColor mTextColor;
    BackgroundColor mBackgroundColor;
};

#endif // TERMINAL_H
