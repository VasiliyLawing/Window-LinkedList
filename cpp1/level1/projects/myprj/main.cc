#include <vpc/comp.hh>
#include "Screen.hh"
#include "Window.h"
#include "WindowsList.h"



int main () {

    Vpc::TextDisplay display("My Text display");
    Screen screen(display);
    Vpc::Comp comp(display);
    //WindowsList windows;

    Window w1(10, 10, 20, 10, screen);
    w1.addText("Window1");
    comp.update();
    getchar();
    w1.printAllText();

    Window w2(40, 10, 20, 10, screen);
    w2.addText("Window2");
    getchar();
    w2.printAllText();

    Window w3(70, 10, 20, 10, screen);
    w3.addText("Window3");
    comp.update();

    getchar();
    w3.printAllText();

    {
        Window w4(85, 10, 20, 10, screen);
        w4.addText("Window4");
        w4.printAllText();
        comp.update();
        getchar();

    }

    Window w4(85, 10, 20, 10, screen);
    w4.addText("Window5");
    w4.printAllText();

    comp.update();

    getchar();

    while (comp.update());
}

