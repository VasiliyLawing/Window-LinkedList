#include <vpc/input.hh>



namespace Vpc {
    Input::Input():
        m_eventBuffer(1024)
    {
    }


    void Input::processEvents(const SDL_Event& e) {
        if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
            m_eventBuffer.push_back(e);
            //Event event(KeyboardEventData(e.type == SDL_KEYDOWN, e.key.keysym));
            //event.m_data.m_keyboard.pressed = e.type == SDL_KEYDOWN;
        }

    }

/*
    Key Input::sdlKeySymToKey(const SDL_Keysym& keysym) {
        std::cerr << "key: " << e.key.type << " " << e.key.keysym.sym << std::endl;

        return Key(0, 0);
    }
*/

}
