#include "Head/board.h"
#include "Head/global.h"
#include "Head/game.h"
#include <stdio.h>

Board *createBoard(SDL_Renderer *renderer) {
    Board *board = calloc(1, sizeof(Board));
    if(!board) return NULL;

    initialiseBoardCells(board);
    initialisePath(board);
    initialiseHomePos(board);
    initialiseFinishPos(board);
    
    return board;
}

void initialiseBoardCells(Board* board) {
    // Initialise chaque cellule du tableau
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            board->grid[y][x].type = CELL_WHITE;
            board->grid[y][x].rect.x = x * CELL_SIZE;
            board->grid[y][x].rect.y = y * CELL_SIZE;
            board->grid[y][x].rect.w = CELL_SIZE;
            board->grid[y][x].rect.h = CELL_SIZE;
            
            board->grid[y][x].occupied_by = -1;
        }
    }

    // Configure les maisons
    //? Maison Rouge (coin supérieur gauche)
    for (int y = 0; y < HOME_SIZE; y++) {
        for (int x = 0; x < HOME_SIZE; x++) {
            board->grid[y][x].type = CELL_HOME_RED;
        }
    }

    // Maison Bleue (coin supérieur droit)
    for (int y = 0; y < HOME_SIZE; y++) {
        for (int x = BOARD_SIZE - HOME_SIZE; x < BOARD_SIZE; x++) {
            board->grid[y][x].type = CELL_HOME_BLUE;
        }
    }

    // Maison Jaune (coin inférieur droit)
    for (int y = BOARD_SIZE - HOME_SIZE; y < BOARD_SIZE; y++) {
        for (int x = BOARD_SIZE - HOME_SIZE; x < BOARD_SIZE; x++) {
            board->grid[y][x].type = CELL_HOME_YELLOW;
        }
    }
    
    // Maison Verte (coin inférieur gauche)
    for (int y = BOARD_SIZE - HOME_SIZE; y < BOARD_SIZE; y++) {
        for (int x = 0; x < HOME_SIZE; x++) {
            board->grid[y][x].type = CELL_HOME_GREEN;
        }
    }

    // Configure la zone d'arrivée centrale
    int startFinish = (BOARD_SIZE - FINISH_SIZE) / 2;
    for (int y = startFinish; y < startFinish + FINISH_SIZE; y++) {
        for (int x = startFinish; x < startFinish + FINISH_SIZE; x++) {
            board->grid[y][x].type = CELL_FINISH;
        }
    }
}

void renderBoard(SDL_Renderer *renderer, Board *board, int offsetX, int offsetY) {
    // Dessine le fond violet
    SDL_SetRenderDrawColor(renderer, 127, 84, 212, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Dessine chaque cellule
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            Cell* cell = &board->grid[y][x];
            cell->rect.x += offsetX;
            cell->rect.y += offsetY;
            renderCell(renderer, cell);
        }
    }

    // Dessine la grille
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (int i = 0; i <= BOARD_SIZE; i++) {
        // Lignes verticales
        SDL_RenderDrawLine(renderer, 
            i * CELL_SIZE + offsetX, 0 + offsetY, 
            i * CELL_SIZE + offsetX, BOARD_SIZE * CELL_SIZE + offsetY
        );
        // Lignes horizontales
        SDL_RenderDrawLine(renderer, 
            0 + offsetX, i * CELL_SIZE + offsetY, 
            BOARD_SIZE * CELL_SIZE + offsetX, i * CELL_SIZE + offsetY
        );
    }
};

void renderCell(SDL_Renderer *renderer, Cell *cell) {
    switch (cell->type) {
        case CELL_HOME_RED:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        break;

        case CELL_HOME_BLUE:
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        break;

        case CELL_HOME_YELLOW:
            SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
        break;

        case CELL_HOME_GREEN:
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        break;

        case CELL_FINISH:
            SDL_SetRenderDrawColor(renderer, 220, 220, 220, SDL_ALPHA_OPAQUE);
        break;

        default:
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        break;
    }
    SDL_RenderFillRect(renderer, &cell->rect);
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
