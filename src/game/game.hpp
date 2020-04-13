#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include "../constants/blockids.hpp"
#include "../texture/texturehandler.hpp"
#include "../event/eventhandler.hpp"
#include "play.hpp"

class Game {

public:
    Game();
    ~Game();

    void init(bool fullscreen);
    void game_init();
    void event_handler();
    void render();
    void update();
    bool running();
    void free();
private:
    const char* title;
    const int WINDOW_W = 800;
    const int WINDOW_H = 600;
    bool has_freed = false;
    bool is_running = false;

    Play* game;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TextureHandler textures;
    EventHandler events;
};


#endif // GAME_HPP
