#include "chunkgroup.hpp"

Chunk_Group::Chunk_Group(SDL_Renderer* renderer, Camera &camera) {
    this->renderer = renderer;
    this->camera = &camera;
    // Temporary test; rendering 5 chunks
    for(int i = 0; i < 5; ++i) {
        generate_chunk(i);
    }
}

Chunk_Group::~Chunk_Group() {

}

void Chunk_Group::generate_chunk(int id) {
    Chunk temp_chunk(id, renderer, *camera);
    group.push_back(temp_chunk);
}

void Chunk_Group::render_all() {
    for (auto &chunk: group) {
        chunk.render_all();
    }
}

void Chunk_Group::update_all() {
    for (auto &chunk: group) {
        chunk.update_all();
    }
}
