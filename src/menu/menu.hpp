#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <string>

#include "../texture/texturehandler.hpp"
#include "../event/eventhandler.hpp"
#include "../constants/blockids.hpp"
#include "../ui/button.hpp"

class Menu {
public:
    Menu(SDL_Renderer* renderer, 
        TextureHandler &textures,
        EventHandler &events,
        std::vector<std::string> option_str);
    ~Menu();

    void update();
    void render();
    int get_pressed();
private:
    std::vector<std::string> option_str;
    std::vector<int> option_state; 
    Button button;
    std::vector<Button> button_group;

    SDL_Renderer* renderer;
    TextureHandler* textures;
    EventHandler* events;
};


#endif // MENU_HPP