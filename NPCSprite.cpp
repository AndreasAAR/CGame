//
// Created by AAR on 2020-02-18.
//

#include <SDL_rect.h>
#include <SDL_render.h>
#include "MovingSprite.h"
#include "NPCSprite.h"

NPCSprite::NPCSprite(int xPos, int yPos, string path, SDL_Renderer *renderer,Direction direction)
        : MovingSprite(xPos, yPos, path, renderer) {
    this->direction = direction;

}

void NPCSprite::move(int x, int y) {

    int xNew =  this->getRect().x;
    int yNew =  this->getRect().y;

    switch(direction){
        case(TOP):
            yNew--;
            break;
        case(BOT):
            yNew++;
            break;
        case(LEFT):
            xNew--;
            break;
        case(RIGHT):
            xNew++;
            break;
    }
    MovingSprite::move(xNew,yNew);
}

void NPCSprite::tick(Sprite* sprite){
    move(0,0);
    draw();

}

