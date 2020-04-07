#include "chunk.hpp"

Chunk::Chunk(unsigned long int seed, int slot, SDL_Renderer* renderer, TextureHandler &textures, Camera &camera)
    : MAX_WIDTH{8}, MAX_HEIGHT{128}, terrain_gen{seed} {
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

int Chunk::get_chunk_x(int x) {
    return x+(slot*MAX_WIDTH);
}

int Chunk::get_chunk_max_size() {
    return MAX_WIDTH*MAX_HEIGHT;
}

int Chunk::get_slot() {
    return slot;
}

void Chunk::generate_chunk() {
    for (int x = 0; x < MAX_WIDTH; ++x) {
        double d_x = (double)x/(double)MAX_WIDTH;

        // Generate world
        int temp = floor(terrain_gen.noise(d_x+(slot), 0)*10);

        int offset = 30;
        for (int y = 0; y < MAX_HEIGHT-temp-offset; ++y) {
            double d_y = (double)y/(double)MAX_HEIGHT;
            if (y == 0) {
                place_block(0, x, y+temp+offset);
            } else if (y >= 1 && y <= 3) {
                place_block(1, x, y+temp+offset);
            } else {
                int cave_noise = terrain_gen.noise(d_x/2+(slot), d_y*12)*400;
                if (cave_noise < 150 && cave_noise > -150) {
                    place_block(2, x, y+temp+offset);
                }
            }
        }
    }

}

void Chunk::place_block(int id, int x, int y) {
    Block temp_block{id, *textures, renderer, *camera, get_chunk_x(x), y};
    // Check if between chunk size
    if ((int)chunk.size()+1 < get_chunk_max_size() || x < MAX_WIDTH || x > 0 || y < MAX_HEIGHT || y > 0) {
        // Check if a block has been placed here before
        bool is_duplicate = false;
        for (auto &i: chunk) {
            if (get_chunk_x(x) == i.get_default_x() && y == i.get_default_y()) {
                is_duplicate = true;
                break;
            }
        }
        if (!is_duplicate) {
            chunk.push_back(temp_block);
        } else {
            std::cout << "here" << std::endl;
        }
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
