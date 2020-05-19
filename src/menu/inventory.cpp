#include "inventory.hpp"

Inventory::Inventory(SDL_Renderer* renderer,
        TextureHandler &textures,
        EventHandler &events,
        int* WINDOW_W,
        int* WINDOW_H) : hotbar_slots{10}, max_slots{hotbar_slots*4}, visible{true}, show_inventory_menu{true},
            hotbar_pos{0}, WINDOW_W{WINDOW_W}, WINDOW_H{WINDOW_H} {
    this->renderer = renderer;
    this->textures = &textures;
    this->events = &events;
}

Inventory::~Inventory() {

}

void Inventory::update() {
    // hotbar_slot keys
    for (int i = 5; i < 15; ++i) {
        if (events->get_state()[i]) {
            hotbar_pos = i-5;
        }
    }
}

void Inventory::draw_hotbar() {
    const int BLOCK_S = 40;
    const int MAX_X = (*WINDOW_W - ((hotbar_slots+1)*BLOCK_S+3))/2;

    for (int i = 0; i < hotbar_slots; ++i) {
        SDL_Rect src{0, 0, 16, 16};
        if (hotbar_pos == i) {
            src.y = 16;
        }
        SDL_Rect block{i*(BLOCK_S+3)+MAX_X, 2, BLOCK_S, BLOCK_S};
        SDL_RenderCopy(renderer, textures->get_texture(sprite_start+6), &src, &block);
    }
}