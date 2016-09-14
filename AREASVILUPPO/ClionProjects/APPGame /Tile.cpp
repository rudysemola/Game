//
// Created by rudysemola on 08/09/16.
//

#include "Tile.h"

Tile::Tile() { }

sf::Sprite Tile::loadSprite(TypeTile typeTile) {
    sf::Sprite sprite;
    image.loadFromFile(
            "/home/rudysemola/AREASVILUPPO/Resource/sprite/tilenoncoll.png");
    texture.loadFromImage(image);
    sf::Sprite tempsprite(texture);

    if (typeTile == TypeTile::NoCollGrass_11) {                          //0
        tempsprite.setTextureRect(sf::IntRect(6 * 32, 1 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWall_11) {                       //1
        tempsprite.setTextureRect(sf::IntRect(4 * 32, 1 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWall_12) {                       //2
        tempsprite.setTextureRect(sf::IntRect(4 * 32, 2 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWall_21) {                       //3
        tempsprite.setTextureRect(sf::IntRect(5 * 32, 1 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWall_22) {                       //4
        tempsprite.setTextureRect(sf::IntRect(5 * 32, 2 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::NoCollGrass_12) {                     //5
        tempsprite.setTextureRect(sf::IntRect(7 * 32, 1 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::NoCollGrass_21) {                     //6
        tempsprite.setTextureRect(sf::IntRect(6 * 32, 2 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::NoCollGrass_22) {                     //7
        tempsprite.setTextureRect(sf::IntRect(7 * 32, 2 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWater_11) {                       //8
        tempsprite.setTextureRect(sf::IntRect(4 * 32, 4 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWater_12) {                       //9
        tempsprite.setTextureRect(sf::IntRect(5 * 32, 4 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWater_21) {                       //10
        tempsprite.setTextureRect(sf::IntRect(4 * 32, 5 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollWater_22) {                       //11
        tempsprite.setTextureRect(sf::IntRect(5 * 32, 5 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollGrass) {                          //12
        tempsprite.setTextureRect(sf::IntRect(10 * 32, 3 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollTrampolineRotate_11) {            //13
        tempsprite.setTextureRect(sf::IntRect(14 * 32, 11 * 32, 32, 32));
        tempsprite.setRotation(180);
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollTrampolineRotate_12) {            //14
        tempsprite.setTextureRect(sf::IntRect(15 * 32, 11 * 32, 32, 32));
        tempsprite.setRotation(180);
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollTrampoline_21) {                  //15
        tempsprite.setTextureRect(sf::IntRect(14 * 32, 10 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollTrampoline_22) {                  //16
        tempsprite.setTextureRect(sf::IntRect(15 * 32, 10 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollTrampoline_31) {                  //17
        tempsprite.setTextureRect(sf::IntRect(14 * 32, 11 * 32, 32, 32));
        sprite = tempsprite;
    }
    else if (typeTile == TypeTile::CollTrampoline_32) {                  //18
        tempsprite.setTextureRect(sf::IntRect(15 * 32, 11 * 32, 32, 32));
        sprite = tempsprite;
    }
    else {
        tempsprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
        sprite = tempsprite;
    }

    return sprite;
}

//se il giocatore collsiona con parti non oltrepassabili della mappa
void Tile::manageTileColl(Player *&player, sf::Sprite &tile, TypeTile typeTile) {
    if (typeTile == TypeTile::CollWall_11 || typeTile == TypeTile::CollWall_12 || typeTile == TypeTile::CollWater_21 ||
        typeTile == TypeTile::CollWater_22 || typeTile == TypeTile::CollWater_11 ||
        typeTile == TypeTile::CollWater_12 ||
        typeTile == TypeTile::CollGrass || typeTile == TypeTile::CollTrampolineRotate_11
        || typeTile == TypeTile::CollTrampoline_21 || typeTile == TypeTile::CollTrampoline_31) {

        if (player->getRect().getGlobalBounds().intersects(tile.getGlobalBounds())) {
            if (player->getTypeP() == Direction::Up) {
                player->setCanMoveUp(false);
                player->changeMoveRect(0, 1);
            }
            else if (player->getTypeP() == Direction::Down) {
                player->setCanMoveDown(false);
                player->changeMoveRect(0, -1);
            }
            else if (player->getTypeP() == Direction::Left) {
                player->setCanMoveLeft(false);
                player->changeMoveRect(1, 0);
            }
            else if (player->getTypeP() == Direction::Right) {
                player->setCanMoveRight(false);
                player->changeMoveRect(-1, 0);
            }
        }
    }
}

//se il nemico collsiona con parti non oltrepassabili della mappa
void Tile::manageTileCollEnemy(Enemy*& enemy, sf::Sprite &tile, TypeTile typeTile) {
    if (typeTile == TypeTile::CollWall_11 || typeTile == TypeTile::CollWall_12 || typeTile == TypeTile::CollWater_21 ||
        typeTile == TypeTile::CollWater_22 || typeTile == TypeTile::CollWater_11 ||
        typeTile == TypeTile::CollWater_12 ||
        typeTile == TypeTile::CollGrass || typeTile == TypeTile::CollTrampolineRotate_11
        || typeTile == TypeTile::CollTrampoline_21 || typeTile == TypeTile::CollTrampoline_31) {

        if (enemy->getRect().getGlobalBounds().intersects(tile.getGlobalBounds())) {
            if (enemy->getDirectionType() == Direction::Up) {
                enemy->setCanMoveUp(false);
                enemy->changeMoveRect(0, 1);
            }
            else if (enemy->getDirectionType() == Direction::Down) {
                enemy->setCanMoveDown(false);
                enemy->changeMoveRect(0, -1);
            }
            else if (enemy->getDirectionType() == Direction::Left) {
                enemy->setCanMoveLeft(false);
                enemy->changeMoveRect(1, 0);
            }
            else if (enemy->getDirectionType() == Direction::Right) {
                enemy->setCanMoveRight(false);
                enemy->changeMoveRect(-1, 0);
            }
        }
    }
}
