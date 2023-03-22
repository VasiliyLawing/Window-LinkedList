#include <vpc/input.hh>
#include <iostream>


namespace Vpc {

    KeyModefiers::KeyModefiers(bool isShift, bool isCtrl, bool isAlt, bool isWin) {
        m_mask = 0;

        if(isShift)
            m_mask |= shiftMask;

        if(isCtrl)
            m_mask |= ctrlMask;

        if(isAlt)
            m_mask |= altMask;

        if(isWin)
            m_mask |= isWin;
    }


    void Input::processEvents(const SDL_Event& e) {
        if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
            Vpc::Input::updateKeyModefiers(e);

            KeyboardEvent event(e.type == SDL_KEYDOWN, sdlKeySymToKey(e.key.keysym));
            if(m_keyboardHandler != nullptr) {
                m_keyboardHandler(event);
            }
        }
    }

    void Input::updateKeyModefiers(const SDL_Event& e) {
        std::cerr << e.key.keysym.mod << " " << e.key.keysym.sym << std::endl;
    }

    Key Input::sdlKeySymToKey(const SDL_Keysym& keysym) {
        std::cerr << "key: " << keysym.sym << std::endl;

        return Key(0, 0);
    }

}
