#ifndef BOARD_H_
#define BOARD_H_
    
    typedef struct {
        int cells[52];
        int startingPoing[4];
        int finishPath[4][6];
    } Board;

    void draw_board(SDL_Renderer *renderer); // Dessine la grille et les élément de bases
    void loard_board_assets(); // charges les textures ou les images de la grille

#endif