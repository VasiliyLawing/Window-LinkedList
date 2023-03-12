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

    SDL_Init(SDL_INIT_VIDEO);
    m_sdlWindow = SDL_CreateWindow(m_title.c_str() , 0, 0, m_width, m_height, 0);
    m_renderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED);

    m_texture = SDL_CreateTexture(
        m_renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        m_width, m_height
    );

    m_thread = std::make_unique<std::thread>( [this] {threadFunc();} );
}

Display::~Display() {
    m_threadStopping = true;
    m_thread->join();

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

        Uint32 *pixels = (Uint32 *)malloc(m_width * m_height * sizeof(*pixels));
        /* fill buffer with blue pixels */

        int color = 0;

        for (int y = 0; y < m_height; y++) {
            Uint32 *row = pixels + y * m_width;
            for (int x = 0; x < m_width; x++) {
                row[x] = 0xFF << 3*8 | color;

                if(color == 0xFFFFFF)
                    color = 0;
                else
                    color++;
            }
        }

        double update_begin = time_in_ms();
        SDL_UpdateTexture(m_texture, NULL, pixels, m_width * sizeof(*pixels));
        double update_end = time_in_ms();
        SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_NONE);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        free(pixels);
        double this_frame = time_in_ms();
        printf("frame took %fms\n", this_frame - last_frame);
        printf(" - update texture: %fms\n", update_end - update_begin);
        last_frame = this_frame;
    }
}
