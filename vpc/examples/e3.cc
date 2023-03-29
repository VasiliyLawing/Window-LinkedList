#include <vpc/terminal.hh>
#include <vpc/key.hh>
#include <iostream>


static void onKey(const Vpc::Event& event) {
    std::cerr << event << std::endl;

    const auto* keyEvent = dynamic_cast<const Vpc::KeyEvent*> (&event);
    if(keyEvent != nullptr) {
        std::cerr << "Got # " << keyEvent << std::endl;

        switch(keyEvent->getCode()) {
            using namespace Vpc;

            case KeyCodes::Return:
                std::cerr << "!!" << keyEvent << std::endl;
                break;
        }
    }
}


static void terminalTest() {
    Vpc::Terminal terminal("Virtual display");
    terminal.getInput().setKeyboardHandler(onKey);

    auto& display = dynamic_cast<Vpc::TextDisplay&> (terminal.getDisplay());
    auto* displayMemory = (std::uint16_t*)display.getMemory();

    while (terminal) {
        terminal.update();
        std::this_thread::sleep_for(std::chrono::milliseconds (1));
    }
}


int main() {
    terminalTest();
    std::cerr << "the end" << std::endl;
}
