//
// Created by rudysemola on 13/09/16.
//

#ifndef GAMESOFTWARE_CSCHASE_H
#define GAMESOFTWARE_CSCHASE_H

#include "AbStrategyMove.h"

class CSChase : public AbStrategyMove {
public:
    virtual void preferenceMove(sf::RectangleShape &rect, sf::Sprite &sprite, TypeEnemy &typeEnemy,
                                Direction &directionType, bool &changeDirection,
                                int &counterWalking,
                                int &movementSpeed, int &counterLength, int &movementLength, bool &canMoveUp,
                                bool &canMoveDown, bool &canMoveLeft, bool &canMoveRight, Player *&player) override;

    Direction moveChase(sf::RectangleShape &rect, int &counterLength, int &movementLength, Player *&player);
};


#endif //GAMESOFTWARE_CSCHASE_H
