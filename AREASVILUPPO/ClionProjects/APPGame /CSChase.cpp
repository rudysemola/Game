//
// Created by rudysemola on 13/09/16.
//

#include "CSChase.h"

void CSChase::preferenceMove(sf::RectangleShape &rect, sf::Sprite &sprite, TypeEnemy &typeEnemy,
                             Direction &directionType, bool &changeDirection, int &counterWalking, int &movementSpeed,
                             int &counterLength, int &movementLength, bool &canMoveUp, bool &canMoveDown,
                             bool &canMoveLeft, bool &canMoveRight,Player*& player) {

    directionType = moveChase(rect,counterLength,movementLength,player);

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
}

Direction CSChase::moveChase(sf::RectangleShape &rect,int &counterLength, int &movementLength,Player *&player) {
    movementLength = 15;
    counterLength++;

    if(counterLength >= movementLength) {
        if(player->getRect().getPosition().y < rect.getPosition().y)
            return Direction::Up;
        else if(player->getRect().getPosition().y > rect.getPosition().y)
            return Direction::Down;
        else if(player->getRect().getPosition().x < rect.getPosition().x)
            return Direction::Left;
        else if(player->getRect().getPosition().x > rect.getPosition().x)
            return Direction::Right;

        counterLength = 0;
    }
    else {
        if(player->getRect().getPosition().x < rect.getPosition().x)
            return Direction::Left;
        else if(player->getRect().getPosition().x > rect.getPosition().x)
            return Direction::Right;
        else if(player->getRect().getPosition().y < rect.getPosition().y)
            return Direction::Up;
        else if(player->getRect().getPosition().y > rect.getPosition().y)
            return Direction::Down;
    }

}