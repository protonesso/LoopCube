#include "blockinfo.hpp"

BlockInfo::BlockInfo(std::string id, std::string name, int texture_id) {
    this->id = id;
    this->name = name;
    this->texture_id = texture_id;
}

BlockInfo::~BlockInfo() {

}

std::string BlockInfo::get_id() const{
    return id;
}

std::string BlockInfo::get_name() const{
    return name;
}

int BlockInfo::get_texture_id() const{
    return texture_id;
}