#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <iostream>
#include <SDL2/SDL.h>

#include <vector>
#include <algorithm>
#include "../texture/texturehandler.hpp"
#include "../event/eventhandler.hpp"
#include "../constants/blockids.hpp"


class Inventory {
public:
    Inventory() = default;
    Inventory(SDL_Renderer* renderer,
        TextureHandler &textures,
        EventHandler &events,
        int* WINDOW_W,
        int* WINDOW_H);
    ~Inventory();

    void draw_hotbar();
    void update();
private:
    unsigned hotbar_slots;
    unsigned max_slots;
    bool visible;
    bool show_inventory_menu;
    int hotbar_pos;

    std::vector<int> slots;

    int* WINDOW_W;
    int* WINDOW_H;

    SDL_Renderer* renderer;
    TextureHandler* textures;
    EventHandler* events;
};

#endif // INVENTORY_HPP