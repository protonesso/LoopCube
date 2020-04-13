#include "block.hpp"

Block::Block() {}

Block::Block(int id, TextureHandler &textures, SDL_Renderer* renderer, Camera &camera, int x, int y)
    : Game_Object{id, textures, renderer, camera, (double)x, (double)y, block_w, block_h} {
    this->id = id;
}

double Block::get_x() const {
    return obj.x*obj.w + (camera->get_x());
}

double Block::get_y() const {
    return obj.y*obj.h + (camera->get_y());

}

void Block::update() {
    src.h = obj.h;
    src.w = obj.w;
    src.x = 0;
    src.y = 0;

    dest.h = src.h;
    dest.w = src.w;
    dest.x = get_x();
    dest.y = get_y();
}

void Block::render() {
    render_shadow(); // Note: When settings menu added, add option to disable shadow, it can be resource hungry
    SDL_RenderCopy(renderer, textures->get_texture(texture_id), &src, &dest);
}

void Block::render_shadow() {
    SDL_Rect shadow;
    shadow.x = dest.x + 10;
    shadow.y = dest.y + 10;
    shadow.w = obj.w;
    shadow.h = obj.h;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 40);
    SDL_RenderFillRect(renderer, &shadow);
}
