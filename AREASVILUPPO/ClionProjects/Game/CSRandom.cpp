//
// Created by rudysemola on 12/09/16.
//

#include "CSRandom.h"
#include "Dice.h"

void CSRandom::preferenceMove(sf::RectangleShape &rect, sf::Sprite &sprite, TypeEnemy &typeEnemy,
                              Direction &directionType, bool &changeDirection,
                              int &counterWalking, int &movementSpeed, int &counterLength, int &movementLength,
                              bool &canMoveUp, bool &canMoveDown, bool &canMoveLeft, bool &canMoveRight,
                              Player *&player) {
    Dice aDice(4);
    counterLength++;

    if (directionType == Direction::Up) {
        if (canMoveUp == true) {
            rect.move(0, -movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }
    else if (directionType == Direction::Down) {
        if (canMoveDown == true) {
            rect.move(0, movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }
    else if (directionType == Direction::Right) {
        if (canMoveRight == true) {
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }
    else if (directionType == Direction::Left) {
        if (canMoveLeft == true) {
            rect.move(-movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 1, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }

    counterWalking++;

    if (counterWalking == 2)
        counterWalking = 0;

    if (counterLength >= movementLength) {
        int randomDirection = aDice.throwDice() - 1;
        if (randomDirection == 4)
            randomDirection = aDice.throwDice() - 1;
        directionType = static_cast<Direction >(randomDirection);

        counterLength = 0;
    }
}