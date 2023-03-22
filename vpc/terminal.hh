#pragma once

#include <string>
#include <thread>
#include <atomic>

#include <vpc/display.hh>
#include <vpc/input.hh>


namespace Vpc {

    class Terminal {
        std::string m_title;

        std::unique_ptr<AbstractDisplay>    m_pDisplay;
        std::unique_ptr<Input>              m_pInput;

        bool m_closeRequested = false;

    public:
        Terminal(const std::string& title = "Virtual Terminal");

        void update();
        bool isCloseRequested() const {return m_closeRequested;}

        const std::string& getTitle() const {return m_title;}

        AbstractDisplay& getDisplay() const {return *m_pDisplay;}
        Input& getInput() const             {return *m_pInput;}

        operator bool() const {return !isCloseRequested();}
    };
}