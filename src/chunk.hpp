#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <iostream>
#include <array>
#include "SDL2/SDL.h"

#include "block.hpp"
#include "camera.hpp"

class Chunk {

public:
    Chunk(int slot, SDL_Renderer* renderer, Camera* camera);
    ~Chunk();

    void updateAll();
    void renderAll();
    void place_block(int id, int x, int y)

private:
    std::array<Block*, 1024> chunk;
    int slot;

    SDL_Renderer* renderer;
    Camera* camera;
};


#endif // CHUNK_HPP
