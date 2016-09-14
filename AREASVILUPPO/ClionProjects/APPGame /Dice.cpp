//
// Created by rudysemola on 21/07/16.
//

#include <cstdlib>
#include <ctime>

#include "Dice.h"

bool Dice::inizialized = false;

void Dice::initDice() {
    if( !inizialized )
    {
        std::srand((unsigned int)time(0));
        inizialized = true;
    }
}

int Dice::throwDice() {
    int result = std::rand() % faces + 1;

    return result;
}
