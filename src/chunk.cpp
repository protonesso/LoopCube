#include "chunk.hpp"

Chunk::Chunk(int slot, SDL_Renderer* renderer, Camera &camera) {

    this->renderer = renderer;
    this->camera = &camera;
    this->slot = slot;
    int i = 0;

    size_t chunk_width = chunk.size()/128;
    size_t chunk_height = chunk.size()/8;

    for (size_t x = 0; x < chunk_width; ++x) {
        for (size_t y = 0; y < chunk_height; ++y) {
            chunk[i] = Block(0, renderer, camera, x+(slot*chunk_width), y);
            i++;
        }
    }
}

Chunk::~Chunk() {

}

void Chunk::update_all() {
    for(size_t i = 0; i < chunk.size(); i++) {
        chunk[i].update();
    }
}

void Chunk::render_all() {
    for(size_t i = 0; i < chunk.size(); i++) {
        chunk[i].render();
    }
}
