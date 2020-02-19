//
// Created by AAR on 2020-02-18.
//

#include "NPCSprite.h"

NPCSprite::NPCSprite(int xPos, int yPos, string path, SDL_Renderer *renderer)
        : MovingSprite(xPos, yPos, path, renderer) {
}

void NPCSprite::move(int collideX, int collideY){

    rect.y +=1;

}


void NPCSprite::tick(int collisionX, int collisionY){
    draw();
    move(collisionX,collisionY);
}