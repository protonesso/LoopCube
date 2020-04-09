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
}

double Game_Object::get_default_x() const {
    return x_pos;
}

double Game_Object::get_default_y() const {
    return y_pos;
}

double Game_Object::get_x() const {
    return x_pos + (camera->get_x());
}

double Game_Object::get_y() const {
    return y_pos + (camera->get_y());
}

double Game_Object::get_width() const {
    return width;
}

double Game_Object::get_height() const {
    return height;
}

bool Game_Object::out_of_view() {
    if (get_x()+(width*2) < 0 || get_y()+(height*2) < 0) {
        return true;
    }
    if (get_x()-width > camera->get_width() || get_y()-height > camera->get_height()) {
        return true;
    }
    return false;
}

void Game_Object::update() {
    src.h = height;
    src.w = width;
    src.x = get_default_x();
    src.y = get_default_y();

    dest.h = src.h;
    dest.w = src.w;
    dest.x = get_x();
    dest.y = get_y();
}

void Game_Object::render() {
    SDL_RenderCopy(renderer, textures->get_texture(texture_id), &src, &dest);
}

const SDL_Rect* Game_Object::get_src() const {
    return &dest;
}

bool operator==(const Game_Object &obj1, const Game_Object &obj2) {
    //bool test = SDL_IntersectRect(temp1.get_src(), temp2.get_src(), NULL);
    SDL_Rect r1, r2;

    r1.x = obj1.get_x();
    r1.y = obj1.get_y();
    r1.w = obj1.get_width();
    r1.h = obj1.get_height();

    r2.x = obj2.get_x();
    r2.y = obj2.get_y();
    r2.w = obj2.get_width();
    r2.h = obj2.get_height();

    if (r1.x < r2.x + r2.w &&
        r1.x + r1.w > r2.x &&
        r1.y < r2.y + r2.h &&
        r1.y + r1.h > r2.y) {
            return true;
        }
    return false;
}

bool operator!=(const Game_Object &obj1, const Game_Object &obj2) {
    return !(obj1 == obj2);
}
