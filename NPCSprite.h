//
// Created by AAR on 2020-02-18.
//

#ifndef CGAME_NPCSPRITE_H
#define CGAME_NPCSPRITE_H


#include "MovingSprite.h"


enum Direction{
    TOP,BOT,LEFT,RIGHT, NEUTRAL
};

class NPCSprite:public MovingSprite {

public:
    Direction direction;
     NPCSprite(int xPos, int yPos, string path, SDL_Renderer *renderer, Direction direction);
     void move(int x, int y);
   void tick(int collisionX, int collisionY, SDL_Event *event) ;

};


#endif //CGAME_NPCSPRITE_H
