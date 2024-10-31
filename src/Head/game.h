#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include "global.h"
#include "player.h"
#include "board.h"
#include "dice.h"
#include "ui.h"

#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define LIMIT_FPS 16 // 60 FPS

    typedef struct {
        SDL_Window *window; // On a une fenetre 
        SDL_Renderer *renderer; // On a un rendu 
        Player player[4]; // Quatre joueur par défaut pour chaque partie
        int currentPlayer; // On a l'id du joueur actuel
        SDL_bool program_launched; // Pour savoir si le jeu est en cours...
        Board *board; // Le tablau de jeu
        Dice dice; // Le dée
        UI ui; // les element visuels (Score, stats, joueur qui joue...)
    } Game;

    void initialiseGame(Game *game); // Initialise une partie de jeu
    void runGame(Game *game); // lancer le jeu
    void updateGame(Game *game); // Faire les mises a jour sur le jeu en fonction des actions
    void renderGame(Game *game); // Rendre le visuel...
    void handleEvents(Game *game); // écouter les différents évenements et gérere une action en contre-partie...
    void cleanUpGame(Game *game); // Néttoyer les ressources alloué pour une partie de jeu

#endif