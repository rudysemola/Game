cmake_minimum_required(VERSION 3.5)
project(APPGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp
        Map.cpp Map.h Tile.cpp Tile.h
        Dice.cpp Dice.h Entity.h Enums.h
        CreatorFactoryMethod.cpp CreatorFactoryMethod.h
        CollEntity.cpp CollEntity.h DeleteEntity.cpp DeleteEntity.h DrawEntity.cpp DrawEntity.h
        Player.cpp Player.h Knight.cpp Knight.h
        Enemy.h Soldier.cpp Soldier.h  GhostSoldier.cpp GhostSoldier.h
        BlockWeapon.cpp BlockWeapon.h
        Weapon.h FireBall.cpp FireBall.h Sword.cpp Sword.h
        Coin.cpp Coin.h
        PowerUp.h PUpConcrete.cpp PUpConcrete.h
        AbStrategyMove.h CSRandom.cpp CSRandom.h CSChase.cpp CSChase.h)

set(CMAKE_MODULE_PATH  "${CMAKE_SOURCE_DIR}/CMake_Modules/" ${CMAKE_MODULE_PATH})
find_package(SFML 2.3 COMPONENTS system window graphics audio REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    add_executable(APPGame ${SOURCE_FILES})
    add_library(core ${SOURCE_FILES})
    target_link_libraries(APPGame ${SFML_LIBRARIES})
endif()


