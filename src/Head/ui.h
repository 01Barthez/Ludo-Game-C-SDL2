#ifndef UI_H_
#define UI_H_
    
    typedef struct {
        SDL_Texture *playerTurnText;
        SDL_Texture *scoreText[4];
    } UI; 
    
    void display_player_turn(SDL_Renderer *renderer, Player *player); // Affiche quel joueur doit jouer
    void display_score(SDL_Renderer *renderer, Player *player); // Affiche le score des joueurs

#endif