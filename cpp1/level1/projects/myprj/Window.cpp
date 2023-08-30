//
// Created by bily101 on 8/25/23.
//

#include "Window.h"

Window::Window(int x, int y, int width, int height, Screen &windowScreen) : windowScreen(windowScreen) {
    windowX = x;
    windowY = y;
    windowWidth = width;
    windowHeight = height;
    windowColor = Color::blueColor;
}

void Window::draw() {
    windowScreen.drawRect(windowX, windowY, windowWidth, windowHeight, windowColor);
    print();
}
void Window::addText(const std::string& text) {
    windowString += text;
}

void Window::print() {
    std::string text = getText();
    int y = windowY;

    for (int xCord = windowX; xCord < text.size()+windowX; xCord++)
        windowScreen.set(xCord, y,text.at(xCord-windowX), Color::blackColor, Color::whiteColor);
}

void Window::setColor(Color color) {
    windowColor = color;
}
