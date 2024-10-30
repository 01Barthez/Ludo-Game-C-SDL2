#include "Head/dice.h"
#include <time.h>
#include <stdlib.h>

void initialiseDice(Dice *dice) {
    srand(time(NULL)); 
    dice->value = SIX;
};

int rollDice(Dice *dice) {
    DiceValue new_dice_value = (rand() % SIX) + ONE;
    dice->value = new_dice_value;
    
    return dice->value;
};

void drawDice(Dice *dice) {
    // ...
}