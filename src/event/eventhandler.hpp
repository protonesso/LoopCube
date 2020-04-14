#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <array>

// Easier wrapper for working with events in the game
class EventHandler {
public:
    EventHandler();
    ~EventHandler();

    void listen();

    std::vector<int> get_state();
    std::vector<SDL_Scancode> get_keys_set();
    std::array<int, 2> get_mouse_pos();
    int get_mouse_down();

    bool get_quit();

private:
    bool quit;
    /* Keyboard configuration
      [0] = up; default = SDL_SCANCODE_W
      [1] = right; default = SDL_SCANCODE_D
      [2] = down; default = SDL_SCANCODE_S
      [3] = left; default = SDL_SCANCODE_A
      [4] = inventory; default = SDL_SCANCODE_I
    */
    std::vector<SDL_Scancode> keys_set;
    std::vector<int> state;

    int mouse_x;
    int mouse_y;
    int mouse_down;

    SDL_Event event;
};

#endif // EVENTHANDLER_HPP
