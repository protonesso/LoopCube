#ifndef CHUNKGROUP_HPP
#define CHUNKGROUP_HPP
#include <vector>

#include "chunk.hpp"


class Chunk_Group {
public:
    Chunk_Group() = default;
    Chunk_Group(SDL_Renderer* renderer, Camera &camera);
    ~Chunk_Group();

    void generate_chunk(int id);
    void render_all();
    void update_all();
private:
    std::vector<Chunk> group;

    SDL_Renderer* renderer;
    Camera* camera;
};


#endif // CHUNKGROUP_HPP
