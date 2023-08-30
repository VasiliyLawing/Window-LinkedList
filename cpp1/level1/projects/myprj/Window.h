#pragma once

#include "Screen.hh"
class Window {
    Screen& windowScreen;
    std::string windowString;

    int windowX;
    int windowY;
    int windowWidth;
    int windowHeight;

    Color windowColor;
public:
    Window(int x, int y, int width, int height, Screen &windowScreen);

    std::string getText() { return windowString; }
    void addText(const std::string& text);

    void print();
    void draw();
    void setColor(Color color);
};


