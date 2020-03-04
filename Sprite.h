//
// Created by AAR on 2020-02-15.
//

#ifndef CGAME_SPRITE_H
#define CGAME_SPRITE_H
#include <string>
#include <SDL_rect.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;

class Sprite {

public:

    int getXPos() const { return xPos; }

    int getYPos() const { return yPos; }

    const SDL_Rect getRect() const { return rect; }

    SDL_Surface *getImage() const { return image;}

    SDL_Texture *getTexture() const { return texture; }
    SDL_Surface* image;
    Sprite(int xPos,int yPos, string path, SDL_Renderer* renderer);

    void draw();
    virtual void tick(Sprite* collissionSprite) = 0;
    virtual ~Sprite(){
        SDL_DestroyTexture(texture);
    };
protected:
    int xPos;
    int yPos;
    string* path;
    SDL_Rect rect;

    SDL_Renderer* renderer;


protected:
    SDL_Texture* texture;



};

#endif //CGAME_SPRITE_H
