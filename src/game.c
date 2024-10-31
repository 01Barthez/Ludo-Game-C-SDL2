#include "Head/game.h"
#include "Head/board.h"
#include "Head/dice.h"

int initialiseGame(Game *game) {
    game->window = SDL_CreateWindow("Ludo Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if(!game->window) 
         SDL_ExitWithError("Failed to create window !\n");

    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if(!game->renderer)
        SDL_ExitWithError("Failed to create render !\n");

    // Initialise dice
    initialiseDice(&game->dice);
    
    game->board = createBoard(game->renderer);
    if(!game->board)
        SDL_ExitWithError("Failed to create Board !\n");
    
    game->program_launched = SDL_TRUE;
};

void cleanUpGame(Game *game) {
    destroyBoard(game->board);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
};

void runGame(Game *game) {
    while (game->program_launched) {
        handleEvents(game);
        updateGame(game);
        renderGame(game);
    }; 
    SDL_Delay(LIMIT_FPS);
};

void updateGame(Game *game) {
    // Ici on va mettre a jour l'etat du jeu a chaque mouvement
};

void renderGame(Game *game){
    if(SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Failed set render color !\n");
    SDL_RenderClear(game->renderer);
    
    int boardOffsetX = (WINDOW_WIDTH - BOARD_WIDTH) / 2;
    int boardOffsetY = (WINDOW_HEIGHT - BOARD_HEIGHT) / 2;

    // Différents affichages
    renderBoard(game->renderer, game->board, boardOffsetX, boardOffsetY); // Pour afficher le tableau de jeu;

    // Presenter les differents rendu
    SDL_RenderPresent(game->renderer);
}

void handleEvents(Game *game){
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
                game->program_launched = SDL_FALSE;
            break;

            default: 
            break;
        }
    }
}
