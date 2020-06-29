#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "gameobj.hpp"
#include "constants.hpp"

class Block: public Game_Object {

public:
    Block();
    Block(std::string id, TextureHandler &textures, SDL_Renderer* renderer, Camera &camera, int x, int y);

    void update();
    void render();
    void render_shadow();
    double get_x() const override;
    double get_y() const override;
};


#endif // BLOCK_HPP
