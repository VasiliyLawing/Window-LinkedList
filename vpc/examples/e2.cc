#include <vpc/display.hh>
#include <iostream>


void dispayTest() {
    TextModeData textModeData;
    textModeData.rows       = 25;
    textModeData.columns    = 80;
    textModeData.fontWidth  = 16;
    textModeData.fontHeight = 16;
    textModeData.fontName   = "vpc/font-16x16-13.png";

    TextDisplay display("Virtual display", textModeData);
    display.turn(true);
    auto* displayMemory = display.getMemory();

    const char* testText = "This is a hell of display!";
    typeof(displayMemory) p = displayMemory;

    for(int i = 0; testText[i] != 0; i++) {
        *p = testText[i];
        p++;
        std::this_thread::sleep_for(std::chrono::milliseconds (500));
    }

    std::this_thread::sleep_for(std::chrono::seconds (500));
}


int main() {
    dispayTest();
    std::cerr << "the end" << std::endl;
}
