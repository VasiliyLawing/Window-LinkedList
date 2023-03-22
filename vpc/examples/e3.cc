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

    while (terminal) {
        terminal.update();
        std::this_thread::sleep_for(std::chrono::milliseconds (1));
    }
}


int main() {
    terminalTest();
    std::cerr << "the end" << std::endl;
}
