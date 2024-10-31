#ifndef PLAYER_H_
#define PLAYER_H_
    
#include <stdbool.h>
#include "pawn.h"
#include "global.h"

    typedef struct {
        int id; //Identifiant du joueur
        Color color; // Couleur du joueur
        Pawn pawn[4]; // Pios du joueurs (4 pions par défauts pour chaque debut de parties)
        bool hasWon; // Pour savoir s'il a gagné ou pas, par défaut c'est faux
    } Player;

    Player *create_player(Color color); // creer un joueur avec une couleur précise et initialisation de ses données
    void move_pions(Player *player, int piece_id, int steps); // deplace le pion d'un joueur d'un certain nombre de cases
    int check_collision(Player *player, int piece_id); // verifie si deux pions se sont tamponnés et exécute renvoie 1 si oui et 0 sinon;

#endif