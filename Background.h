//
// Created by AAR on 2020-03-04.
//

#ifndef CGAME_BACKGROUND_H
#define CGAME_BACKGROUND_H


#include "Sprite.h"

class Background : public Sprite{
public:
    void tick(int x, int y, SDL_Event *event);
    Background(int xPos, int yPos, const string &path, SDL_Renderer *renderer);

};


#endif //CGAME_BACKGROUND_H
