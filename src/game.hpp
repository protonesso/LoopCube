#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include "gameobj.hpp"
#include "texture.hpp"
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
    const int WINDOW_W = 800;
    const int WINDOW_H = 600;
    bool has_freed = false;
    bool is_running = false;

    SDL_Window* window;
    SDL_Renderer* renderer;

    Chunk_Group chunks;
    Camera camera;

    double view_x = 0; // TEMP values for testing the camera
    double view_y = 0;

};


#endif // GAME_HPP
