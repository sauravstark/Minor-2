#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL.h>
#include "./Bitmask.hpp"

class Input
{
public:
    enum class Key
    {
        NONE = 0,
        LEFT = 1,
        RIGHT = 2,
        UP = 3,
        DOWN = 4,
        ESC = 5
    };

public:
    bool isKeyPressed(Key keycode);
    bool isKeyDown(Key keycode);
    bool isKeyUp(Key keycode);
    void updateInput();

private:
    BitMask this_frame_keys;
    BitMask last_frame_keys;
};

bool Input::isKeyPressed(Key keycode) {
    return this_frame_keys.getBit((unsigned int)keycode);
}

bool Input::isKeyDown(Key keycode) {
    bool last_frame_state = last_frame_keys.getBit((unsigned int)keycode);
    bool this_frame_state = this_frame_keys.getBit((unsigned int)keycode);
    
    return this_frame_state && !last_frame_state;
}

bool Input::isKeyUp(Key keycode) {
    bool last_frame_state = last_frame_keys.getBit((unsigned int)keycode);
    bool this_frame_state = this_frame_keys.getBit((unsigned int)keycode);
    
    return !this_frame_state && last_frame_state;
}

void Input::updateInput() {
    last_frame_keys.setMask(this_frame_keys);

    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                bool on = (event.type == SDL_KEYDOWN);
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        this_frame_keys.putBit((unsigned int)Key::LEFT, on);
                        break;
                    case SDLK_RIGHT:
                        this_frame_keys.putBit((unsigned int)Key::RIGHT, on);
                        break;
                    case SDLK_UP:
                        this_frame_keys.putBit((unsigned int)Key::UP, on);
                        break;
                    case SDLK_DOWN:
                        this_frame_keys.putBit((unsigned int)Key::DOWN, on);
                        break;
                    case SDLK_ESCAPE:
                        this_frame_keys.putBit((unsigned int)Key::ESC, on);
                        break;
                    default:
                        this_frame_keys.putBit((unsigned int)Key::NONE, on);
                        break;
                }
                break;
        }
    }
}

#endif // !INPUT_HPP