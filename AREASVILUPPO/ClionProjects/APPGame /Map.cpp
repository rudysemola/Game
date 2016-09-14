//
// Created by rudysemola on 16/07/16.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "Map.h"

Map::Map() : tile(new Tile) { }

Map::~Map() {
    for (auto itr = map.begin(); itr != map.end(); itr++) {
        map.erase(itr);
    }

    for (auto itrS = mapSprite.begin(); itrS != mapSprite.end(); itrS++) {
        mapSprite.erase(itrS);
    }

    if(tile != nullptr)
        delete tile;
}

void Map::loadMap(const char *filename) {
    std::ifstream openfile;
    openfile.open(filename);

    std::vector<int> tempmap;
    map.clear();

    if (openfile.is_open()) {

        while (!openfile.eof()) {
            std::string value;
            std::string str;
            std::getline(openfile, str);
            std::stringstream stream(str);

            while (std::getline(stream, value, ' ')) {
                if (value.length() > 0) {

                    int a = atoi(value.c_str());
                    tempmap.push_back(a);
                }
            }
            if (tempmap.size() > 0) {
                map.push_back(tempmap);
                tempmap.clear();
            }
        }
    }
    openfile.close();

    int i, j;
    mapSprite.clear();

    for (i = 0; i < map.size(); i++) {
        for (j = 0; j < map[i].size(); j++) {
            if (map[i][j] != -1) {
                typeTile = static_cast<TypeTile >(map[i][j]);
                sf::Sprite tempSprite = tile->loadSprite(typeTile);
                tempSprite.setPosition(j * 32, i * 32);

                mapSprite.push_back(tempSprite);
            }
        }
    }
}

void Map::updateDraw(sf::RenderWindow &w) {

    for (auto itr = mapSprite.begin(); itr != mapSprite.end(); itr++) {
        w.draw((*itr));
    }
}

void Map::collMap(Player* &player) {
    int i, j;
    auto itr=mapSprite.begin();

    for (i = 0; i < map.size(); i++) {
        for (j = 0; j < map[i].size(); j++) {
            if (map[i][j] != -1) {

                if(itr != mapSprite.end()) {
                    typeTile = static_cast<TypeTile >(map[i][j]);
                    tile->manageTileColl(player,(*itr),typeTile);

                    itr++;
                }
            }
        }
    }
}

void Map::collMapEnemy(Enemy *enemy) {
    int i, j;
    auto itr=mapSprite.begin();

    for (i = 0; i < map.size(); i++) {
        for (j = 0; j < map[i].size(); j++) {
            if (map[i][j] != -1) {

                if(itr != mapSprite.end()) {
                    typeTile = static_cast<TypeTile >(map[i][j]);
                    tile->manageTileCollEnemy(enemy,(*itr),typeTile);

                    itr++;
                }
            }
        }
    }
}


