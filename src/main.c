#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Head/init.h"
#include "Head/game.h"

#define LIMIT_FPS 16 // 60 FPS

int main(int argc, char *argv[]) {
    // Initialiser la SDL
    init_SDL();
    
    Game game;

    initialiseGame(&game);

    SDL_bool program_launched = SDL_TRUE;

    while (program_launched) {
        SDL_Event event; 

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_KEYDOWN: 
                    switch(event.key.keysym.sym){
                        case SDLK_SPACE:
                            // Action pour lancer une nouvelle partie si on tape sur la touche entrer
                            printf("L'utilisateur a appuyé sur espace !\n");
                        continue;

                        default: 
                        continue;
                    }
                break;

                case SDL_MOUSEBUTTONDOWN: 
                    // Gerer les differents cas en fonction de ou on a clické
                    printf("l'utilisateur a clické\n");
                break;

                case SDL_WINDOWEVENT: 
                    switch(event.window.event) {
                        case SDL_WINDOWEVENT_ENTER:
                            // Action pour changer le curseur de la souris lorsqu'on entre dans la fenetre
                            printf("L'utilisateur es entrer dans la fenetre\n");
                        continue;

                        default: 
                        continue;
                    }
                break;

                case SDL_QUIT: 
                    program_launched = SDL_FALSE;
                break;

                default: 
                break;
            }
        }
        
        SDL_Delay(LIMIT_FPS);
    } 
    
    // Fermeture du jeu;
    cleanUpGame(&game);

    // Fermeture propre de la SDL
    cleanup_SDL();

    // Fin du programme
    return EXIT_SUCCESS;
}

