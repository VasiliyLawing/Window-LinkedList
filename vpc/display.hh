#pragma once

#include <string>
#include <thread>
#include <atomic>

#include <SDL2/SDL.h>


class Display {
public:
    using pixel_t = std::uint32_t;

private:
    std::string     m_title;
    int m_width;
    int m_height;

    SDL_Window*     m_sdlWindow;
    SDL_Renderer*   m_renderer;
    SDL_Texture*    m_texture;

    std::unique_ptr<std::thread> m_thread;
    std::atomic<bool> m_threadStopping = false;

    pixel_t* m_memory;

public:
    Display(const std::string& title, int width, int height);
    ~Display();

    int getWidth() const    {return m_width;}
    int getHeight() const   {return m_height;}

    pixel_t* getMemory() const {return m_memory;}

private:
    void threadFunc();
};