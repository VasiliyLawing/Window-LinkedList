#include <vpc/display.hh>
#include <iostream>


void dispayTest() {
    Display display("Virtual display", 1929, 1080);
    auto* displayMemory = display.getMemory();

//    std::this_thread::sleep_for(std::chrono::seconds(10));


    long timeMs = 0;
    int delayMs = 1;

    typeof(displayMemory) p = displayMemory;

    int color = 0;

    while(true) {
        p = displayMemory;

        for (int i = 0; i < display.getWidth() * display.getHeight(); ++i) {
//            *p = 0xFF00FF00;
            *p = 0xFF00 << 8*2 | color << 8 | 0x00;
            p++;

//        std::this_thread::sleep_for(std::chrono::nanoseconds (delayMs));
            timeMs += delayMs;

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
