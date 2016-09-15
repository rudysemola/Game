//
// Created by rudysemola on 20/07/16.
//

#include "Coin.h"

Coin::Coin(bool r, int v,bool d) : raro(r), value(v),destroy(d) {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(300, 100);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    if (!raro) {
        tempsprite.setTextureRect(sf::IntRect(32 * 7, 32 * 2, 32, 32));
        image.loadFromFile("/home/rudysemola/AREASVILUPPO/Resource/sprite/itemsize.png");
    }
    else {
        tempsprite.setTextureRect(sf::IntRect(32 * 6, 32 * 2, 32, 32));
        image.loadFromFile("/home/rudysemola/AREASVILUPPO/Resource/sprite/itemsize.png");
    }

    texture.loadFromImage(image);
    sprite = tempsprite;
}

void Coin::update() {
    sprite.setPosition(rect.getPosition());
}

int Coin::isCaught() {
    int newCoins;
    if (raro)
        value = 10;
    newCoins = value;

    return newCoins;
}