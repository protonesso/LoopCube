#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <iostream>
#include <array>
#include <SDL2/SDL.h>

#include "block.hpp"
#include "camera.hpp"

class Chunk {

public:
    Chunk(int slot, SDL_Renderer* renderer, Camera &camera);
    ~Chunk();

    void update_all();
    void render_all();
    void place_block(int id, int x, int y);
    void generate_chunk();

private:
    std::array<Block, 1024> chunk;
    int slot;

    SDL_Renderer* renderer;
    Camera* camera;
};


#endif // CHUNK_HPP
