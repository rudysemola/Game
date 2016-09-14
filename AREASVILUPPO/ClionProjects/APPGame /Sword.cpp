//
// Created by rudysemola on 11/08/16.
//

#include "Sword.h"

Sword::Sword(bool sSw,bool poss, int s) : superSword(sSw), Weapon(poss,s) {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    if(superSword) {
        tempsprite.setTextureRect(sf::IntRect(32*2,32*1,32,32));
        Sword::strength *= 2;
    }
    else
        tempsprite.setTextureRect(sf::IntRect(32*4,0,32,32));

    image.loadFromFile("/home/rudysemola/AREASVILUPPO/Resource/sprite/sword.png");
    texture.loadFromImage(image);
    sprite = tempsprite;
}

void Sword::update(Direction type) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        if( type == Direction::Up )
        {
            sprite.setRotation(-45.0f);
        }
        else if( type == Direction::Down )
        {
            sprite.setRotation(125.0f);
        }
        else if( type == Direction::Right )
        {
            sprite.setRotation(35.0f);
        }
        else if( type == Direction::Left )
        {
            sprite.setRotation(-135.0f);
        }
    }

    sprite.setPosition(rect.getPosition());
}
