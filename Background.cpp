//
// Created by AAR on 2020-03-04.
//

#include "Background.h"

void Background::tick(int x, int y, SDL_Event *event){
    //Does nothing
    draw();

};
Background::Background(int xPos, int yPos, const string &path, SDL_Renderer *renderer) : Sprite(xPos, yPos, path,
                                                                                                renderer) {};
