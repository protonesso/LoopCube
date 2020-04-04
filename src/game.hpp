#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include <time.h>

#include "gameobj.hpp"
#include "texturehandler.hpp"
#include "camera.hpp"
#include "block.hpp"
#include "chunkgroup.hpp"


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
    const int WINDOW_W = 1400;
    const int WINDOW_H = 600;
    bool has_freed = false;
    bool is_running = false;

    SDL_Window* window;
    SDL_Renderer* renderer;
    TextureHandler textures;

    Chunk_Group chunks;
    Camera camera;

    double view_x = 0; // TEMP values for testing the camera
    double view_y = 0;

};


#endif // GAME_HPP
