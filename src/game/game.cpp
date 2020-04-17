#include "game.hpp"

Game::Game() : title{"LoopCube"} {

}

Game::~Game() {
    // Clean up all game objects/SDL stuff to prevent memory leakage
    free();
}

// Game related stuff below
// Initiates Game objects
void Game::game_init() {
    textures = TextureHandler(renderer);
    //game = new Play(renderer, textures, events, WINDOW_W, WINDOW_H);
    menu = new Menu(renderer, textures, events, {"one", "two", "three", "four", "five"});
}

// Game related loop stuff
void Game::update() {
    //game->update();
    menu->update();
}



// Draw objects to screen
void Game::render() {
    SDL_RenderClear(renderer);

    // game->render();
    menu->render();

    SDL_RenderPresent(renderer);
}

// SDL2 related stuff below
// Initiates Window/Game Loop
void Game::init(bool fullscreen = false) {
    // Handle flags
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "[SDL] Initialized SDL" << std::endl;
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0x79, 0xae, 0xd9, 255);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    } else {
        std::cerr << "[SDL] ERROR: Failed to initialize SDL!" << std::endl;
    }


    // Todo check error
    IMG_Init(IMG_INIT_PNG);

    game_init();

    is_running = true;
}

// Handles events such as exit, keypresses, mouse
void Game::event_handler() {

    events.listen();

    auto eventer = events.get_state();

    if (events.get_quit()) {
        is_running = false;
    }
}

bool Game::running() {
    return is_running;
}

void Game::free() {
    // Incase user manually runs this method and then the destructor calls this afterwards
    if (has_freed == false) {
        std::cout << "[Game] Cleaning up..." << std::endl;
        //delete game;
        delete menu;
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    has_freed = true;
}
