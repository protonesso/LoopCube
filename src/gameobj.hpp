#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP
#include "texture.hpp"
#include "SDL2/SDL.h"
#include "string"
#include "camera.hpp"

class Game_Object {

public:
    Game_Object();
    Game_Object(std::string image, SDL_Renderer* renderer, Camera &camera, double x, double y, double w, double h);
    virtual ~Game_Object();

    virtual void update();
    virtual void render();
protected:
    double x_pos;
    double y_pos;
    double width;
    double height;
    std::string image_location;

    SDL_Renderer* renderer;
    SDL_Rect src, dest;
    SDL_Texture* texture;
    Camera* camera;

};


#endif // GAMEOBJ_HPP
