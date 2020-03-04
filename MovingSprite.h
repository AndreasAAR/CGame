//
// Created by AAR on 2020-02-17.
//

#ifndef CGAME_MOVINGSPRITE_H
#define CGAME_MOVINGSPRITE_H

#include "Sprite.h"
#include <SDL_rect.h>
#include <SDL_image.h>

class MovingSprite:public Sprite{

public:
    MovingSprite(int xPos, int yPos, string path, SDL_Renderer* renderer): Sprite(xPos, yPos, path, renderer)
    {
    };
    void tick(Sprite* collissionSprite);
protected:
    void move(int x, int y);
};




#endif //CGAME_MOVINGSPRITE_H
