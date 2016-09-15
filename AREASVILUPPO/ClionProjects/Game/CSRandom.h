//
// Created by rudysemola on 12/09/16.
//

#ifndef GAMESOFTWARE_CSRANDOM_H
#define GAMESOFTWARE_CSRANDOM_H

#include "AbStrategyMove.h"

class CSRandom : public AbStrategyMove {
public:
    virtual void preferenceMove(sf::RectangleShape &rect, sf::Sprite &sprite, TypeEnemy &typeEnemy,
                                Direction &directionType, bool &changeDirection,
                                int &counterWalking,
                                int &movementSpeed, int &counterLength, int &movementLength, bool &canMoveUp,
                                bool &canMoveDown, bool &canMoveLeft, bool &canMoveRight, Player *&player) override;
};


#endif //GAMESOFTWARE_CSRANDOM_H
