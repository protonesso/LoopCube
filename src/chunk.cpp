#include "chunk.hpp"

Chunk::Chunk(int slot, SDL_Renderer* renderer, TextureHandler &textures, Camera &camera) {
    this->renderer = renderer;
    this->camera = &camera;
    this->textures = &textures;
    this->slot = slot;
    generate_chunk();
}

Chunk::~Chunk() {
}

bool Chunk::operator<(const Chunk &c) {
    if (slot < c.slot) {
        return true;
    }
    return false;
}


int Chunk::get_slot() {
    return slot;
}

void Chunk::generate_chunk() {
    size_t chunk_width = chunk.size()/128;
    size_t chunk_height = chunk.size()/8;
    int i = 0;

    // Seed chunk

    for (size_t x = 0; x < chunk_width; ++x) {
        for (size_t y = 0; y < chunk_height; ++y) {
            if (y == 0) {
                chunk[i] = Block(0, *textures, renderer, *camera, x+(slot*chunk_width), y);
            } else if (y >= 1 && y <= 3) {
                chunk[i] = Block(1, *textures, renderer, *camera, x+(slot*chunk_width), y+(rand() % 3));
            } else {
                chunk[i] = Block(2, *textures, renderer, *camera, x+(slot*chunk_width), y);

            }
            i++;
        }
    }

}

void Chunk::place_block(int id, int x, int y) {
    // TODO
    // Need to declare these to get rid of warnings
    std::cout << id << x << y << std::endl;

}

void Chunk::update_all() {
    for(size_t i = 0; i < chunk.size(); i++) {
        chunk[i].update();
    }
}

void Chunk::render_all() {
    for(size_t i = 0; i < chunk.size(); i++) {
        if (!chunk[i].out_of_view()) {
            chunk[i].render();
        }
    }
}
