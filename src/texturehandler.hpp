#ifndef TEXTUREHANDLER_HPP
#define TEXTUREHANDLER_HPP
#include "texture.hpp"
#include "constants/blockids.hpp"
#include <algorithm>
#include <vector>
#include <utility>

#include <SDL2/SDL.h>

class TextureHandler {

public:
    TextureHandler() = default;
    TextureHandler(SDL_Renderer* renderer);
    ~TextureHandler();

    SDL_Texture* get_texture(int id);

private:
    SDL_Renderer* renderer;
    std::vector<std::pair<int, Texture>> textures;
};


#endif // TEXTUREHANDLER_HPP
