//
// Created by rudysemola on 21/07/16.
//

#include "FireBall.h"

FireBall::FireBall(bool poss,int s) : Weapon(poss,s),movementSpeed(15),lifeTime(10),counterLifeTime(0),counterAnimation(0) {
    rect.setSize(sf::Vector2f(32,32));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    tempsprite.setTextureRect(sf::IntRect(0,0,32,32));

    image.loadFromFile("/home/rudysemola/AREASVILUPPO/Resource/sprite/fireballsprite.png");
    texture.loadFromImage(image);
    sprite = tempsprite;
}

void FireBall::update(Direction type) {
    if(type != Direction::null) {
        if( type == Direction::Up )
        {
            rect.move(0,-movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterAnimation*32,0,32,32));
        }
        else if( type == Direction::Down )
        {
            rect.move(0,movementSpeed);
            sprite.setTextureRect(sf::IntRect(counterAnimation*32,32*3,32,32));
        }
        else if( type == Direction::Right )
        {
            rect.move(movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterAnimation*32,32*1,32,32));
        }
        else if( type == Direction::Left )
        {
            rect.move(-movementSpeed,0);
            sprite.setTextureRect(sf::IntRect(counterAnimation*32,32*2,32,32));
        }

        counterLifeTime++;
        if( counterLifeTime >= lifeTime )
            destroy = true;

        counterAnimation++;
        if( counterAnimation >= 2 )
            counterAnimation = 0;
    }

    sprite.setPosition(rect.getPosition());
}


