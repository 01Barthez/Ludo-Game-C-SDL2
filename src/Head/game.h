#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include "global.h"
#include "player.h"
#include "board.h"
#include "dice.h"
#include "ui.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LIMIT_FPS 16 // 60 FPS

    typedef struct {
        SDL_Window *window;
        SDL_Renderer *renderer;
        Player player[4]; // Quatre joueur par défaut pour chaque partie
        int currentPlayer;
        SDL_bool program_launched;
        Board board;
        Dice dice;
        UI ui;
    } Game;

    int initialiseGame(Game *game); // Initialise une partie de jeu
    void runGame(Game *game);
    void updateGame(Game *game);
    void renderGame(Game *game);
    void handleEvents(Game *game);
    void cleanUpGame(Game *game);

#endif