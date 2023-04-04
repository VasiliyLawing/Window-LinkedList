#include <vpc/comp.hh>
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
    Vpc::TextDisplay display("Virtual display");
    Vpc::Comp comp(display);
    comp.getInput().setKeyboardHandler(onKey);

    displayMemory = (std::uint16_t*)display.getMemory();

    while (comp.update()) ;
}


int main() {
    terminalTest();
    std::cerr << "the end" << std::endl;
}
