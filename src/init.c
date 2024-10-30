#include<stdlib.h>
#include <SDL2/SDL.h>
#include "Head/init.h"
#include "Head/global.h"

// Fonction pour initialiser la SDL, creer une fenetre et un rendu
void init_SDL(void) {
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        SDL_ExitWithError("Failed to Initialise SDL !\n");
}

// Fonction pour Liberer les ressources de la SDL 
void cleanup_SDL(void) {
    SDL_Quit();
}
