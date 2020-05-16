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
        ESC = 5,
		LSHIFT = 6,
		RSHIFT = 7,
		LCTRL = 8,
		RCTRL = 9,
		LALT = 10,
		RALT = 11,
		ALPH_A = 12,
		ALPH_B = 13,
		ALPH_C = 14,
		ALPH_D = 15,
		ALPH_E = 16,
		ALPH_F = 17,
		ALPH_G = 18,
		ALPH_H = 19,
		ALPH_I = 20,
		ALPH_J = 21,
		ALPH_K = 22,
		ALPH_L = 23,
		ALPH_M = 24,
		ALPH_N = 25,
		ALPH_O = 26,
		ALPH_P = 27,
		ALPH_Q = 28,
		ALPH_R = 29,
		ALPH_S = 30,
		ALPH_T = 31,
		ALPH_U = 32,
		ALPH_V = 33,
		ALPH_W = 34,
		ALPH_X = 35,
		ALPH_Y = 36,
		ALPH_Z = 37,
		NUM_0 = 38,
		NUM_1 = 39,
		NUM_2 = 40,
		NUM_3 = 41,
		NUM_4 = 42,
		NUM_5 = 43,
		NUM_6 = 44,
		NUM_7 = 45,
		NUM_8 = 46,
		NUM_9 = 47
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
					case SDLK_LSHIFT:
						this_frame_keys.putBit((unsigned int)Key::LSHIFT, on);
						break;
					case SDLK_RSHIFT:
						this_frame_keys.putBit((unsigned int)Key::RSHIFT, on);
						break;
					case SDLK_LCTRL:
						this_frame_keys.putBit((unsigned int)Key::LCTRL, on);
						break;
					case SDLK_RCTRL:
						this_frame_keys.putBit((unsigned int)Key::RCTRL, on);
						break;
					case SDLK_LALT:
						this_frame_keys.putBit((unsigned int)Key::LALT, on);
						break;
					case SDLK_RALT:
						this_frame_keys.putBit((unsigned int)Key::RALT, on);
						break;
					case SDLK_a:
						this_frame_keys.putBit((unsigned int)Key::ALPH_A, on);
						break;
					case SDLK_b:
						this_frame_keys.putBit((unsigned int)Key::ALPH_B, on);
						break;
					case SDLK_c:
						this_frame_keys.putBit((unsigned int)Key::ALPH_C, on);
						break;
					case SDLK_d:
						this_frame_keys.putBit((unsigned int)Key::ALPH_D, on);
						break;
					case SDLK_e:
						this_frame_keys.putBit((unsigned int)Key::ALPH_E, on);
						break;
					case SDLK_f:
						this_frame_keys.putBit((unsigned int)Key::ALPH_F, on);
						break;
					case SDLK_g:
						this_frame_keys.putBit((unsigned int)Key::ALPH_G, on);
						break;
					case SDLK_h:
						this_frame_keys.putBit((unsigned int)Key::ALPH_H, on);
						break;
					case SDLK_i:
						this_frame_keys.putBit((unsigned int)Key::ALPH_I, on);
						break;
					case SDLK_j:
						this_frame_keys.putBit((unsigned int)Key::ALPH_J, on);
						break;
					case SDLK_k:
						this_frame_keys.putBit((unsigned int)Key::ALPH_K, on);
						break;
					case SDLK_l:
						this_frame_keys.putBit((unsigned int)Key::ALPH_L, on);
						break;
					case SDLK_m:
						this_frame_keys.putBit((unsigned int)Key::ALPH_M, on);
						break;
					case SDLK_n:
						this_frame_keys.putBit((unsigned int)Key::ALPH_N, on);
						break;
					case SDLK_o:
						this_frame_keys.putBit((unsigned int)Key::ALPH_O, on);
						break;
					case SDLK_p:
						this_frame_keys.putBit((unsigned int)Key::ALPH_P, on);
						break;
					case SDLK_q:
						this_frame_keys.putBit((unsigned int)Key::ALPH_Q, on);
						break;
					case SDLK_r:
						this_frame_keys.putBit((unsigned int)Key::ALPH_R, on);
						break;
					case SDLK_s:
						this_frame_keys.putBit((unsigned int)Key::ALPH_S, on);
						break;
					case SDLK_t:
						this_frame_keys.putBit((unsigned int)Key::ALPH_T, on);
						break;
					case SDLK_u:
						this_frame_keys.putBit((unsigned int)Key::ALPH_U, on);
						break;
					case SDLK_v:
						this_frame_keys.putBit((unsigned int)Key::ALPH_V, on);
						break;
					case SDLK_w:
						this_frame_keys.putBit((unsigned int)Key::ALPH_W, on);
						break;
					case SDLK_x:
						this_frame_keys.putBit((unsigned int)Key::ALPH_X, on);
						break;
					case SDLK_y:
						this_frame_keys.putBit((unsigned int)Key::ALPH_Y, on);
						break;
					case SDLK_z:
						this_frame_keys.putBit((unsigned int)Key::ALPH_Z, on);
						break;
					case SDLK_0:
						this_frame_keys.putBit((unsigned int)Key::NUM_0, on);
						break;
					case SDLK_1:
						this_frame_keys.putBit((unsigned int)Key::NUM_1, on);
						break;
					case SDLK_2:
						this_frame_keys.putBit((unsigned int)Key::NUM_2, on);
						break;
					case SDLK_3:
						this_frame_keys.putBit((unsigned int)Key::NUM_3, on);
						break;
					case SDLK_4:
						this_frame_keys.putBit((unsigned int)Key::NUM_4, on);
						break;
					case SDLK_5:
						this_frame_keys.putBit((unsigned int)Key::NUM_5, on);
						break;
					case SDLK_6:
						this_frame_keys.putBit((unsigned int)Key::NUM_6, on);
						break;
					case SDLK_7:
						this_frame_keys.putBit((unsigned int)Key::NUM_7, on);
						break;
					case SDLK_8:
						this_frame_keys.putBit((unsigned int)Key::NUM_8, on);
						break;
					case SDLK_9:
						this_frame_keys.putBit((unsigned int)Key::NUM_9, on);
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