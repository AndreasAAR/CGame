//
// Created by AAR on 2020-02-17.
//

#ifndef CGAME_PLAYERSPRITE_H
#define CGAME_PLAYERSPRITE_H

#include "NPCSprite.h"

#include "MovingSprite.h"
#include "NPCSprite.h"

class PlayerSprite: public NPCSprite{


//Supposed to respond to keycommands, Isabelle fix this!

public:
    PlayerSprite(int xPos,int yPos, string path, SDL_Renderer* renderer, Direction direction): NPCSprite(xPos, yPos, path, renderer, direction){
            this->direction = NEUTRAL;
    };
private:
    void move(int x, int y, SDL_Event* event) ;
    void setDirection(SDL_Event* event );
    void tick(int collisionX, int collisionY, SDL_Event *event);

};

//Behöver funktion for move som innehåller keyboardinput
//Behöver också funktion för movement
//Behöver attribut för key

#endif //CGAME_PLAYERSPRITE_H
