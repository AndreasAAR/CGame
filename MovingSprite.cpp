//
// Created by AAR on 2020-02-19.
//

#include "MovingSprite.h"
#include "SDL_rect.h"

void MovingSprite::tick(Sprite* collissionSprite){

    move(0,0);
    draw();

}

void MovingSprite::move(int x, int y) {
            this->rect.x=x;
            this->rect.y=y;
}