#include "main.hpp"
#ifdef _WIN32
int WinMain() {
#else
int main() {
#endif
    const int FPS = 60;
    const int frame_del = 1000 / FPS;

    Uint32 frame;
    int frame_time;

    Game game{};

    game.init(false);

    while(game.running()) {
        frame = SDL_GetTicks();

        game.update();
        game.render();
        game.event_handler();

        frame_time = SDL_GetTicks() - frame;

        if (frame_time < frame_del) {
            SDL_Delay(frame_del - frame_time);
        }
    }
    game.free();

    return 0;
}
