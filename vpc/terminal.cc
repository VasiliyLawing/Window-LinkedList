#include <vpc/terminal.hh>

#include <SDL2/SDL.h>


namespace Vpc {
    Terminal::Terminal(const std::string& title) {
        m_title = title;
        m_pInput = std::make_unique<Input>();
    }

    void Terminal::setGraphicMode(int width, int height) {
        m_pDisplay = std::make_unique<GraphicDisplay>(m_title, width, height);
    }

    void Terminal::setTextMode(const Resolution &resolution, const Font &font) {
        m_pDisplay = std::make_unique<TextDisplay>
            (m_title, resolution, font);
    }

    void Terminal::update() {
        if(m_pDisplay == nullptr)
            throw std::runtime_error("You must to set a display mode");

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
