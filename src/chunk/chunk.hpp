#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <iostream>
#include <array>
#include <cstdlib>
#include <time.h>
#include <SDL2/SDL.h>

#include "../constants/blockids.hpp"
#include "../gameobject/block.hpp"
#include "../math/perlin.hpp"
#include "../camera/camera.hpp"
#include "../texture/texturehandler.hpp"

class Chunk {

public:
    Chunk(unsigned long int seed, int slot, SDL_Renderer* renderer, TextureHandler &texture, Camera &camera);
    ~Chunk();
    // For std::sort
    bool operator<(const Chunk &c);

    void update_all();
    void render_all();
    void place_block(int id, int x, int y);
    void destroy_block(int x, int y);
    void generate_chunk();

    int get_slot();

    // Need to be able to view the chunk to do stuff such as collision detection
    std::vector<Block>* get_chunk();

private:
    int get_chunk_x(int x);
    int get_chunk_max_size();

    int MAX_WIDTH;
    int MAX_HEIGHT;
    std::vector<Block> chunk;
    int slot;
    PerlinNoise terrain_gen;

    SDL_Renderer* renderer;
    TextureHandler* textures;
    Camera* camera;
};


#endif // CHUNK_HPP
