#include <vpc/terminal.hh>
#include <iostream>


static void onKey(const Vpc::KeyboardEvent& event) {
    std::cerr << event.getKey().getAscii() << std::endl;
}


static void terminalTest() {
    Vpc::Terminal terminal("Virtual display");
    terminal.getInput().setKeyboardHandler(onKey);

    auto& display = dynamic_cast<Vpc::TextDisplay&> (terminal.getDisplay());
    auto* displayMemory = (std::uint16_t*)display.getMemory();

    const char* testText = "This is a hell of display!";

    int fgColor = 1;
    int bgColor = 0;

    for(int row = 0; row < display.getResolution().rows; row++) {
        typeof(displayMemory) rowPtr = displayMemory + display.getResolution().columns * row;

        const char* textPtr = testText;

        for (int col = 0; col < display.getResolution().columns; col++, textPtr++) {
            if(*textPtr == 0)
                textPtr = testText;

            rowPtr[col] = bgColor << (8+4) | fgColor << 8 | *textPtr;

            if (fgColor < 15)
                fgColor++;
            else
                fgColor = 1;

//            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        if(bgColor < 15)
            bgColor++;
        else
            bgColor = 0;
    }

    terminal.update();
    std::this_thread::sleep_for(std::chrono::seconds (500));
}


int main() {
    terminalTest();
    std::cerr << "the end" << std::endl;
}
