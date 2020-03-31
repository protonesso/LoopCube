#include "main.hpp"
int main() {
    const int FPS = 60;
    const int frame_del = 1000 / FPS;

    Uint32 frame;
    int frame_time;

    Game* game = new Game();

    game->init(false);

    while(game->running()) {
        frame = SDL_GetTicks();

        game->event_handler();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame;

        if (frame_time < frame_del) {
            SDL_Delay(frame_del - frame_time);
        }
    }
    game->free();

    delete game;

    return 0;
}
