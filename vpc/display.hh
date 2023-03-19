#pragma once

#include <string>
#include <thread>
#include <atomic>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vpc/base.hh>
#include <vpc/palette.hh>

namespace Vpc {

    class AbstractDisplay {
        std::string m_title;
        int         m_width;
        int         m_height;

        SDL_Window*    m_sdlWindow;
        SDL_Renderer*  m_renderer;

        std::byte*  m_memory = nullptr;
        int         m_memorySize;

        double m_lastFrameTime = 0;

    public:
        virtual ~AbstractDisplay();

        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        std::byte *getMemory() const { return m_memory; }
        int getMemorySize() const { return m_memorySize; }

        virtual void drawFrame() = 0;

    protected:
        AbstractDisplay(const std::string &title, int width, int height, int memorySize);

        SDL_Window *getWindow() { return m_sdlWindow; }
        SDL_Renderer *getRenderer() { return m_renderer; }
    };


    struct Font {
        std::string filename;
        int width;
        int height;
    };

    struct Resolution {
        int width;
        int height;
        int columns;
        int rows;
    };


    class GraphicDisplay : public AbstractDisplay {
        SDL_Texture *m_texture;

    public:
        GraphicDisplay(const std::string &title, int width, int height);
        ~GraphicDisplay();

        void drawFrame() override;
    };


    class TextDisplay : public AbstractDisplay {
    private:
        SDL_Texture *m_fontTexture = nullptr;

        Font m_font;
        Resolution m_resolution;

        int m_columnsInTexture;

        const Palette& m_palette;

    public:
        TextDisplay(const std::string &title, const Resolution &resolution, const Font &font);
        ~TextDisplay();

        const Resolution &getResolution() const { return m_resolution; }
        const Font &getFont() const { return m_font; }
        void drawFrame() override;

    private:
        void drawCharacter(int row, int column);
    };


    namespace Fonts {
        extern Vpc::Font f16x16_13;
    }


    namespace Resolutions {
        extern Vpc::Resolution r120x67_1920x1080;
        extern Vpc::Resolution r80x45_1280x720;
    }
}