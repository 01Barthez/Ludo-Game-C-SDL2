#ifndef DICE_H_
#define DICE_H_

    typedef enum {
        ONE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX
    } DiceValue;

    typedef struct {
        DiceValue value;
    } Dice;

    void initialiseDice(Dice *dice); // Initialiser le dé avec sa valeur par défaut;
    int rollDice(Dice *dice); // génère un nombre aléatoire entre 1 et 6
    void drawDice(Dice *dice); // Affiche le dé avec le nombre tiré

#endif