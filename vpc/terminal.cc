#include <vpc/terminal.hh>

#include <SDL2/SDL.h>


namespace Vpc {
    Terminal::Terminal(const std::string& title) {
        m_title = title;
        m_pDisplay = std::make_unique<TextDisplay>(m_title, Vpc::Resolutions::r80x45_1280x720, Vpc::Fonts::f16x16_13);
        m_pInput = std::make_unique<Input>();
    }

    void Terminal::update() {
        if(isCloseRequested())
            return;

        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                m_closeRequested = true;
                break;
            }

            m_pInput->processEvents(e);
        }

        m_pDisplay->drawFrame();
    }
}
