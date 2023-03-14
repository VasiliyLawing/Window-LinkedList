#include "display.hh"

#include <sys/time.h>
#include <iostream>


static double time_in_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}


///////////////////////////
// AbstractDisplay
AbstractDisplay::AbstractDisplay(const std::string& title, int width, int height, int memorySize) {
    m_title = title;
    m_width = width;
    m_height = height;
    m_memorySize = memorySize;
    m_memory = new memory_t [memorySize];
}

AbstractDisplay::~AbstractDisplay() {
    if(isTurnedOn())
        turn(false);

    m_thread->join();
    delete[] m_memory;
}

void AbstractDisplay::turn(bool on) {
    if(on) {
        m_threadStopping = false;
        m_thread = std::make_unique<std::thread>([this] {
            uiProcess();
            m_turnedOn = false;
        });
    }
    else
        m_threadStopping = true;
}

void AbstractDisplay::uiProcessInit() {
    SDL_setenv("SDL_DEBUG", "1", 1);
    SDL_Init(SDL_INIT_EVERYTHING);

    m_sdlWindow = SDL_CreateWindow(m_title.c_str() , 0, 0, m_width, m_height, 0);
    m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    std::cerr << "WH: " << SDL_GetWindowSurface(m_sdlWindow)->h << std::endl;
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

        if(counter++ % 1000 == 0) {
            printf("frame took %fms\n", thisFrameTime - m_lastFrameTime);
        }

        m_lastFrameTime = thisFrameTime;
    }

    uiProcessShutdown();
}


//////////////////////////////
// GraphicDisplay
GraphicDisplay::GraphicDisplay(const std::string& title, int width, int height):
    AbstractDisplay(title, width, height, width * height)
{}

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
    if(m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }

    AbstractDisplay::uiProcessShutdown();
}


void GraphicDisplay::drawFrame() {
    int pitch;
    char* tex;
    SDL_LockTexture(m_texture, nullptr, (void**)&tex, &pitch);
    memcpy(tex, getMemory(), pitch * getHeight());
    SDL_UnlockTexture(m_texture);

    SDL_RenderCopy(getRenderer(), m_texture, NULL, NULL);
    SDL_RenderPresent(getRenderer());
}


////////////////////////
// TextDisplay
TextDisplay::TextDisplay(const std::string &title, const TextModeData& modeData):
    AbstractDisplay(
        title,
        modeData.columns * modeData.fontWidth, modeData.rows * modeData.fontHeight,
        modeData.columns * modeData.rows
    )
{
    m_textModeData = modeData;
}

void TextDisplay::uiProcessInit() {
    AbstractDisplay::uiProcessInit();

    m_fontTexture = IMG_LoadTexture(getRenderer(), m_textModeData.fontName.c_str());
    if(m_fontTexture == nullptr) {
        throw std::runtime_error("Cannot load font '" + m_textModeData.fontName + "'");
    }

    SDL_Point size;
    SDL_QueryTexture(m_fontTexture, NULL, NULL, &size.x, &size.y);
    m_columnsInTexture = size.x / m_textModeData.fontWidth;
}

void TextDisplay::uiProcessShutdown() {
    AbstractDisplay::uiProcessShutdown();

    if(m_fontTexture != nullptr) {
        SDL_DestroyTexture(m_fontTexture);
        m_fontTexture = nullptr;
    }
}

void TextDisplay::drawFrame() {
    for(int row = 0; row < m_textModeData.rows; ++row) {
        for (int col = 0; col < m_textModeData.columns; ++col) {
            drawCharacter(row, col);
        }
    }

    SDL_RenderPresent(getRenderer());
}

void TextDisplay::drawCharacter(int row, int column) {
    memory_t chData = getMemory()[row * m_textModeData.columns + column];
    int asciiCode = chData;
    int texIndex = asciiCode - (65-33);

    if(asciiCode != 0) {
        std::cerr << asciiCode << " " << texIndex << std::endl;
    }

    SDL_SetTextureColorMod(m_fontTexture, 0x0, 0x80, 0x0);

    int texRow = texIndex / m_columnsInTexture;
    int texColumn = texIndex % m_columnsInTexture;

    int chWidth = 16;
    int chHeight = 16;
    int padY = 5;
    int padX = 5;

    SDL_Rect srcRect, dstRect;
    srcRect.x = texColumn * m_textModeData.fontWidth;
    srcRect.y = texRow * m_textModeData.fontHeight;
    srcRect.w = chWidth;
    srcRect.h = chHeight;

    dstRect.x = padX + column * m_textModeData.fontWidth;
    dstRect.y = padY + row * m_textModeData.fontHeight;
    dstRect.w = chWidth;
    dstRect.h = chHeight;

    SDL_RenderCopy(getRenderer(), m_fontTexture, &srcRect, &dstRect);
}
