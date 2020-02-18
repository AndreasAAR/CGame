//
// Created by AAR on 2020-02-17.
//

#ifndef CGAME_PLAYERSPRITE_H
#define CGAME_PLAYERSPRITE_H

#include "MovingSprite.h"

class Player: MovingSprite{


//Supposed to respond to keycommands, Isabelle fix this!

public:
    Player(int xPos,int yPos, string* path): MovingSprite(xPos, yPos, path){}
private:
    void move(const Sprite* []){};

};

#endif //CGAME_PLAYERSPRITE_H
