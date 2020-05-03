#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL.h>
#include "bitmask.hpp"

class Input
{
public:
    enum class Key
    {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Esc = 5
    };

public:
    bool isKeyPressed(Key keycode);
    bool isKeyDown(Key keycode);
    bool isKeyUp(Key keycode);
    void update();

private:
    Bitmask thisFrameKeys;
    Bitmask lastFrameKeys;
};

bool Input::isKeyPressed(Key keycode) {
    return thisFrameKeys.GetBit((unsigned int)keycode);
}

bool Input::isKeyDown(Key keycode) {
    bool lastFrame = lastFrameKeys.GetBit((unsigned int)keycode);
    bool thisFrame = thisFrameKeys.GetBit((unsigned int)keycode);
    
    return thisFrame && !lastFrame;
}

bool Input::isKeyUp(Key keycode) {
    bool lastFrame = lastFrameKeys.GetBit((unsigned int)keycode);
    bool thisFrame = thisFrameKeys.GetBit((unsigned int)keycode);
    
    return !thisFrame && lastFrame;
}

void Input::update() {
    lastFrameKeys.SetMask(thisFrameKeys);

    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                bool on = (event.type == SDL_KEYDOWN);
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        thisFrameKeys.PutBit((unsigned int)Key::Left, on);
                        break;
                    case SDLK_RIGHT:
                        thisFrameKeys.PutBit((unsigned int)Key::Right, on);
                        break;
                    case SDLK_UP:
                        thisFrameKeys.PutBit((unsigned int)Key::Up, on);
                        break;
                    case SDLK_DOWN:
                        thisFrameKeys.PutBit((unsigned int)Key::Down, on);
                        break;
                    case SDLK_ESCAPE:
                        thisFrameKeys.PutBit((unsigned int)Key::Esc, on);
                        break;
                    default:
                        thisFrameKeys.PutBit((unsigned int)Key::None, on);
                        break;
                }
                break;
        }
    }
}

#endif // !INPUT_HPP