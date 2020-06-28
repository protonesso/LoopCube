#include "text.hpp"

Text::Text(SDL_Renderer* renderer,
        std::string text, 
        SDL_Color color,
        int font_size, 
        const char* font)
    :  text{text}, color{color}, renderer{renderer} {
    this->font = TTF_OpenFont(font, font_size);

    if (this->font == NULL) {
        std::cerr << "[ERROR] TTF_OpenFont: " << TTF_GetError() << std::endl;
        throw "Fuck";
    }
    surface = TTF_RenderText_Blended(this->font, text.c_str(), color);
    messageText = SDL_CreateTextureFromSurface(renderer, surface);
}

Text::~Text() {
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    SDL_DestroyTexture(messageText);
}

void Text::draw(int x, int y) {
    int w, h;
    TTF_SizeText(font, text.c_str(), &w, &h);
    SDL_Rect pos{x, y, w, h};
    SDL_RenderCopy(renderer, messageText, NULL, &pos);
}