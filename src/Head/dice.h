#ifndef DICE_H_
#define DICE_H_
    
    typedef struct {
        int defaultRoll;
        int lastRoll;
    } Dice;

    int roll_dice(); // génère un nombre aléatoire entre 1 et 6
    void draw_dice(); // Affiche le dé avec le nombre tiré

#endif