#include <vpc/terminal.hh>

#include <SDL2/SDL.h>

#include <iostream>


namespace Vpc {

    Terminal::~Terminal() {
        if (isTurnedOn())
            turn(false);

        m_thread->join();

    }

    void Terminal::turn(bool on) {
        if (on) {
            m_threadStopping = false;
            m_thread = std::make_unique<std::thread>([this] {
                uiProcess();
            });

            while (!m_turnedOn)
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
        } else
            m_threadStopping = true;
    }

    void Terminal::uiProcess() {
        m_pDisplay = std::make_unique<TextDisplay>(m_title, Vpc::Resolutions::r80x45_1280x720, Vpc::Fonts::f16x16_13);
        m_pInput = std::make_unique<Input>();

        m_turnedOn = true;

        while (!m_threadStopping) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    return;
                }
            }

            m_pInput->processEvents(e);
            m_pDisplay->drawFrame();
        }

        m_pInput = nullptr;
        m_pDisplay = nullptr;
        m_turnedOn = false;
    }
}