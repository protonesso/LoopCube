#include "eventhandler.hpp"

EventHandler::EventHandler()
    : quit{false}, keys_set{SDL_SCANCODE_W, SDL_SCANCODE_D, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_I,
        SDL_SCANCODE_1, SDL_SCANCODE_2,
        SDL_SCANCODE_3, SDL_SCANCODE_4, SDL_SCANCODE_5,
        SDL_SCANCODE_6, SDL_SCANCODE_7, SDL_SCANCODE_8,
        SDL_SCANCODE_9, SDL_SCANCODE_0}, mouse_down{0} {
    state.resize(keys_set.size());
}

EventHandler::~EventHandler() {}

void EventHandler::listen() {



    while (SDL_PollEvent(&event)) {
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);

        // Set state for each key
        for (size_t i = 0; i < keys_set.size(); ++i) {
            if (keystate[keys_set[i]]) {
                state[i] = 1;
            } else {
                state[i] = 0;
            }
        }

        switch(event.type) {
            case SDL_KEYDOWN:
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouse_down = 1;
                break;
            case SDL_MOUSEBUTTONUP:
                mouse_down = 0;
                break;
            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&mouse_x, &mouse_y);
                break;
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
        }
    }
}

std::vector<int> EventHandler::get_state() {
    return state;
}

std::vector<SDL_Scancode> EventHandler::get_keys_set() {
    return keys_set;
}

std::array<int, 2> EventHandler::get_mouse_pos() {
    std::array<int, 2> i{mouse_x, mouse_y};
    return i;
}

int EventHandler::get_mouse_down() {
    return mouse_down;
}

SDL_Event EventHandler::get_event() {
    return event;
}

bool EventHandler::get_quit() {
    return quit;
}
