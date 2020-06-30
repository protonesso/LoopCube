#ifndef TEXT_HPP
#define TEXT_HPP
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class Text {
public:
    Text(SDL_Renderer* renderer,
        std::string text,
        SDL_Color color, 
        int font_size = 12, 
        const char* font = "data/fonts/liberation-sans/LiberationSans-Regular.ttf");
    ~Text();

    void draw(int x, int y);
    void set_text(std::string text);
private:
    std::string text;

    SDL_Color color;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Surface* surface;
    SDL_Texture* messageText;

};

#endif // TEXT_HPP