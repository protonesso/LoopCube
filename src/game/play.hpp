#ifndef PLAY_HPP
#define PLAY_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <ctime>

#include "../constants/blockids.hpp"
#include "../texture/texturehandler.hpp"
#include "../camera/camera.hpp"
#include "../event/eventhandler.hpp"
#include "../chunk/chunkgroup.hpp"
#include "../gameobject/player.hpp"
#include "../math/animation.hpp"

class Play {

public:
    Play() {};
    Play(SDL_Renderer* renderer, TextureHandler &textures, EventHandler &events, int *WINDOW_W, int *WINDOW_H);
    ~Play();

    void event_handler();
    void render();
    void update();
private:
    int *WINDOW_W;
    int *WINDOW_H;
    void handle_camera();
    void draw_selection(int* p1, int* p2);
    void print_mouse_pos();

    SDL_Renderer* renderer;
    TextureHandler* textures;
    EventHandler* events;
    Chunk_Group chunks;
    Camera camera;
    Player player;

    // Animations
    Animation fade;

};


#endif // PLAY_HPP
