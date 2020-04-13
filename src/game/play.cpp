#include "play.hpp"

Play::Play(SDL_Renderer* renderer, TextureHandler &textures, EventHandler &events, int WINDOW_W, int WINDOW_H)
    : WINDOW_W{WINDOW_W}, WINDOW_H{WINDOW_H}, camera{WINDOW_W, WINDOW_H} {
    this->renderer = renderer;
    this->textures = &textures;
    this->events = &events;

    camera.set_pos(0, 125);


    unsigned long int seed = 1;
    // Configure camera
    player = Player(textures, renderer, camera);

    textures = TextureHandler(renderer);
    chunks = Chunk_Group(seed, renderer, camera, textures);
}

Play::~Play() {

}

void Play::update() {
    // Update all chunks
    chunks.update_all();
    chunks.check_area();

    // Set background
    SDL_SetRenderDrawColor(renderer, 0x7f, 0xc6, 0xdb, 255);

    // Update player
    player.update(chunks);

    for (int i = 0; i < 4; ++i) {
        if (events->get_state()[i]) {
            player.direct_player(i, chunks);
        }
    }


    // Update camera
    handle_camera();
}

void Play::render() {
    chunks.render_all();
    player.render();
}

void Play::handle_camera() {
    double x = (player.get_default_x()*-1 + (WINDOW_W/2)) - player.get_width()/2;
    double y = player.get_default_y()*-1 + (WINDOW_H/2) - player.get_height()/2;
    camera.set_pos(x, y);
}
