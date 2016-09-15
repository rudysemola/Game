//
// Created by rudysemola on 28/07/16.
//

#include "Knight.h"

Knight::Knight(bool futur,Weapon* w) : futuristic(futur) ,Player(w){
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    tempsprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    if(futuristic)
        image.loadFromFile(
            "/home/rudysemola/AREASVILUPPO/Resource/sprite/knightfuturisticsprite.png");
    else
        image.loadFromFile(
                "/home/rudysemola/AREASVILUPPO/Resource/sprite/knightsupremesprite.png");
    texture.loadFromImage(image);
    sprite = tempsprite;
}

void Knight::update() {
    sprite.setPosition(rect.getPosition());
}

void Knight::updateMove() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        typeP = Direction::Up;
        if (canMoveUp == true) {
            rect.move(0, -movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 3, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        typeP = Direction::Down;
        if (canMoveDown == true) {
            rect.move(0, movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 0, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        typeP = Direction::Right;
        if (canMoveRight == true) {
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(counterWalking * 32, 32 * 2, 32, 32));

            canMoveUp = true;
            canMoveDown = true;
            canMoveRight = true;
            canMoveLeft = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        typeP = Direction::Left;
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
