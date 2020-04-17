#ifndef BLOCKIDS_HPP
#define BLOCKIDS_HPP
#include <vector>
#include <utility>
#include <string>

// NOTE maybe move to texture.cpp?
const std::string path = "data/img/";
/*
    Blocks = 0x0 ... 0xF9F
    Sprites = 0xFA0 ... 0xFFF
*/
const std::vector<std::pair<int, std::string>> ids = {
    {0, "grass"},
    {1, "dirt"},
    {2, "stone"},
    {3, "wood"},
    {0xFA0, "player"},
    {0xFA1, "menu_solid"},
    {0xFA2, "menu_rounded_left"},
    {0xFA3, "menu_rounded_right"}
};
const int block_start = 0;
const int sprite_start = 0xFA0;

// TODO move to block.hpp
const double block_w = 32;
const double block_h = 32;

#endif // BLOCKIDS
