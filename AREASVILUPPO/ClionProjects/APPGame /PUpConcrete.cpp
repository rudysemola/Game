//
// Created by rudysemola on 21/07/16.
//

#include "PUpConcrete.h"
#include "Dice.h"

PUpConcrete::PUpConcrete(TypePowerUp type,int nA,bool d) : PowerUp(nA,type,d) {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::Blue);

    sf::Sprite tempsprite(texture);
    tempsprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

    if(typePowerUp == TypePowerUp::StarHP)
        image.loadFromFile(
            "/home/rudysemola/AREASVILUPPO/Resource/sprite/KMA_Warp_Star_sprite.png");
    else
        image.loadFromFile(
                "/home/rudysemola/AREASVILUPPO/Resource/sprite/heartlife.png");

    texture.loadFromImage(image);
    sprite = tempsprite;
}

void PUpConcrete::update() {
    sprite.setPosition(rect.getPosition());
}

int PUpConcrete::isCaught() {
    Dice aDice(6);
    int newHP;
    int newLife;

    if(typePowerUp == TypePowerUp::StarHP) {
        if (aDice.throwDice() >= numActivator) {
            newHP = 100;
        }
        else
            newHP = 25;

        return newHP;
    }
    else if(typePowerUp == TypePowerUp::HeartLife) {
        if (aDice.throwDice() > numActivator) {
            newLife = 2;
        }
        else
            newLife = 1;

        return newLife;
    }
    else
        return 0;
}
