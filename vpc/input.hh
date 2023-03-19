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


    using KeyboardHandler = std::function<void(KeyboardEvent&)>;

    class Input {
        boost::circular_buffer<SDL_Event>   m_eventBuffer;
        KeyboardHandler                     m_keyboardHandler;

    public:
        Input();

        void setKeyboardHandler(KeyboardHandler handler) {
            m_keyboardHandler = handler;
        }

        // Only for internal use
        void processEvents(const SDL_Event& e);

    private:
//        Key sdlKeySymToKey(const SDL_Keysym& keysym);
    };
}