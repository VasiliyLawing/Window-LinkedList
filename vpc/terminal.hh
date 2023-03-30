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

        void setGraphicMode(int width, int height);
        void setTextMode(const Resolution& resolution = Vpc::Resolutions::r80x45_1280x720, const Font& font = Vpc::Fonts::f16x16_13);

        void update();
        bool isCloseRequested() const {return m_closeRequested;}

        const std::string& getTitle() const {return m_title;}

        AbstractDisplay& getDisplay() const {return *m_pDisplay;}
        Input& getInput() const             {return *m_pInput;}

        operator bool() const {return !isCloseRequested();}
    };
}