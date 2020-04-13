#include "eventhandler.hpp"

EventHandler::EventHandler()
    : quit{false}, keys_set{SDL_SCANCODE_UP, SDL_SCANCODE_RIGHT, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_I} {
    state.resize(keys_set.size());
}

EventHandler::~EventHandler() {};

void EventHandler::listen() {
    int pass = SDL_PollEvent(&event);

    const Uint8 *keystate = SDL_GetKeyboardState(NULL);

    // Set state for each key
    for (size_t i = 0; i < keys_set.size(); ++i) {
        if (keystate[keys_set[i]]) {
            state[i] = 1;
        } else {
            state[i] = 0;
        }
    }

    if (pass == 1) {
        switch(event.type) {
            case SDL_KEYDOWN:
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

bool EventHandler::get_quit() {
    return quit;
}
