//
// Created by AAR on 2020-02-15.
//

#include "Sprite.h"
#include <string>
#include <iostream>

Sprite::Sprite(int xPos,int yPos, string path, SDL_Renderer* renderer){
    image = IMG_Load(path.c_str());
    this->texture = SDL_CreateTextureFromSurface(renderer,image);
    cout<<"Got into"<<endl;
    cout<<xPos<<yPos<<endl;
    cout<<image->w<<image->h<<endl;
    rect = {xPos,yPos, image->w,image->h};
};



