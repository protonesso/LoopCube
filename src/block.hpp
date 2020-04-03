#ifndef BLOCK_HPP
#define BLOCK_HPP
#include "gameobj.hpp"
#include "constants/blockids.hpp"

class Block: public Game_Object {

public:
    Block();
    Block(int id, SDL_Renderer* renderer, Camera &camera, int x, int y);
    ~Block();

    void update() override;
    double get_x() override;
    double get_y() override;
private:
    int id;
};


#endif // BLOCK_HPP
