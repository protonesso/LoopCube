#include "texturehandler.hpp"
#include <iostream>

TextureHandler::TextureHandler(SDL_Renderer* renderer) {
    this->renderer = renderer;

    for (auto &i: ids) {
        textures.push_back(std::make_pair(i.first, Texture{renderer, path+i.second+".png"}));
    }
}

TextureHandler::~TextureHandler() {}

void TextureHandler::free_textures() {
    for (auto &i: textures) {
        i.second.free_texture();
    }
}

SDL_Texture* TextureHandler::get_texture(int id) {
    for (auto &i: textures) {
        if (id == i.first) {
            return i.second.get_texture();
        }
    }
    return nullptr;
}
