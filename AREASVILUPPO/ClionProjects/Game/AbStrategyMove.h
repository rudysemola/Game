//
// Created by rudysemola on 12/09/16.
//
/*
 * Uso del pattern Strategy per la gestione del tipo di movimento degli enemy
 */
#ifndef GAMESOFTWARE_ABSTRATEGYMOVE_H
#define GAMESOFTWARE_ABSTRATEGYMOVE_H

#include <SFML/Graphics.hpp>

#include "Enums.h"
#include "Player.h"

class AbStrategyMove {
public:
    virtual void preferenceMove(sf::RectangleShape &rect, sf::Sprite &sprite, TypeEnemy &typeEnemy,
                                Direction &directionType, bool &changeDirection, int &counterWalking,
                                int &movementSpeed, int &counterLength, int &movementLength, bool &canMoveUp,
                                bool &canMoveDown, bool &canMoveLeft, bool &canMoveRight, Player *&player) = 0;

};

#endif //GAMESOFTWARE_ABSTRATEGYMOVE_H
