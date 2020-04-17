#include "menu.hpp"

Menu::Menu(SDL_Renderer* renderer,
        TextureHandler &textures,
        EventHandler &events,
        std::vector<std::string> option_str) {
    this->renderer = renderer;
    this->textures = &textures;
    this->events = &events;
    
    // Resize option_state to match option_str size
    this->option_str = option_str;
    option_state.resize(option_str.size());
    button_group.resize(option_str.size());
    const int offset_y = 48;

    for (size_t i = 0; i < button_group.size(); ++i) {
        button_group[i] = Button(i, this->renderer, *(this->textures), 30, 30+(offset_y*i));
    }
}

Menu::~Menu() { }

void Menu::update() {

    // Set background
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 255);

    auto mouse_pos = events->get_mouse_pos();
    for (auto &i: button_group) {
        i.update(mouse_pos[0], mouse_pos[1], events->get_mouse_down());
    }
}

int Menu::get_pressed() {
    for (auto &i: button_group) {
        if (i.get_pressed()) {
            return i.get_id();
        }
    }
    return -1;
}

void Menu::render() {
    for (auto &i: button_group) {
        i.render();
    }
}