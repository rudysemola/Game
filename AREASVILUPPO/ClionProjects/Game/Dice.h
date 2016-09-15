//
// Created by rudysemola on 21/07/16.
//
/*
 * ...
 */
#ifndef GAMESOFTWARE_DICE_H
#define GAMESOFTWARE_DICE_H

class Dice {
public:
    explicit Dice(int f=6) : faces(f) { }

    int throwDice();

    static void initDice();

    int getFaces() const { return faces; }

    void setFaces(int faces) {
        if( faces<4 )
            faces = 6;
        Dice::faces = faces;
    }

private:
    int faces;
    static bool inizialized;
};


#endif //GAMESOFTWARE_DICE_H
