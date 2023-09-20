//
// Created by bily101 on 8/25/23.
//

#include "Window.h"

Window* Window::firstWindow = nullptr;
int Window::length = 1;

Window::Window(int x, int y, int width, int height, Screen& windowScreen) : windowScreen(windowScreen) {
    windowX = x;
    windowY = y;

    windowWidth = width;
    windowHeight = height;
    windowColor = Color::blueColor;

    append();

    length++;

    draw();
}

void Window::draw() {
    windowScreen.drawRect(windowX, windowY, windowWidth, windowHeight, windowColor);
    print();
}

void Window::addText(const std::string& text) {
    windowString += text;
    print();
}

void Window::print() {
    std::string text = getText();
    int y = windowY;
    int xCursor = 0;
    for (int xCord = windowX; xCord < text.size()+windowX; xCord++) {
        if (xCursor+xCord >= windowX + windowWidth) {
            ++y;
            xCursor -= windowWidth;
        }
        windowScreen.set(xCursor+xCord, y, text.at(xCord - windowX), Color::blackColor, Color::whiteColor);
    }
}

void Window::setColor(Color color) {
    windowColor = color;
    draw();
}
void Window::append() {
    this->nextWindow = firstWindow;
    this->previousWindow = nullptr;

    if (firstWindow != nullptr)
        firstWindow->previousWindow = this;

    firstWindow = this;

    length++;
}


Window::~Window() {

    if (firstWindow == this)
        firstWindow = this->nextWindow;

    if (this->nextWindow != nullptr)
        this->nextWindow->previousWindow = this->previousWindow;

    if (this->previousWindow != nullptr)
        this->previousWindow->nextWindow = this->nextWindow;

    length--;
    windowScreen.clear();
    drawAll();
}



void Window::drawAll() {
    Window* currentWindow = firstWindow;
    std::cout << firstWindow << std::endl;

    while (currentWindow != nullptr) {
        currentWindow->draw();
        currentWindow = currentWindow->nextWindow;
    }
}
