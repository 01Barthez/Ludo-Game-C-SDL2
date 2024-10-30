#include <stdlib.h>
#include <SDL2/SDL.h>

// Fonction pour gerer la sortie brusque en cas d'erreur
void SDL_ExitWithError(const char *message) {
    SDL_Log("Error: %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
