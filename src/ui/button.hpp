#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include "../texture/texturehandler.hpp"
#include "../math/aabb.hpp"

class Button {
public:
    Button() = default;
    Button(int id, SDL_Renderer* renderer, TextureHandler &textures, int x, int y);
    ~Button();

    void update(int mouse_x, int mouse_y, int mouse_state);
    void render();

    // Text
    void set_text(std::string text);
    std::string get_text();
    bool get_pressed();
    int get_id();
private:
    SDL_Renderer* renderer;
    TextureHandler* textures;
    std::string text;
    unsigned int id;

    // Mouse state
    int x;
    int y;
    bool hovered;
    bool being_clicked;
    bool clicked;

    SDL_Rect src, dest;

};

#endif // BUTTON_HPP