#include <vpc/input.hh>
#include <iostream>


namespace Vpc {

    void Input::processEvents(const SDL_Event& e) {
        if(e.type == SDL_TEXTINPUT && e.text.text[0] != 0) {
            CharEvent event(e.text.text[0]);
            handleEvent(event);
        }
        else if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
            if(!std::isprint(e.key.keysym.sym)) {
                KeyEvent event(e.type == SDL_KEYDOWN, sdlKeySymToKey(e.key.keysym));
                handleEvent(event);
            }
        }
    }

    void Input::handleEvent(const Event &e) const {
        if(m_eventHandler != nullptr)
            m_eventHandler(e);
    }

    Key Input::sdlKeySymToKey(const SDL_Keysym& keysym) {
        std::cerr << "key: " << keysym.sym << std::endl;

        auto mods = makeKeyModifiersFromSdl(keysym.mod);
        ascii_t ascii = (keysym.sym > 0 && keysym.sym <= 255) ? keysym.sym : 0;

        if(isalpha(ascii) && mods.isShift())
            ascii = toupper(ascii);

        return Key(ascii, 0, mods);
    }

    KeyModifiers Input::makeKeyModifiersFromSdl(std::uint16_t keyMod) {
        return KeyModifiers(
            (keyMod & (KMOD_LSHIFT | KMOD_RSHIFT)) != 0,
            (keyMod & (KMOD_LCTRL | KMOD_RCTRL)) != 0,
            (keyMod & (KMOD_LALT | KMOD_RALT)) != 0,
            (keyMod & (KMOD_LGUI | KMOD_RGUI)) != 0
        );
    }

    void CharEvent::print(std::ostream &os) const {
        os
            << "CharEvent("
            << m_ch
            << ")"
            ;
    }

    void KeyEvent::print(std::ostream &os) const {
        os
            << "KeyEvent("
            << (isPressed() ? "pressed" : "released")
            << getCode() << ", "
            << getModifiers()
            << ")"
            ;
    }
}
