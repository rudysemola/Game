//
// Created by rudysemola on 11/08/16.
//

#include "BlockWeapon.h"

BlockWeapon::BlockWeapon(bool d) : destroy(d) {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    tempsprite.setTextureRect(sf::IntRect(0, 32*2, 32, 32));
    image.loadFromFile("/home/rudysemola/AREASVILUPPO/Resource/sprite/blockothersprite.png");

    texture.loadFromImage(image);
    sprite = tempsprite;
}

void BlockWeapon::update() {
    sprite.setPosition(rect.getPosition());
}
