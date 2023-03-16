#include <vpc/display.hh>
#include <iostream>


void dispayTest() {
    Vpc::GraphicDisplay display("Virtual display", 1929, 1080);
    display.turn(true);

    auto* displayMemory = display.getMemory();

    int color = 0;

    while(true) {
        typeof(displayMemory) p = displayMemory;

        for (int i = 0; i < display.getWidth() * display.getHeight(); ++i) {
//            *p = 0xFF00FF00;
            *p = 0xFF00 << 8*2 | color << 8 | 0x00;
            p++;

//        std::this_thread::sleep_for(std::chrono::nanoseconds (1));

            if (color == 0xFF)
                color = 0;
            else
                color++;
        }
    }
}


int main() {
    dispayTest();
    std::cerr << "the end" << std::endl;
}
