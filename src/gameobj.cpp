#include "gameobj.hpp"

Game_Object::Game_Object() {}

Game_Object::Game_Object(int texture_id, TextureHandler &textures, SDL_Renderer* renderer, Camera &camera,
    double x, double y, double w, double h) : x_pos{x}, y_pos{y}, width{w}, height{h} {
    this->texture_id = texture_id;
    this->renderer = renderer;
    // Camera needs to be a pointer incase another object changes the camera
    this->camera = &camera;
    this->textures = &textures;
}

Game_Object::~Game_Object() {
    //std::cout << "Well shit man" << std::endl;
    //SDL_DestroyTexture(texture);
}

double Game_Object::get_default_x() {
    return x_pos;
}

double Game_Object::get_default_y() {
    return y_pos;
}

double Game_Object::get_x() {
    return x_pos + (camera->get_x());
}

double Game_Object::get_y() {
    return y_pos + (camera->get_y());
}

bool Game_Object::out_of_view() {
    if (get_x()+width < 0 || get_y()+height < 0) {
        return true;
    }
    if (get_x() > camera->get_width() || get_y() > camera->get_height()) {
        return true;
    }
    return false;
}

void Game_Object::update() {
    src.h = height;
    src.w = width;
    src.x = 0;
    src.y = 0;

    dest.h = src.h;
    dest.w = src.w;
    dest.x = get_x();
    dest.y = get_y();
}

void Game_Object::render() {
    SDL_RenderCopy(renderer, textures->get_texture(texture_id), &src, &dest);
}
