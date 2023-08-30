#include <vpc/comp.hh>
#include "Screen.hh"
#include "Window.h"
#include "WindowsList.h"

int main () {
    Vpc::TextDisplay display("My Text display");
    Screen screen(display);
    WindowsList windows;


    Window w1(10, 10, 20, 10, screen);
    w1.setColor(Color::greenColor);

    Window w2(40,11,20,10,screen);
    Window w3(50,11,20,10,screen);
    w3.setColor(Color::whiteColor);

    w1.addText("First Window");
    w2.addText("Second Window");
    w3.addText("Third Window");

    windows.insert(&w1);
    windows.insert(&w2);
    windows.insert(&w3);

    windows.remove(2);


    windows.insert(&w1);


    while (true) {
        Vpc::Comp comp(display);

        windows.drawWindows();
        comp.update();
    }
}

