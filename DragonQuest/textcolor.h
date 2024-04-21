#ifndef TEXTCOLOR_H
#define TEXTCOLOR_H


class TextColor
{
public:
    TextColor();

    void red();
    void yellow();
    void green();
    void cyan();
    void black();
    void magenta();
    void white();
    void blue();
    void RGB(unsigned int red, unsigned int green, unsigned int blue);
};

#endif // TEXTCOLOR_H
