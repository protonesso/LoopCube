#include "texturehandler.hpp"
#include <iostream>

TextureHandler::TextureHandler(SDL_Renderer* renderer) {
    this->renderer = renderer;

    for (auto &i: ids) {
        textures.push_back(std::make_pair(i.first, Texture{renderer, path+i.second+".png"}));
    }
}

TextureHandler::~TextureHandler() {
    // Delete all textures
}

SDL_Texture* TextureHandler::get_texture(int id) {
    for (auto &i: textures) {
        if (id == i.first) {
            return i.second.get_texture();
        }
    }
    return nullptr;
}
