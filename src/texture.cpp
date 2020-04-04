#include "texture.hpp"

Texture::Texture(SDL_Renderer* renderer, std::string filename) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    this->texture = texture;
}

SDL_Texture* Texture::get_texture() {
    return texture;
}

Texture::~Texture() {
   // SDL_DestroyTexture(texture);
}
