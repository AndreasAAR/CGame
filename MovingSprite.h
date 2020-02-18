//
// Created by AAR on 2020-02-17.
//

#ifndef CGAME_MOVINGSPRITE_H
#define CGAME_MOVINGSPRITE_H

#include "Sprite.h"
#include <SDL_rect.h>
#include <SDL_image.h>

class MovingSprite: Sprite{

public:
    MovingSprite(int xPos, int yPos, string path, SDL_Renderer* renderer): Sprite(xPos, yPos, path, renderer){};

    ~MovingSprite(){
        this->~Sprite();
    };
protected:
    virtual void move(int collideX, int collideY);
};


#endif //CGAME_MOVINGSPRITE_H
