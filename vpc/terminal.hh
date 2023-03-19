#pragma once

#include <string>
#include <thread>
#include <atomic>

#include <vpc/display.hh>
#include <vpc/input.hh>


namespace Vpc {

    class Terminal {
        std::string m_title;
        std::unique_ptr<std::thread> m_thread;

        std::atomic<bool> m_turnedOn = false;
        std::atomic<bool> m_threadStopping = false;

        // created, destroyed and used only in uiThread!
        std::unique_ptr<AbstractDisplay>    m_pDisplay;
        std::unique_ptr<Input>              m_pInput;

    public:
        Terminal(const std::string& title = "Virtual Terminal"): m_title(title) {}
        ~Terminal();

        const std::string& getTitle() const {return m_title;}

        void turn(bool on);
        bool isTurnedOn() const { return m_turnedOn; }


        const AbstractDisplay& getDisplay() const {return *m_pDisplay;}

    private:
        void uiProcess();
    };
}