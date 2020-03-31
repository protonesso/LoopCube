#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <SDL2/SDL_image.h>

class Texture {

public:
    static SDL_Texture* load(const char* filename, SDL_Renderer* renderer);
};


#endif // TEXTURE_HPP
