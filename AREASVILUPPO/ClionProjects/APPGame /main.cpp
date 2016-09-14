//
// GameSoftware Created by rudysemola on 01/07/16.
//
/*
 * In questo file troviamo l'istanziazione delle classi e il Game Loop del gioco.
 * Dopo gli Header file,troviamo due funzioni che regolano il movimento "artificiale-autonomo" dei nemici del gioco;
 *
 * Nel main ogni riga o piccola porzione del codice è accompagnata da un breve commento che spiega il suo funzionamento principale.
 *
 * Classi(e file cpp) del gioco:
 *      (main.cpp)
 *      Map.cpp Map.h Tile.cpp Tile.h
 *      Dice.cpp Dice.h Entity.h Enums.h
 *      CreatorFactoryMethod.cpp CreatorFactoryMethod.h
 *      CollEntity.cpp CollEntity.h DeleteEntity.cpp DeleteEntity.h DrawEntity.cpp DrawEntity.h
 *      Player.cpp Player.h Knight.cpp Knight.h
 *      Enemy.h Soldier.cpp Soldier.h  GhostSoldier.cpp GhostSoldier.h
 *      BlockWeapon.cpp BlockWeapon.h
 *      Weapon.h FireBall.cpp FireBall.h Sword.cpp Sword.h
 *      Coin.cpp Coin.h
 *      PowerUp.h PUpConcrete.cpp PUpConcrete.h
*/

#include <iostream>
#include <vector>

#include<SFML/Graphics.hpp>

#include "Dice.h"
#include "CreatorFactoryMethod.h"
#include "CollEntity.h"
#include "DeleteEntity.h"
#include "DrawEntity.h"
#include "Map.h"

/**********************************************************************************************************************/
//AI move enemy
void AImoveEnemy(std::vector<Enemy *> &eA, sf::Clock &clockMove, Map &map, Player *&player) {
    sf::Time timeMove = clockMove.getElapsedTime();

    if (timeMove.asSeconds() > 0.2) {
        clockMove.restart();

        for (auto itr = eA.begin(); itr != eA.end(); itr++) {
            map.collMapEnemy((*itr));
            (*itr)->updateMove(player);
            (*itr)->update();
        }
    }
}

/**********************************************************************************************************************/
int main() {
    Dice::initDice();

    //Create the Game'map
    Map map1;
    map1.loadMap("/home/rudysemola/AREASVILUPPO/Resource/Map1.txt");

    //Create the factory of Entity
    CreatorFactoryMethod factory;
    //Create the object whose manage the collision between Entity
    CollEntity collision;
    //Create the object whose controlls the delete of Entity
    DeleteEntity deleteEntity;
    //Create a object whose draw Entity
    DrawEntity drawEntity;

    //Create a Game'window
    sf::RenderWindow window;
    sf::Vector2i screenDimensions(800, 608);
    window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y), "APPGAME");
    //Create a Game'view
    sf::View gameView;
    gameView.reset(sf::FloatRect(0, 0, screenDimensions.x, screenDimensions.y));

    //Create a clock for the fireball time(1) and (2)for enemy movement (3)fight enemy
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Clock clock3;

    //Create a vector Enemy
    std::vector<Enemy *> enemyArray = factory.createEnemy(TypeEnemy::AllEnemy);

    //Create Missle FireBall
    FireBall fireBall;
    std::vector<FireBall> missleArray;

    //Create Block for Weapon's player
    std::vector<BlockWeapon *> blockWArray = factory.createBlockW();

    //Create Coin
    std::vector<Coin *> coinsArray = factory.createCoins(TypeCoin::AllCoins);

    //Create PowerUp item to caught
    std::vector<PowerUp *> powerUpArray = factory.createPowerUp(TypePowerUp::AllPowerUp);

    //Create a player Game(see even begin Game Loop)
    Player *player = factory.createPlayer(TypePlayer::PlayerKnightFuturistic, screenDimensions);
    TypePlayer typePlayer = TypePlayer::PlayerKnightFuturistic;

    //Start the GAME LOOP
    while (window.isOpen()) {
        //Event,exit with closed or escape
        sf::Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed :
                    window.close();
                    break;
                case sf::Event::KeyPressed :
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
            }
        }
        window.clear(sf::Color::Green);

        //when life player = 0 or select Q(old player dead!) continue game,change the type player
        if (player->getLife() == 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            //During Game Loop the user cans change the player type(old player dead!)
            if (typePlayer == TypePlayer::PlayerKnightFuturistic) {
                delete player;
                player = factory.createPlayer(TypePlayer::PlayerKnightSupreme, screenDimensions);
                typePlayer = TypePlayer::PlayerKnightSupreme;
            }
            else if (typePlayer == TypePlayer::PlayerKnightSupreme) {
                delete player;
                player = factory.createPlayer(TypePlayer::PlayerKnightFuturistic, screenDimensions);
                typePlayer = TypePlayer::PlayerKnightFuturistic;
            }

            blockWArray.clear();
            blockWArray = factory.createBlockW();

            coinsArray.clear();
            coinsArray = factory.createCoins(TypeCoin::AllCoins);

            powerUpArray.clear();
            powerUpArray = factory.createPowerUp(TypePowerUp::AllPowerUp);

            enemyArray.clear();
            enemyArray = factory.createEnemy(TypeEnemy::AllEnemy);
        }
        //Creation of enemy random with Y
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
            factory.createRandomEnemy(enemyArray);
        }

        //Draw the map & manage the collision between player-map collisionable
        map1.updateDraw(window);
        map1.collMap(player);

        //player collision and add numCoin,delete map'coins,Draw & update Coins
        collision.isCaughtCollCoin(coinsArray, player);
        deleteEntity.deleteCoins(coinsArray);
        drawEntity.drawCoins(coinsArray, window);

        //player collision and take the PowerUp,delete map'PowerUp,draw & update powerUp
        collision.isCaughtCollPU(powerUpArray, player);
        deleteEntity.deletePowerUp(powerUpArray);
        drawEntity.drawPowerUp(powerUpArray, window);

        //player collision with box and take the Weapon prime,delete box,draw weapon prime when you use it
        collision.isCaughtCollBlockW(blockWArray, player, factory);
        deleteEntity.deleteBlock(blockWArray);
        drawEntity.drawBlockW(blockWArray, window);

        //Delete projectiles Missle
        deleteEntity.deleteMissle(missleArray);

        //Create Missle or display weapon(sword) player with Z
        sf::Time elapsed1 = clock1.getElapsedTime();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            if (elapsed1.asSeconds() >= 0.075) {
                clock1.restart();
                if (player->getTypeWeapon() == TypeWeapon::Fireball)
                    factory.createMissles(player, fireBall, missleArray);
                if (player->getTypeWeapon() == TypeWeapon::Sword || player->getTypeWeapon() == TypeWeapon::Sword_super)
                    drawEntity.weaponDisplay(player, window);
            }
        }
        //Draw Missle
        drawEntity.drawMissle(window, missleArray, player);

        //dinamic Fight player with enemies
        collision.missleCollEnemy(missleArray, enemyArray);
        collision.weaponCollEnemy(player, enemyArray);

        //Delete enemy if player success fight;player get a prime(PUpConcrete or HeartLife)
        deleteEntity.deleteEnemy(factory, enemyArray, powerUpArray);

        //enemy collides with player:fight enemy
        sf::Time elapsed3 = clock3.getElapsedTime();
        if (elapsed3.asSeconds() >= 0.25) {
            clock1.restart();
            collision.fightAIEnemy(enemyArray, player);
        }

        //Update player
        player->update();
        player->updateMove();
        //Update & move AI enemy
        AImoveEnemy(enemyArray, clock2, map1, player);
        //enemies Collides
        collision.collAIEnemy(enemyArray);

        //Controll View game whose depend by player
        window.setView(gameView);
        gameView.setCenter(player->getRect().getPosition());

        //Draw player
        window.draw(player->getSprite());
        //Draw Enemy
        drawEntity.drawAIEnemy(enemyArray, window);

        //Window display
        window.display();
    }

    return EXIT_SUCCESS;
}