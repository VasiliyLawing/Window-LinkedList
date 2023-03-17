#include <vpc/display.hh>
#include <iostream>


void dispayTest() {
    Vpc::TextDisplay display("Virtual display", Vpc::Resolutions::r80x45_1280x720, Vpc::Fonts::f16x16_13);
    display.turn(true);
    auto* displayMemory = (std::uint16_t*)display.getMemory();

    const char* testText = "This is a hell of display!";

    int fgColor = 1;
    int bgColor = 0;

    for(int lineNum = 0; lineNum < 25; lineNum++) {
        typeof(displayMemory) rowPtr = displayMemory + display.getResolution().columns * lineNum;

        for (int col = 0; col < display.getResolution().columns && testText[col] != 0; col++) {
            rowPtr[col] = bgColor << (8+4) | fgColor << 8 | testText[col];

            if (fgColor < 16)
                fgColor++;
            else
                fgColor = 1;

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        if(bgColor < 16)
            bgColor++;
        else
            bgColor = 0;
    }

    std::this_thread::sleep_for(std::chrono::seconds (500));
}


int main() {
    dispayTest();
    std::cerr << "the end" << std::endl;
}
