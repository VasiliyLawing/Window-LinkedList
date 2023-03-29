#pragma once

#include <vpc/base.hh>
#include <SDL_keycode.h>

#include <iostream>


namespace Vpc {

    using ascii_t = std::uint8_t;
    using keyCode_t = std::uint32_t;


    class KeyModifiers {
        using mask_t = std::uint8_t;

        enum {
            shiftMask = 1,
            ctrlMask = 1<<1,
            altMask = 1<<2,
            winMask = 1<<3
        };

        mask_t m_mask;

    public:
        KeyModifiers(bool isShift, bool isCtrl, bool isAlt, bool isWin);

        bool isShift() const {return (m_mask & shiftMask) != 0;}
        bool isCtrl() const {return (m_mask & ctrlMask) != 0;}
        bool isAlt() const {return (m_mask & altMask) != 0;}
        bool isWin() const {return (m_mask & winMask) != 0;}
    };

    std::ostream& operator<< (std::ostream& os, KeyModifiers modifiers);

    // todo Add more keys. See: https://wiki.libsdl.org/SDL2/SDL_Keycode
    enum KeyCodes {
        Up          = SDLK_UP,
        Down        = SDLK_DOWN,
        Left        = SDLK_LEFT,
        Right       = SDLK_RIGHT,
        Return      = SDLK_RETURN,
        Delete      = SDLK_DELETE,
        Backspace   = SDLK_BACKSPACE,
        Home        = SDLK_HOME,
        F1          = SDLK_F1,
        F2          = SDLK_F2,
        F3          = SDLK_F3,
        F4          = SDLK_F4,
        F5          = SDLK_F5
    };
}
