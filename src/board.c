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
    SDL_SetRenderDrawColor(renderer, 26, 11, 94, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Dessiner d'abord les grandes zones fusionnées
    SDL_Rect homeRect;
    
    // Maison Rouge (coin supérieur gauche)
    homeRect.x = offsetX;
    homeRect.y = offsetY;
    homeRect.w = HOME_SIZE * CELL_SIZE;
    homeRect.h = HOME_SIZE * CELL_SIZE;
    if(SDL_SetRenderDrawColor(renderer, 228, 42, 42, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Failed to set red color !");
    SDL_RenderFillRect(renderer, &homeRect);
    
    // Maison Bleue (coin supérieur droit)
    homeRect.x = offsetX + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE;
    homeRect.y = offsetY;
    if(SDL_SetRenderDrawColor(renderer, 0, 110, 210, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Failed to set blue color !");
    SDL_RenderFillRect(renderer, &homeRect);
    
    // Maison Jaune (coin inférieur droit)
    homeRect.x = offsetX + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE;
    homeRect.y = offsetY + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE;
    if(SDL_SetRenderDrawColor(renderer, 255, 210, 10, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Failed to set yellow color !");
    SDL_RenderFillRect(renderer, &homeRect);
    
    // Maison Verte (coin inférieur gauche)
    homeRect.x = offsetX;
    homeRect.y = offsetY + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE;
    if(SDL_SetRenderDrawColor(renderer, 21, 135, 46, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Failed to set green color !");
    SDL_RenderFillRect(renderer, &homeRect);
    
    // Case Finish au centre
    int start = (BOARD_SIZE - 3) / 2;
    SDL_Rect finishRect;
    finishRect.x = offsetX + start * CELL_SIZE;
    finishRect.y = offsetY + start * CELL_SIZE;
    finishRect.w = 3 * CELL_SIZE;
    finishRect.h = 3 * CELL_SIZE;
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &finishRect);

    // Dessiner toutes les autres cellules (cases blanches et chemins colorés)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Ne pas redessiner les cases des maisons et de finish
            if (!(// Maison Rouge
                  (i < HOME_SIZE && j < HOME_SIZE) ||
                  // Maison Bleue
                  (i < HOME_SIZE && j >= BOARD_SIZE - HOME_SIZE) ||
                  // Maison Jaune
                  (i >= BOARD_SIZE - HOME_SIZE && j >= BOARD_SIZE - HOME_SIZE) ||
                  // Maison Verte
                  (i >= BOARD_SIZE - HOME_SIZE && j < HOME_SIZE) ||
                  // Case Finish
                  (i >= start && i < start + 3 && j >= start && j < start + 3))) {
                
                board->grid[i][j].rect.x = j * CELL_SIZE + offsetX;
                board->grid[i][j].rect.y = i * CELL_SIZE + offsetY;
                renderCell(renderer, &board->grid[i][j]);
            }
        }
    }

   
// Ajouter les cercles et carrés dans les zones de départ
   // Calculer le centre exact de chaque zone maison
    int homeCenterOffset = (HOME_SIZE * CELL_SIZE) / 2;

    // Pour la maison Rouge (coin supérieur gauche)
    renderHomeCircleAndSquares(renderer, 
        offsetX + homeCenterOffset,  // Centre X de la zone rouge
        offsetY + homeCenterOffset,  // Centre Y de la zone rouge
        228, 42, 42);

    // Pour la maison Bleue (coin supérieur droit)
    renderHomeCircleAndSquares(renderer,
        offsetX + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE + homeCenterOffset,
        offsetY + homeCenterOffset,
        0, 110, 210);

    // Pour la maison Jaune (coin inférieur droit)
    renderHomeCircleAndSquares(renderer,
        offsetX + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE + homeCenterOffset,
        offsetY + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE + homeCenterOffset,
        255, 210, 10);

    // Pour la maison Verte (coin inférieur gauche)
    renderHomeCircleAndSquares(renderer,
        offsetX + homeCenterOffset,
        offsetY + (BOARD_SIZE - HOME_SIZE) * CELL_SIZE + homeCenterOffset,
        21, 135, 46);
}

void renderHomeCircleAndSquares(SDL_Renderer *renderer, int centerX, int centerY, Uint8 r, Uint8 g, Uint8 b) {
    // Dessiner le cercle blanc
    int circleRadius = 2 * CELL_SIZE;
    SDL_SetRenderDrawColor(renderer, 244, 244, 244, SDL_ALPHA_OPAQUE);
    for(int w = -circleRadius; w < circleRadius; w++) {
        for(int h = -circleRadius; h < circleRadius; h++) {
            if((w*w + h*h) <= circleRadius*circleRadius) {
                SDL_RenderDrawPoint(renderer, centerX + w, centerY + h);
            }
        }
    }

    // Taille des petits carrés (un peu plus petit qu'une case)
      int squareSize = (int)(CELL_SIZE * 0.8);
    int squareOffset = CELL_SIZE;
    
    // Positions des carrés : en haut à gauche, en haut à droite, en bas à gauche, en bas à droite
     SDL_Point squareOffsets[] = {
        {-squareOffset - squareSize/2, -squareOffset - squareSize/2},  // Haut gauche
        {squareOffset - squareSize/2, -squareOffset - squareSize/2},   // Haut droite
        {-squareOffset - squareSize/2, squareOffset - squareSize/2},   // Bas gauche
        {squareOffset - squareSize/2, squareOffset - squareSize/2}     // Bas droite
    };

    // Dessiner les 4 carrés colorés
     for(int i = 0; i < 4; i++) {
        SDL_Rect square = {
            centerX + squareOffsets[i].x,
            centerY + squareOffsets[i].y,
            squareSize,
            squareSize
        };

        // Remplir le carré avec la couleur du joueur
        SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &square);
        
        // Dessiner la bordure noire
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer, &square);
    }
}
void renderCell(SDL_Renderer *renderer, Cell *cell) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); // Couleur noire pour les bordures
    SDL_RenderDrawRect(renderer, &cell->rect);

    switch (cell->type) {
        case CELL_HOME_RED:
            if(SDL_SetRenderDrawColor(renderer, 228, 42, 42, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set red color !");
        break;
        
        case CELL_HOME_BLUE:
            if(SDL_SetRenderDrawColor(renderer, 0, 110, 210, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set blue color !");
        break;

        case CELL_HOME_GREEN:
            if(SDL_SetRenderDrawColor(renderer, 21, 135, 46, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
        
        case CELL_HOME_YELLOW:
            if(SDL_SetRenderDrawColor(renderer, 255, 210, 10, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
        
        case CELL_FINISH:
            if(SDL_SetRenderDrawColor(renderer, 120, 120, 120, SDL_ALPHA_OPAQUE) != 0)
                SDL_ExitWithError("Failed to set green color !");
        break;
        
        case CELL_WHITE:
            if(SDL_SetRenderDrawColor(renderer, 244, 244, 244, SDL_ALPHA_OPAQUE) != 0)
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
