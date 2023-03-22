#pragma once

#include <functional>

#include <SDL2/SDL.h>
#include <boost/circular_buffer.hpp>

#include <vpc/key.hh>


namespace Vpc {

    class KeyboardEvent {
        bool    m_isPressed;
        Key     m_key;

    public:
        KeyboardEvent(bool isPressed, const Key& key) {
            m_isPressed = isPressed;
            m_key       = key;
        }

        bool isPressed() const  {return m_isPressed;}
        Key getKey() const      {return m_key;}
    };


    using KeyboardHandler = std::function<void(const KeyboardEvent&)>;

    class KeyModefiers {
        using mask_t = std::uint8_t;

        enum {
            shiftMask = 1,
            ctrlMask = 1<<1,
            altMask = 1<<2,
            winMask = 1<<3
        };

        mask_t m_mask;

    public:
        KeyModefiers(bool isShift, bool isCtrl, bool isAlt, bool isWin);

        bool isShift() const {return (m_mask & shiftMask) != 0;}
        bool isCtrl() const {return (m_mask & ctrlMask) != 0;}
        bool isAlt() const {return (m_mask & altMask) != 0;}
        bool isWin() const {return (m_mask & winMask) != 0;}
    };

    class Input {
        KeyboardHandler m_keyboardHandler = nullptr;

        struct {
            bool
                isShift = false,
                isCftrl = false,
                isAlt   = false,
                isWin   = false
            ;
        } m_modefiers;

    public:
        void setKeyboardHandler(KeyboardHandler handler) {
            m_keyboardHandler = handler;
        }

        // Only for internal use
        void processEvents(const SDL_Event& e);

    private:
        Key sdlKeySymToKey(const SDL_Keysym& keysym);
        void updateKeyModefiers(const SDL_Event& e);
    };
}