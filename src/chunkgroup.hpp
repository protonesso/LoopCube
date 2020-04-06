#ifndef CHUNKGROUP_HPP
#define CHUNKGROUP_HPP
#include <vector>
#include <cmath>
#include <algorithm>

#include "chunk.hpp"
#include "constants/blockids.hpp"
#include "texturehandler.hpp"

// TODO non-important Rename this properly
class Chunk_Group {
public:
    Chunk_Group() = default;
    Chunk_Group(SDL_Renderer* renderer, Camera &camera, TextureHandler &textures);
    ~Chunk_Group();

    void generate_chunk(int id);
    void check_area();
    void render_all();
    void update_all();
private:
    std::vector<Chunk> group;
    std::vector<int> loaded_chunks;

    SDL_Renderer* renderer;
    Camera* camera;
    TextureHandler* textures;
};


#endif // CHUNKGROUP_HPP
