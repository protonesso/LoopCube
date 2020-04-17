#include "button.hpp"

Button::Button(int id, SDL_Renderer* renderer, TextureHandler &textures, int x, int y) : id{static_cast<unsigned int>(id)}, hovered{false} {
    this->renderer = renderer;
    this->textures = &textures;
    this->x = x;
    this->y = y;
}

Button::~Button() {}

void Button::update(int mouse_x, int mouse_y, int mouse_state) {
    src.h = 16;
    src.w = 16;
    src.x = 0;
    src.y = (static_cast<int>(hovered))*16;

    dest.h = src.h*2;
    dest.w = src.w*8;
    dest.x = x+32;
    dest.y = y;

    if (clicked == true) {
        clicked = false;
    }

    int calc_width = dest.w + (src.w*2)*2;
    if (AABB(mouse_x, mouse_y, 1, 1, x, y, calc_width, dest.h)) {
        hovered = true;
        if (mouse_state == 1) {
            dest.y += 5;
            being_clicked = true;
        } else {
            if (being_clicked == true) {
                clicked = true;
                being_clicked = false;
            }
        }

    } else {
        hovered = false;
        being_clicked = false;
        clicked = false;
    }
}

bool Button::get_pressed() {
    return clicked;
}

int Button::get_id() {
    return id;
}

void Button::render() {
    SDL_Rect begin{x, dest.y, src.w*2, dest.h}, end{dest.x+dest.w, dest.y, src.w*2, dest.h};
    SDL_RenderCopy(renderer, textures->get_texture(sprite_start+2), &src, &begin);
    SDL_RenderCopy(renderer, textures->get_texture(sprite_start+1), &src, &dest);
    SDL_RenderCopy(renderer, textures->get_texture(sprite_start+3), &src, &end);
}

void Button::set_text(std::string text) {
    this->text = text;
}

std::string Button::get_text() {
    return text;
}