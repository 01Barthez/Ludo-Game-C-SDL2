#ifndef PLAYER_H_
#define PLAYER_H_
    
#include <stdbool.h>
#include "pawn.h"

    typedef enum {
        ROUGE,
        VERT,
        BLEU,
        JAUNE
    } Color;

    typedef struct {
        int id; //Identifiant du joueur
        Color color;
        Pawn pawn[4];
        bool hasWon;
    } Player;

    Player *create_player(Color color); //* creer un joueur ave une couleur précise
    void move_pions(Player *player, int piece_id, int steps); // deplace le pion d'un joueur d'un certain nombre de cases
    int check_collision(Player *player, int piece_id); // verifie si deux pions se son

#endif