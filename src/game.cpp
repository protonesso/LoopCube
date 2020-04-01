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
    // Configure camera
    camera = new Camera();
    camera->set_pos(view_x, view_y);

    chunk = new Chunk(-4, renderer, camera);

}

// Game related loop stuff
void Game::update() {
    chunk->updateAll();

    // Update camera position
    camera->set_pos(view_x, view_y);
}

// Draw objects to screen
void Game::render() {
    SDL_RenderClear(renderer);
    chunk->renderAll();
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

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }


    // Todo check error
    IMG_Init(IMG_INIT_PNG);

    game_init();

    is_running = true;
}

// Handles events such as exit, keypresses, mouse
void Game::event_handler() {
    SDL_Event event;
    SDL_PollEvent(&event);

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_UP]) {
        view_y -= 5;
    }

    if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        view_y += 5;
    }

    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        view_x -= 5;
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        view_x += 5;
    }

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
    }
}

bool Game::running() {
    return is_running;
}

void Game::free() {
    // Incase user manually runs this method and then the destructor calls this afterwards
    if (has_freed == false) {
        std::cout << "Freeing..." << std::endl;
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        delete camera;
        delete chunk;
        SDL_Quit();
    }

    has_freed = true;
}
