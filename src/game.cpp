#include "game.hpp"

Game::Game() : title{"LoopCube"}, camera{WINDOW_W, WINDOW_H} {

}

Game::~Game() {
    // Clean up all game objects/SDL stuff to prevent memory leakage
    free();
}

// Game related stuff below
// Initiates Game objects
void Game::game_init() {
    unsigned long int seed = 1;
    // Configure camera
    player = Player(textures, renderer, camera);
    camera.set_pos(0, -45*block_h);

    textures = TextureHandler(renderer);
    chunks = Chunk_Group(seed, renderer, camera, textures);


}

// Game related loop stuff
void Game::update() {

    // Update player
    player.update(chunks);
    // Update camera
    handle_camera();

    // Update all chunks
    chunks.update_all();
    chunks.check_area();
}

void Game::handle_camera() {
    double x = (player.get_default_x()*-1 + (WINDOW_W/2)) - player.get_width()/2;
    double y = player.get_default_y()*-1 + (WINDOW_H/2) - player.get_height()/2;
    camera.set_pos(x, y);
}

// Draw objects to screen
void Game::render() {
    SDL_RenderClear(renderer);

    chunks.render_all();
    player.render();

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

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 0x79, 0xae, 0xd9, 255);
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
        player.direct_player(0, chunks);
    }

    if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        player.direct_player(2, chunks);
    }

    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        player.direct_player(3, chunks);
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        player.direct_player(1, chunks);
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
        SDL_Quit();
    }

    has_freed = true;
}
