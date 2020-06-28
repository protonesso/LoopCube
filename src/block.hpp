#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "gameobj.hpp"
#include "blockids.hpp"

class Block: public Game_Object {

public:
    Block();
    Block(int id, TextureHandler &textures, SDL_Renderer* renderer, Camera &camera, int x, int y);

    void update();
    void render();
    void render_shadow();
    double get_x() const override;
    double get_y() const override;
private:
    int id;
};


#endif // BLOCK_HPP
