//
// Created by rudysemola on 28/07/16.
//

/*
 * Uso del pattern FactoryMethod per la creazione di oggetti delle classi entity
 */

#ifndef GAMESOFTWARE_CREATORFACTORYMETHOD_H
#define GAMESOFTWARE_CREATORFACTORYMETHOD_H

#include <vector>

#include "Coin.h"
#include "PUpConcrete.h"
#include "BlockWeapon.h"
#include "Weapon.h"
#include "FireBall.h"
#include "Player.h"
#include "Enemy.h"

#include "Enums.h"

class CreatorFactoryMethod {
public:
    Player *createPlayer(TypePlayer type,sf::Vector2i& screen);

    std::vector<Enemy *> createEnemy(TypeEnemy typeEnemy);
    //Creazione di tutti gli enemy del gioco(usato all'inizio del gioco,al cambio o morte del player)
    void createAllEnemy(std::vector<Enemy *> &enemyArray);
    //Creazione Enemy random (By press Y)
    void createRandomEnemy(std::vector<Enemy *> &enemyArray);

    std::vector<Coin *> createCoins(TypeCoin typeCoin);
    //Creazione di tutti i coins del gioco(usato all'inizio del gioco,al cambio o morte del player)
    void createAllCoins(std::vector<Coin *> &coinsArray);

    std::vector<PowerUp *> createPowerUp(TypePowerUp typePU);
    //battuto il nemico si crea un PowerUp dove era stato distrutto il nemico
    void primePowerUp(TypePowerUp typePU,std::vector<PowerUp *> &pUpArray, Enemy *enemy);
    //Creazione di tutti i powerUp del gioco(usato all'inizio del gioco,al cambio o morte del player)
    void createAllPowerUp(std::vector<PowerUp *> &pUpArray);

    std::vector<BlockWeapon *> createBlockW();

    Weapon* createWeapon(TypeWeapon typeW);

    //Funzione creazione missili di FireBall
    void createMissles(Player* &player, FireBall &weapon, std::vector<FireBall> &wMissle);
};


#endif //GAMESOFTWARE_CREATORFACTORYMETHOD_H
