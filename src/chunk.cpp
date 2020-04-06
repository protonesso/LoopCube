#include "chunk.hpp"

Chunk::Chunk(int slot, SDL_Renderer* renderer, TextureHandler &textures, Camera &camera) : MAX_WIDTH{8}, MAX_HEIGHT{128} {
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
    int i = 0;

    // Seed chunk

    for (int x = 0; x < MAX_WIDTH; ++x) {
        for (int y = 0; y < MAX_HEIGHT; ++y) {
            if (y == 0) {

                place_block(0, x, y);
            } else if (y >= 1 && y <= 3) {
                place_block(1, x, y);
            } else {
                place_block(2, x, y);
            }
            i++;
        }
    }

}

void Chunk::place_block(int id, int x, int y) {
    Block temp_block{id, *textures, renderer, *camera, x+(slot*MAX_WIDTH), y};
    if ((int)chunk.size()+1 < MAX_HEIGHT*MAX_WIDTH || x < 8 || x > 0 || y < 128 || y > 0) {
        chunk.push_back(temp_block);
    } else {
        std::cerr << "[ERROR] Block placed too far" << std::endl;
    }

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
