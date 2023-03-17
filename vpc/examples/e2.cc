#include <vpc/display.hh>
#include <iostream>


void dispayTest() {
    Vpc::TextDisplay display("Virtual display", Vpc::Resolutions::r80x45_1920x1080, Vpc::Fonts::f16x16_13);
    display.turn(true);
    auto* displayMemory = (std::uint16_t*)display.getMemory();

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
