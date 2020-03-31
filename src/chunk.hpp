#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <iostream>
#include <array>

#include "block.hpp"

class Chunk {

public:
    Chunk();
    ~Chunk();

private:
    std::array<Block, 2048> chunk;
};


#endif // CHUNK_HPP
