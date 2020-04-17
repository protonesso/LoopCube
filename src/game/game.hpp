#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

#include "../constants/blockids.hpp"
#include "../texture/texturehandler.hpp"
#include "../event/eventhandler.hpp"
#include "play.hpp"
#include "../menu/menu.hpp"
#include "state.hpp"

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
    int WINDOW_W = 800;
    int WINDOW_H = 600;
    bool has_freed = false;
    bool is_running = false;

    State state;
    Play* game;
    Menu* menu;

    SDL_Window* window;
    SDL_Renderer* renderer;
    TextureHandler textures;
    EventHandler events;
};


#endif // GAME_HPP
