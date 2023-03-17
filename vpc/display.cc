#include "display.hh"

#include <sys/time.h>
#include <iostream>

namespace Vpc {

    static double time_in_ms(void) {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
    }


///////////////////////////
// AbstractDisplay
    AbstractDisplay::AbstractDisplay(const std::string &title, int width, int height, int memorySize) {
        m_title = title;
        m_width = width;
        m_height = height;
        m_memorySize = memorySize;
        m_memory = new std::byte[memorySize];
    }

    AbstractDisplay::~AbstractDisplay() {
        if (isTurnedOn())
            turn(false);

        m_thread->join();
        delete[] m_memory;
    }

    void AbstractDisplay::turn(bool on) {
        if (on) {
            m_threadStopping = false;
            m_thread = std::make_unique<std::thread>([this] {
                uiProcess();
                m_turnedOn = false;
            });
        } else
            m_threadStopping = true;
    }

    void AbstractDisplay::uiProcessInit() {
        SDL_setenv("SDL_DEBUG", "1", 1);
        SDL_Init(SDL_INIT_EVERYTHING);

        m_sdlWindow = SDL_CreateWindow(m_title.c_str(), 0, 0, m_width, m_height, 0);
        m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    void AbstractDisplay::uiProcessShutdown() {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_sdlWindow);
    }

    void AbstractDisplay::uiProcess() {
        uiProcessInit();
        m_turnedOn = true;

        m_lastFrameTime = time_in_ms();

        int counter = 0;

        while (!m_threadStopping) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    return;
                }
            }

            drawFrame();

            double thisFrameTime = time_in_ms();

            if (counter++ % 1000 == 0) {
                printf("frame took %fms\n", thisFrameTime - m_lastFrameTime);
            }

            m_lastFrameTime = thisFrameTime;
        }

        uiProcessShutdown();
    }


//////////////////////////////
// GraphicDisplay
    GraphicDisplay::GraphicDisplay(const std::string &title, int width, int height) :
            AbstractDisplay(title, width, height, width * height * sizeof(std::uint32_t)) {}

    void GraphicDisplay::uiProcessInit() {
        AbstractDisplay::uiProcessInit();

        m_texture = SDL_CreateTexture(
                getRenderer(),
                SDL_PIXELFORMAT_ARGB8888,
                SDL_TEXTUREACCESS_STREAMING,
                getWidth(), getHeight()
        );

        SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_NONE);
    }

    void GraphicDisplay::uiProcessShutdown() {
        if (m_texture != nullptr) {
            SDL_DestroyTexture(m_texture);
            m_texture = nullptr;
        }

        AbstractDisplay::uiProcessShutdown();
    }


    void GraphicDisplay::drawFrame() {
        int pitch;
        char *tex;
        SDL_LockTexture(m_texture, nullptr, (void **) &tex, &pitch);
        memcpy(tex, getMemory(), pitch * getHeight());
        SDL_UnlockTexture(m_texture);

        SDL_RenderCopy(getRenderer(), m_texture, NULL, NULL);
        SDL_RenderPresent(getRenderer());
    }


////////////////////////
// TextDisplay
    TextDisplay::TextDisplay(const std::string &title, const Resolution& resolution, const Font &font) :
            AbstractDisplay(
                    title,
                    resolution.width, resolution.height,
                    resolution.columns * resolution.rows * sizeof(std::uint16_t)
            ) {
        m_font = font;
        m_resolution = resolution;
    }

    void TextDisplay::uiProcessInit() {
        AbstractDisplay::uiProcessInit();

        std::string fontFilename = std::string("vpc/") + m_font.filename;
        m_fontTexture = IMG_LoadTexture(getRenderer(), fontFilename.c_str());
        if (m_fontTexture == nullptr) {
            throw std::runtime_error("Cannot load font '" + fontFilename + "'");
        }

        SDL_Point size;
        SDL_QueryTexture(m_fontTexture, NULL, NULL, &size.x, &size.y);
        m_columnsInTexture = size.x / m_font.width;
    }

    void TextDisplay::uiProcessShutdown() {
        AbstractDisplay::uiProcessShutdown();

        if (m_fontTexture != nullptr) {
            SDL_DestroyTexture(m_fontTexture);
            m_fontTexture = nullptr;
        }
    }

    void TextDisplay::drawFrame() {
        for (int row = 0; row < m_resolution.rows; ++row) {
            for (int col = 0; col < m_resolution.columns; ++col) {
                drawCharacter(row, col);
            }
        }

        SDL_RenderPresent(getRenderer());
    }

    void TextDisplay::drawCharacter(int row, int column) {
        std::uint16_t* memory = (std::uint16_t*)getMemory();

        std::uint16_t chData = memory[row * m_resolution.columns + column];
        int asciiCode = chData & 0xFF;
        int texIndex = asciiCode - (65 - 33);

        SDL_SetTextureColorMod(m_fontTexture, 0x0, 0x80, 0x0);

        int texRow = texIndex / m_columnsInTexture;
        int texColumn = texIndex % m_columnsInTexture;

        int chWidth = 16;
        int chHeight = 16;

        int padX = (m_resolution.width - m_resolution.columns * m_font.width) / 2;
        int padY = (m_resolution.height - m_resolution.rows * m_font.height) / 2;

        SDL_Rect srcRect, dstRect;
        srcRect.x = texColumn * m_font.width;
        srcRect.y = texRow * m_font.height;
        srcRect.w = chWidth;
        srcRect.h = chHeight;

        dstRect.x = padX + column * m_font.width;
        dstRect.y = padY + row * m_font.height;
        dstRect.w = chWidth;
        dstRect.h = chHeight;

        SDL_RenderCopy(getRenderer(), m_fontTexture, &srcRect, &dstRect);
    }

    namespace Fonts {
        Vpc::Font f16x16_13 = {"font-16x16-13.png", 16, 16};
    }

    namespace Resolutions {
        Vpc::Resolution r120x67_1920x1080 = {1920, 1080, 120, 67};
        Vpc::Resolution r80x45_1920x1080 = {1280, 720, 80, 45};
    }
}