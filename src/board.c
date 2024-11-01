#include "Head/board.h"
#include "Head/global.h"
#include "Head/game.h"
#include <stdio.h>

Board *createBoard(SDL_Renderer *renderer) {
    Board *board = calloc(1, sizeof(Board));
    if(!board) return NULL;

    initialiseBoardCells(board);

    return board;
}

void initialiseBoardCells(Board *board) {
    // Initialisation de toutes les cases en blanc
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->grid[i][j].type = CELL_WHITE;
            board->grid[i][j].rect.x = j * CELL_SIZE;
            board->grid[i][j].rect.y = i * CELL_SIZE;
            board->grid[i][j].rect.w = CELL_SIZE;
            board->grid[i][j].rect.h = CELL_SIZE;
            board->grid[i][j].occupied_by = 0;
        }
    }

    // Initialisation des maisons
    //? Maison Rouge (coin supérieur gauche)
    for (int i = 0; i < HOME_SIZE; i++) {
        for (int j = 0; j < HOME_SIZE; j++) {
            board->grid[i][j].type = CELL_HOME_RED;
        }
    }

    //? Maison Bleue (coin supérieur droit)
    for (int i = 0; i < HOME_SIZE; i++) {
        for (int j = BOARD_SIZE - HOME_SIZE; j < BOARD_SIZE; j++) {
            board->grid[i][j].type = CELL_HOME_BLUE;
        }
    }

    //? Maison Jaune (coin inférieur droit)
    for (int i = BOARD_SIZE - HOME_SIZE; i < BOARD_SIZE; i++) {
        for (int j = BOARD_SIZE - HOME_SIZE; j < BOARD_SIZE; j++) {
            board->grid[i][j].type = CELL_HOME_YELLOW;
        }
    }

    //? Maison Verte (coin inférieur gauche)
    for (int i = BOARD_SIZE - HOME_SIZE; i < BOARD_SIZE; i++) {
        for (int j = 0; j < HOME_SIZE; j++) {
            board->grid[i][j].type = CELL_HOME_GREEN;
        }
    }

    //? Case d'arrivée au centre
    int start = (BOARD_SIZE - 3) / 2;
    int end = start + 3;
    for (int i = start; i < end; i++) {
        for (int j = start; j < end; j++) {
            board->grid[i][j].type = CELL_FINISH;
        }
    }

    // Cases de départ spéciales
    board->grid[6][1].type = CELL_HOME_RED;    //* Rouge
    board->grid[1][8].type = CELL_HOME_BLUE;   //* Bleu
    board->grid[8][13].type = CELL_HOME_YELLOW; //* Jaune
    board->grid[13][6].type = CELL_HOME_GREEN;  //* Vert

    // grilles en blancs
    // Pour le rouges    
    board->grid[4][1].type = CELL_WHITE;
    board->grid[4][2].type = CELL_WHITE;
    board->grid[4][3].type = CELL_WHITE;
    board->grid[4][4].type = CELL_WHITE;
    
    board->grid[1][1].type = CELL_WHITE;
    board->grid[1][2].type = CELL_WHITE;
    board->grid[1][3].type = CELL_WHITE;
    board->grid[1][4].type = CELL_WHITE;

    board->grid[2][1].type = CELL_WHITE;
    board->grid[3][1].type = CELL_WHITE;

    board->grid[2][4].type = CELL_WHITE;
    board->grid[3][4].type = CELL_WHITE;

    // Pour le bleu
    board->grid[4][10].type = CELL_WHITE;
    board->grid[4][11].type = CELL_WHITE;
    board->grid[4][12].type = CELL_WHITE;
    board->grid[4][13].type = CELL_WHITE;

    board->grid[1][10].type = CELL_WHITE;
    board->grid[1][11].type = CELL_WHITE;
    board->grid[1][12].type = CELL_WHITE;
    board->grid[1][13].type = CELL_WHITE;

    board->grid[2][10].type = CELL_WHITE;
    board->grid[3][10].type = CELL_WHITE;

    board->grid[2][13].type = CELL_WHITE;
    board->grid[3][13].type = CELL_WHITE;

    // Pour le Jaune
    board->grid[10][10].type = CELL_WHITE;
    board->grid[10][11].type = CELL_WHITE;
    board->grid[10][12].type = CELL_WHITE;
    board->grid[10][13].type = CELL_WHITE;

    board->grid[13][10].type = CELL_WHITE;
    board->grid[13][11].type = CELL_WHITE;
    board->grid[13][12].type = CELL_WHITE;
    board->grid[13][13].type = CELL_WHITE;

    board->grid[11][13].type = CELL_WHITE;
    board->grid[12][13].type = CELL_WHITE;

    board->grid[11][10].type = CELL_WHITE;
    board->grid[12][10].type = CELL_WHITE;

    // Pour le vert
    board->grid[10][1].type = CELL_WHITE;
    board->grid[10][2].type = CELL_WHITE;
    board->grid[10][3].type = CELL_WHITE;
    board->grid[10][4].type = CELL_WHITE;

    board->grid[13][1].type = CELL_WHITE;
    board->grid[13][2].type = CELL_WHITE;
    board->grid[13][3].type = CELL_WHITE;
    board->grid[13][4].type = CELL_WHITE;

    board->grid[11][4].type = CELL_WHITE;
    board->grid[12][4].type = CELL_WHITE;

    board->grid[11][1].type = CELL_WHITE;
    board->grid[12][1].type = CELL_WHITE;

    // Route pour la libraison des pions...
    // Pour le rouge
    board->grid[7][1].type = CELL_HOME_RED;
    board->grid[7][2].type = CELL_HOME_RED;
    board->grid[7][3].type = CELL_HOME_RED;
    board->grid[7][4].type = CELL_HOME_RED;
    board->grid[7][5].type = CELL_HOME_RED;

    // Pour le bleu
    board->grid[1][7].type = CELL_HOME_BLUE;
    board->grid[2][7].type = CELL_HOME_BLUE;
    board->grid[3][7].type = CELL_HOME_BLUE;
    board->grid[4][7].type = CELL_HOME_BLUE;
    board->grid[5][7].type = CELL_HOME_BLUE;

  // Pour le jaune
    board->grid[7][9].type = CELL_HOME_YELLOW;
    board->grid[7][10].type = CELL_HOME_YELLOW;
    board->grid[7][11].type = CELL_HOME_YELLOW;
    board->grid[7][12].type = CELL_HOME_YELLOW;
    board->grid[7][13].type = CELL_HOME_YELLOW;

    // Pour le vert
    board->grid[9][7].type = CELL_HOME_GREEN;
    board->grid[10][7].type = CELL_HOME_GREEN;
    board->grid[11][7].type = CELL_HOME_GREEN;
    board->grid[12][7].type = CELL_HOME_GREEN;
    board->grid[13][7].type = CELL_HOME_GREEN;
}

void renderBoard(SDL_Renderer *renderer, Board *board, int offsetX, int offsetY) {
    // Dessine le fond violet
    SDL_SetRenderDrawColor(renderer, 127, 84, 212, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

  // Dessiner chaque cellule
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->grid[i][j].rect.x = j * CELL_SIZE + offsetX;
            board->grid[i][j].rect.y = i * CELL_SIZE + offsetY;
            renderCell(renderer, &board->grid[i][j]);
        }
    }
};

void renderCell(SDL_Renderer *renderer, Cell *cell) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Couleur noire pour les bordures
    SDL_RenderDrawRect(renderer, &cell->rect);

    switch (cell->type) {
        case CELL_HOME_RED:
            if(SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set red color !");
        break;
        
        case CELL_HOME_BLUE:
            if(SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set blue color !");
        break;

        case CELL_HOME_GREEN:
            if(SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
        
        case CELL_HOME_YELLOW:
            if(SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
        
        case CELL_FINISH:
            if(SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
        
        case CELL_WHITE:
            if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
    }
    
    SDL_Rect innerRect = cell->rect;
    innerRect.x += 1;
    innerRect.y += 1;
    innerRect.w -= 2;
    innerRect.h -= 2;
    SDL_RenderFillRect(renderer, &innerRect);
}

// Initialise le chemin à suivre
void initialisePath(Board* board) {
    // Regle et chemin a suivre par chaque pions;
}

void initialiseHomePos(Board* board) {
    // Regle et chemin a suivre par chaque pions;
}

void initialiseFinishPos(Board* board) {
    // Regle et chemin a suivre par chaque pions;
}

void destroyBoard(Board *board) {
    if (board)
        free(board);
}
