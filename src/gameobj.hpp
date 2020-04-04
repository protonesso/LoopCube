#ifndef GAMEOBJ_HPP
#define GAMEOBJ_HPP
#include "texturehandler.hpp"
#include "SDL2/SDL.h"
#include <string>
#include "camera.hpp"

class Game_Object {

public:
    Game_Object();
    Game_Object(int texture_id, TextureHandler &textures, SDL_Renderer* renderer, Camera &camera, double x, double y, double w, double h);
    virtual ~Game_Object();

    virtual void update();
    virtual void render();

    virtual bool out_of_view();

    // Return position
    virtual double get_default_x();
    virtual double get_default_y();
    virtual double get_x();
    virtual double get_y();
protected:
    double x_pos;
    double y_pos;
    double width;
    double height;
    int texture_id;

    SDL_Renderer* renderer;
    SDL_Rect src, dest;
    TextureHandler* textures;
    Camera* camera;

};


#endif // GAMEOBJ_HPP
