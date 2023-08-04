#include <vpc/comp.hh>
#include "iostream"

static std::uint16_t* displayMemory = nullptr;
static int charOffset = 0;
const int textColor = 2;
const int textBgColor = 0;
 int y = 0;

static void onKey(const Vpc::Event& event, void*) {

    const auto* charEvent = dynamic_cast<const Vpc::CharEvent*> (&event);
    if(charEvent != nullptr) {
        if(charOffset >= 25 && y < 10) {
            charOffset = 0;
            y++;
        }

        auto collPtr = displayMemory + 106  * y;

        if (y >= 10) {
            auto clearBottomPtr = displayMemory + 106  *  9;

            for (int height = 1; height <= 10; height++) {
                auto clearPtr = displayMemory + 106 * height;
                auto replacePtr = displayMemory + 106 * (height-1);

                for (int width = 0; width < 25; width+=1)
                    replacePtr[width] = clearPtr[width];


            }

            for (int single = 0; single < 25; single++) {
                clearBottomPtr[single] = 1<<12 | textColor<<8 | ' ';
            }
            y-=1;

        }

        collPtr[charOffset] = textBgColor<<12 | textColor<<8 | charEvent->getChar();
        charOffset++;
    }
}


int main () {
    Vpc::TextDisplay display("Virtual display");
    Vpc::Comp comp(display);

    comp.getInput().setKeyboardHandler(onKey);
    displayMemory = (std::uint16_t*)display.getMemory();

    for (int height = 0; height < 10; height++) {

        auto collPtr = displayMemory + display.getColumns() * height;

        for (int width = 0; width < 25; width++)
            collPtr[width] = 1 << (8+4) | 2 << 8 | ' ';

    }
    while(comp.update());
}