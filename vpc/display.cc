#include "display.hh"

#include <sys/time.h>
#include <iostream>


static double time_in_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
}


Display::Display(const std::string &title, int width, int height) {
    m_title = title;
    m_width = width;
    m_height = height;

    SDL_setenv("SDL_DEBUG", "1", 1);
    SDL_Init(SDL_INIT_VIDEO);

    m_sdlWindow = SDL_CreateWindow(m_title.c_str() , 0, 0, m_width, m_height, 0);
    m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    m_texture = SDL_CreateTexture(
        m_renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        m_width, m_height
    );

    SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_NONE);

    m_memory = new Uint32[m_width * m_height];

    auto amountOfDrivers = SDL_GetNumVideoDrivers();
    for(int driverIdx = 0; driverIdx < amountOfDrivers; driverIdx++) {
        std::cerr << "driver: " << SDL_GetVideoDriver(driverIdx) << std::endl;
    }

    std::cerr << "current driver: " << SDL_GetCurrentVideoDriver() << std::endl;


    m_thread = std::make_unique<std::thread>( [this] {threadFunc();} );
}

Display::~Display() {
    m_threadStopping = true;
    m_thread->join();

    delete[] m_memory;

    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_sdlWindow);
}

void Display::threadFunc() {
    double last_frame = time_in_ms();

    while (!m_threadStopping) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                return;
            }
        }

        double update_begin = time_in_ms();
        int pitch;

        SDL_UpdateTexture(m_texture, NULL, m_memory, m_width * sizeof(pixel_t));
        double update_end = time_in_ms();

        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);

//        SDL_LockTexture(m_texture, nullptr, (void**)&m_memory, &pitch);

        double this_frame = time_in_ms();
//        printf("frame took %fms\n", this_frame - last_frame);
//        printf(" - update texture: %fms\n", update_end - update_begin);
        last_frame = this_frame;
    }
}
