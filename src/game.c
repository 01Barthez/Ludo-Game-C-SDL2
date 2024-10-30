#include "Head/game.h"

int initialiseGame(Game *game) {
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &game->window, &game->renderer) != 0)
        SDL_ExitWithError("Failed to create window and render !\n");
};

void cleanUpGame(Game *game) {
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
};
