#include "chunkgroup.hpp"

Chunk_Group::Chunk_Group(SDL_Renderer* renderer, Camera &camera, TextureHandler &textures) {
    this->renderer = renderer;
    this->camera = &camera;
    this->textures = &textures;
    // Temporary test; rendering 5 chunks
}

Chunk_Group::~Chunk_Group() {

}

void Chunk_Group::generate_chunk(int id) {
    // Generate the chunk if it hasn't been generated before
    if (std::find(loaded_chunks.begin(), loaded_chunks.end(), id) == loaded_chunks.end()) {
        Chunk temp_chunk(id, renderer, *textures, *camera);
        group.push_back(temp_chunk);

        loaded_chunks.push_back(id);
    }
}

void Chunk_Group::check_area() {
    const int surrounding = 5; // surroundings

    double id = 0;
    id = ceil(camera->get_x() / (8 * block_w));

    // Make number positive if negative and vice versa
    if (id > 0) {
        id *= -1;
    } else {
        id = abs(id);
    }

    // TODO make generate_chunk return a boolean so we can check ourselves if the chunk generated
    //      allowing us to generate one chunk per frame

    // Unload old chunks

    if (loaded_chunks.size() > (surrounding*2)+5) {
        std::sort(loaded_chunks.begin(), loaded_chunks.end());
        std::sort(group.begin(), group.end());
        if (id-surrounding-1 < loaded_chunks[0]) {
            loaded_chunks.erase(loaded_chunks.end()-1);
            group.erase(group.end()-1);
        }
        if (id+surrounding > loaded_chunks[loaded_chunks.size()-1]) {
            loaded_chunks.erase(loaded_chunks.begin());
            group.erase(group.begin());
        }
    }

    for (int i = surrounding*-1; i < surrounding; ++i) {
        generate_chunk(id+i);
    }
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
