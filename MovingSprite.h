//
// Created by AAR on 2020-02-17.
//

#ifndef CGAME_MOVINGSPRITE_H
#define CGAME_MOVINGSPRITE_H

#include "Sprite.h"

class MovingSprite: Sprite{

public:
    MovingSprite(int xPos, int yPos, string* path): Sprite(xPos, yPos, path){};

    ~MovingSprite(){
        this->~Sprite();
    };
protected:
    virtual void move(int collideX, int collideY){};
};


#endif //CGAME_MOVINGSPRITE_H
