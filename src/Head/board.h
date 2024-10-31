#ifndef BOARD_H_
#define BOARD_H_

#include <SDL2/SDL.h>
#include "player.h"

#define CELL_SIZE 40 // Taille d'une case en pixel
#define BOARD_SIZE 15 // Nombre de case par coté
#define HOME_SIZE 6 // Taille de la maison d'un player par coté
#define FINISH_SIZE 15 // Taill de la eone d'arrivée par coté
#define TOTAL_CELLS 52 // Nombre total de case sur le parcours
#define BOARD_WIDTH (BOARD_SIZE * CELL_SIZE)
#define BOARD_HEIGHT (BOARD_SIZE * CELL_SIZE)

    typedef enum {
        CELL_EMPTY, // case Vide
        CELL_PATH, // Case du chemin
        CELL_HOME_RED, // Maison du joueur rouge
        CELL_HOME_BLUE, // Maison du joueur bleu
        CELL_HOME_GREEN, // Maison du joueur vert
        CELL_HOME_YELLOW, // Maison du joueur yellow
        CELL_FINISH, // zone d'arrivé
        CELL_SAFE, // case ou on ne peut etre mangé
    } CellType;

    typedef struct {
        CellType type;
        SDL_Rect rect;
        int occupied_by;
    } Cell;

    typedef struct {
        Cell grid[BOARD_SIZE][BOARD_SIZE];
        SDL_Point path[TOTAL_CELLS];
        SDL_Point startPoint[4][4];
        SDL_Point finishPath[4][4];
    } Board;
    
    // Fonction d'initialisation
    Board *createBoard(SDL_Renderer *renderer);
    void initialiseBoardCells(Board *board);
    void initialisePath(Board *board);
    void initialiseHomePos(Board *board);
    void initialiseFinishPos(Board *board);

    // Fonction de rendu
    void renderBoard(SDL_Renderer *renderer, Board *board, int offsetX, int offsetY);// Afficher le tableau de jeu;
    void renderCell(SDL_Renderer *renderer, Cell *cell);

    // Fonction de manipulation
    int isMoveValid(Board* board, int player_id, int current_pos, int dice_roll);
    void MoveToken(Board* board, int player_id, int token_id, int dice_roll);
    SDL_Point getNextPosition(Board* board, int current_pos, int steps);

    // Nettoyage de l'espace occupé par le tableau
    void destroyBoard(Board *board);
#endif