//
// Created by rudysemola on 16/07/16.
//
/*
 * Classe mappa del gioco:
 */
#ifndef GAMESOFTWARE_MAP_H
#define GAMESOFTWARE_MAP_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Enums.h"

#include "Tile.h"

class Map {
public:
    Map();

    virtual ~Map();

    void loadMap(const char *filename);

    void updateDraw(sf::RenderWindow &w);

    void collMap(Player* &player);

    void collMapEnemy(Enemy* enemy);

private:
    Tile * tile;

    TypeTile typeTile;
    std::vector<std::vector<int>> map;
    std::vector<sf::Sprite> mapSprite;
};

#endif //GAMESOFTWARE_MAP_H
