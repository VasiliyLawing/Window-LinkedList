#pragma once

#include "iostream"
#include "string"
#include <vpc/comp.hh>
#include <cstdint>
#include <map>


enum class Color {
        blackColor = 0,blueColor =  1,
        greenColor = 2, cyanColor = 3,
        redColor = 4, purpleColor = 5,
        orangeColor = 6, whiteColor = 7,
        grayColor = 8, brightBlueColor = 9,
        brightGreenColor = 10, brightRedColor = 12,
        brightPurpleColor = 13, brightYellowColor = 14,
};

class Screen {
    std::uint16_t* displayMemory;
    int displayColumns;
    std::map<std::string, int> colors;

public:
    explicit Screen(const Vpc::TextDisplay& display);

    void clear();
    void drawRect(int x, int y, int width,int height, Color color);
    void set(int x, int y, char text, Color bgColor, Color fgColor);
};


