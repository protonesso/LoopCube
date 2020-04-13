#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

// Easier wrapper for working with events in the game
class EventHandler {
public:
    EventHandler();
    ~EventHandler();

    void listen();

    std::vector<int> get_state();
    std::vector<SDL_Scancode> get_keys_set();

    bool get_quit();

private:
    bool quit;
    /* Keyboard configuration
      [0] = up; default = SDL_SCANCODE_UP
      [1] = right; default = SDL_SCANCODE_RIGHT
      [2] = down; default = SDL_SCANCODE_DOWN
      [3] = left; default = SDL_SCANCODE_LEFT
      [4] = inventory; default = SDL_SCANCODE_I
    */
    std::vector<SDL_Scancode> keys_set;
    std::vector<int> state;

    SDL_Event event;
};

#endif // EVENTHANDLER_HPP
