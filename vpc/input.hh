#pragma once

#include <functional>

#include <SDL2/SDL.h>

#include <vpc/key.hh>


namespace Vpc {

    class Event {
    public:
        virtual ~Event() = default;

        virtual void print(std::ostream& os) const = 0;
    };


    class CharEvent: public Event {
        char m_ch;

    public:
        explicit CharEvent(char ch) {m_ch = ch;}

        char getChar() const {return m_ch;}
        virtual void print(std::ostream& os) const override;
    };


    class KeyEvent: public Event {
        bool    m_isPressed;

        keyCode_t       m_code;
        KeyModifiers    m_modifiers;

    public:
        KeyEvent(bool isPressed, keyCode_t code, KeyModifiers modifiers):
            m_isPressed(isPressed),
            m_modifiers(modifiers),
            m_code(code)
        {}

        bool isPressed() const  {return m_isPressed;}
        keyCode_t getCode() const           {return m_code;}
        KeyModifiers getModifiers() const   {return m_modifiers;}

        virtual void print(std::ostream& os) const override;
    };

    inline std::ostream& operator<< (std::ostream& os, const Event& e) {
        e.print(os); return os;
    }


    using EventHandler = std::function<void(const Event&)>;


    class Input {
        EventHandler m_eventHandler = nullptr;

    public:
        void setKeyboardHandler(EventHandler handler) {
            m_eventHandler = handler;
        }

        // Only for internal use
        void processEvents(const SDL_Event& e);

    private:
        void handleEvent(const Event& e) const;
        static KeyModifiers makeKeyModifiersFromSdl(std::uint16_t);
    };
}