//
// Created by rudysemola on 08/09/16.
//

#ifndef GAMESOFTWARE_TILE_H
#define GAMESOFTWARE_TILE_H

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enums.h"
#include "Enemy.h"

class Tile {
public:
    Tile();

    sf::Sprite loadSprite(TypeTile typeTile);

    void manageTileColl(Player* &player,sf::Sprite& tile,TypeTile typeTile);

    void manageTileCollEnemy(Enemy*& enemy,sf::Sprite& tile,TypeTile typeTile);

private:
    sf::Image image;
    sf::Texture texture;
};


#endif //GAMESOFTWARE_TILE_H
