#include "chunkgroup.hpp"

Chunk_Group::Chunk_Group(SDL_Renderer* renderer, Camera &camera) {
    this->renderer = renderer;
    this->camera = &camera;
    // Temporary test; rendering 5 chunks
}

Chunk_Group::~Chunk_Group() {

}

void Chunk_Group::generate_chunk(int id) {
    // Generate the chunk if it hasn't been generated before
    if (std::find(loaded_chunks.begin(), loaded_chunks.end(), id) == loaded_chunks.end()) {
        Chunk temp_chunk(id, renderer, *camera);
        group.push_back(temp_chunk);

        loaded_chunks.push_back(id);
        std::cout << "Generated chunk at " << id << std::endl;
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

    // Check if this id has been generated before
    // TODO make generate_chunk return a boolean so we can check ourselves if the chunk generated
    //      allowing us to generate one chunk per frame
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
