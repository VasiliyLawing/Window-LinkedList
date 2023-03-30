#include <vpc/terminal.hh>
#include <iostream>


static std::uint16_t* displayMemory = nullptr;
static int charOffset = 0;
const int textColor = 2;
const int textBgColor = 0;


static void onKey(const Vpc::Event& event) {
    const auto* charEvent = dynamic_cast<const Vpc::CharEvent*> (&event);
    if(charEvent != nullptr) {
        if(charOffset > 160)
            charOffset = 0;

        displayMemory[charOffset] = textBgColor<<12 | textColor<<8 | charEvent->getChar();
        charOffset++;
    }


    const auto* keyEvent = dynamic_cast<const Vpc::KeyEvent*> (&event);
    if(keyEvent != nullptr && keyEvent->isPressed()) {
        switch(keyEvent->getCode()) {
            using namespace Vpc;

            case KeyCodes::Backspace:
                charOffset--;
                displayMemory[charOffset] = ' ';
                break;
        }
    }
}


static void terminalTest() {
    Vpc::Terminal terminal("Virtual display");
    terminal.setTextMode();
    terminal.getInput().setKeyboardHandler(onKey);

    auto& display = dynamic_cast<Vpc::TextDisplay&> (terminal.getDisplay());
    displayMemory = (std::uint16_t*)display.getMemory();

    while (terminal) {
        terminal.update();
        std::this_thread::sleep_for(std::chrono::milliseconds (1));
    }
}


int main() {
    terminalTest();
    std::cerr << "the end" << std::endl;
}
