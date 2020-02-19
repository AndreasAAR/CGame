//
// Created by AAR on 2020-02-18.
//

#ifndef CGAME_NPCSPRITE_H
#define CGAME_NPCSPRITE_H


#include "MovingSprite.h"

class NPCSprite:public MovingSprite {

public:
    NPCSprite(int xPos, int yPos, string path, SDL_Renderer *renderer);
    void move(int collideX, int collideY);
    void tick(int collisionX, int collisionY);
};


#endif //CGAME_NPCSPRITE_H
