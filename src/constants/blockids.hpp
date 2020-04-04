#ifndef BLOCKIDS_HPP
#define BLOCKIDS_HPP
#include <vector>
#include <utility>
#include <string>

const std::string path = "data/img/";
const std::vector<std::pair<int, std::string>> ids = {
    {0, "grass"},
    {1, "dirt"},
    {2, "stone"}
};
const double block_w = 40;
const double block_h = 40;

#endif // BLOCKIDS
