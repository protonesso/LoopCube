#include "gameobj.hpp"

Game_Object::Game_Object() {}

Game_Object::Game_Object(std::string image, SDL_Renderer* renderer, Camera &camera,
    double x, double y, double w, double h) : x_pos{x}, y_pos{y}, width{w}, height{h} {
    image_location = image;
    this->renderer = renderer;
    // Camera needs to be a pointer incase another object changes the camera
    this->camera = &camera;

    texture = Texture::load(image.c_str(), renderer);
}

Game_Object::~Game_Object() {
    camera = nullptr;
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
    SDL_RenderCopy(renderer, texture, &src, &dest);
}
