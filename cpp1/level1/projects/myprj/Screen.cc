//
// Created by bily101 on 8/23/23.
//

#include "Screen.hh"


Screen::Screen(const Vpc::TextDisplay& display) {
    displayMemory = (std::uint16_t*)display.getMemory();
    displayColumns = display.getColumns();
}


void Screen::drawRect(int x, int y, int width,int height, Color color) {
    for (int heightPt = y; heightPt < y+height; heightPt++)
        for (int widthPt = x; widthPt < x+width; widthPt++)
            set(widthPt, heightPt, ' ', color, color);
}

void Screen::set(int x, int y, const char text, const Color bgColor, const Color fgColor) {
    if (x > 106)
        std::cerr << "X VALUE IS OFF SCREEN" << std::endl;
    if (y > 25)
        std::cerr << "Y VALUE IS OFF SCREEN" << std::endl;

    auto collumnPointer = displayMemory + displayColumns * y;
    collumnPointer[x] = int(bgColor) << (8+4) | int(fgColor) << 8 | text;

}

void Screen::clear() {
    for (int x = 0; x <= 106; x++) {
        for (int y = 0; y < 25; y++) {
           set(x, y, ' ', Color::blackColor, Color::blackColor);
        }
    }
}




