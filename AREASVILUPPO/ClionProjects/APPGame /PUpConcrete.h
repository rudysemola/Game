//
// Created by rudysemola on 21/07/16.
//
/*
 * Attributi della classe(ereditati):
 *  sf::RectangleShape rect;
 *  sf::Image image;
 *  sf::Texture texture;
 *  sf::Sprite sprite;
 *  sf::Text text;
 *      int numActivator;
 *      bool destroy;
 *      TypePowerUp typePowerUp;
 */
#ifndef GAMESOFTWARE_UNBEATEN_H
#define GAMESOFTWARE_UNBEATEN_H

#include "PowerUp.h"

class PUpConcrete : public PowerUp {
public:
    explicit PUpConcrete(TypePowerUp type,int nA = 3,bool d = false);

    virtual ~PUpConcrete() { }

    virtual void update() override;

    virtual int isCaught() override;
};

#endif //GAMESOFTWARE_UNBEATEN_H
