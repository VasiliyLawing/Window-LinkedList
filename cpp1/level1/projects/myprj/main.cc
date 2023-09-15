#include <vpc/comp.hh>
#include "Screen.hh"
#include "Window.h"



int main () {

    Vpc::TextDisplay display("My Text display");
    Screen screen(display);
    Vpc::Comp comp(display);

    Window w1(10, 10, 20, 10, screen);
    w1.addText("Window1221kkkkkkkkkkkkllkkkkkkkk");
    w1.addText("Window1221kkkkkkkkkkkkllkkkkkkkk");

    comp.update();
    getchar();

    {
        Window w2(13, 11, 20, 10, screen);
        w2.addText("Window2");
        w2.setColor(Color::brightGreenColor);
        comp.update();
        getchar();
    }
    comp.update();

    Window w3(70, 10, 20, 10, screen);
    w3.addText("Window3");
    comp.update();

    getchar();

    {
        Window w4(85, 10, 20, 10, screen);
        w4.addText("Window4");
        comp.update();
        getchar();

    }

    Window w4(85, 10, 20, 10, screen);
    w4.addText("Window5");

    comp.update();

    getchar();

    while (comp.update());
}

