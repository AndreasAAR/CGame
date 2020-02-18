//
// Created by AAR on 2020-02-15.
//

#ifndef CGAME_SPRITE_H
#define CGAME_SPRITE_H
#include <string>
#include <SDL_rect.h>
#include <SDL_image.h>

using namespace std;

class Sprite {

public:

    int getXPos() const { return xPos; }

    int getYPos() const { return yPos; }

    const SDL_Rect &getRect() const { return rect; }

    SDL_Surface *getImage() const { return image;}

    SDL_Texture *getTexture() const { return texture; }

    Sprite(int xPos,int yPos, string path, SDL_Renderer* renderer);

    void draw();

    const string* getPath(){return path; }
//virtual void tick(const Sprite* []);

protected:
    int xPos;
    int yPos;
    string* path;
    SDL_Rect rect;
    SDL_Surface* image;
    SDL_Renderer* renderer;

protected:
    SDL_Texture* texture;


    ~Sprite(){
        SDL_DestroyTexture(texture);
        delete image;
        delete path;
    };
};







#endif //CGAME_SPRITE_H
