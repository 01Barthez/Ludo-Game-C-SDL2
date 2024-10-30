#include <SDL2/SDL.h>
#include "Head/init.h"
#include "Head/game.h"

int main(int argc, char *argv[]) {
    // Initialiser la SDL
    init_SDL();
    
    Game game;

    // Initialiser la partie de jeu
    initialiseGame(&game);

    // Lancer la partie de jeu
    runGame(&game);
    
    // Fermeture du jeu;
    cleanUpGame(&game);

    // Fermeture propre de la SDL
    cleanup_SDL();

    // Fin du programme
    return EXIT_SUCCESS;
}

