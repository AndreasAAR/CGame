//
// Created by Isabelle Grimborg on 2020-03-01.
//
#include "PlayerSprite.h"

void PlayerSprite::setDirection(SDL_Event *event) {
    Direction currentDirection = LEFT;

    switch (event->key.keysym.sym) {
        case SDLK_LEFT:
            currentDirection = LEFT;
            break;
        case SDLK_RIGHT:
            currentDirection = RIGHT;
            break;
        case SDLK_UP:
            currentDirection = TOP;
            break;
        case SDLK_DOWN:
            currentDirection = BOT;
            break;
        default:
            break;
    }
    this->direction = currentDirection;
}
void PlayerSprite::move(int collisionX, int collisionY){
    NPCSprite::move(collisionX,collisionY);
}
void PlayerSprite::tick(int collisionX, int collisionY, SDL_Event *event){
    setDirection(event);
    NPCSprite::tick(collisionX,collisionY,event);
}