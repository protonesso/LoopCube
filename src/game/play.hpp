#ifndef PLAY_HPP
#define PLAY_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include "../constants/blockids.hpp"
#include "../texture/texturehandler.hpp"
#include "../camera/camera.hpp"
#include "../chunk/chunkgroup.hpp"
#include "../gameobject/player.hpp"

class Play {

public:
    Play() {};
    Play(SDL_Renderer* renderer, TextureHandler &textures, int WINDOW_W, int WINDOW_H);
    ~Play();

    void event_handler();
    void render();
    void update();
private:
    int WINDOW_W;
    int WINDOW_H;
    void handle_camera();

    SDL_Renderer* renderer;
    TextureHandler* textures;
    Chunk_Group chunks;
    Camera camera;
    Player player;

};


#endif // PLAY_HPP
