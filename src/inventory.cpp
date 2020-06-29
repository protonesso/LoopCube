#include "inventory.hpp"

Inventory::Inventory(SDL_Renderer* renderer,
        TextureHandler &textures,
        EventHandler &events,
        int* WINDOW_W,
        int* WINDOW_H) : hotbar_slots{10}, max_slots{hotbar_slots*5}, visible{true}, show_inventory_menu{0},
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

    if (events->get_state()[4]) {
        show_inventory_menu = !show_inventory_menu;
    }
}

void Inventory::draw_inventory_menu() {
    if (show_inventory_menu) {
        int scale = 3;
        const int MAX_X = (*WINDOW_W - (170*scale))/2;
        const int MAX_Y = (*WINDOW_H - (95*scale))/2;
        
        SDL_Rect src{0, 0, 170, 95};
        SDL_Rect dest{MAX_X, MAX_Y, src.w*scale, src.h*scale};

        // First draw BG shadow
        SDL_Rect shadow{0, 0, *WINDOW_W, *WINDOW_H};
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 160);
        SDL_RenderFillRect(renderer, &shadow);

        // Render inventory menu
        SDL_RenderCopy(renderer, textures->get_texture(11), &src, &dest);

        std::vector<int> pos = get_hovered_pos(events->get_mouse_pos()[0], events->get_mouse_pos()[1], MAX_X, MAX_Y, true);
    }
}

std::vector<int> Inventory::get_hovered_pos(int x, int y, int corner_x, int corner_y, bool draw = false) {
    const int tile_size = 40;

    // Start gap
    const int sx_gap = 20;
    const int sy_gap = 22;

    // Splitter gap
    const int sp_gap = 8;
    int total = max_slots/10;

    
    // Loop through slots
    for (int i = 0; i < hotbar_slots; ++i) {
        for (int j = 0; j < total; ++j) {
            // Check collision

            int new_x = corner_x+(i*(tile_size+sp_gap)+sx_gap);
            int new_y = corner_y+(j*(tile_size+sp_gap)+sy_gap);

            if (collision(x, y, 1, 1,
                new_x, new_y, tile_size, tile_size)) {

                if (draw) {
                    SDL_Rect rect{new_x, new_y, tile_size, tile_size};
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 40);
                    SDL_RenderFillRect(renderer, &rect);
                }

                return std::vector<int>{i, j};
            }
        }
    }

    
    
    return std::vector<int>{-1, -1};
}

bool Inventory::collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
    SDL_Rect r1{x1, y1, w1, h1}, r2{x2, y2, w2, h2};

    if (r1.x < r2.x + r2.w &&
        r1.x + r1.w > r2.x &&
        r1.y < r2.y + r2.h &&
        r1.y + r1.h > r2.y) {
            return true;
        }
    return false;
}

bool Inventory::get_inventory_visibility() {
    return show_inventory_menu;
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
        SDL_RenderCopy(renderer, textures->get_texture(10), &src, &block);
    }
}