//
// Created by AAR on 2020-02-27.
//

#include "AnimatedEnemy.h"

AnimatedEnemy::AnimatedEnemy(int xPos, int yPos, const string &path, SDL_Renderer *renderer, Direction direction,
                              string imagePath,  string imageFolder,int NUMBERFRAMES) :
        NPCSprite (xPos, yPos, path, renderer, direction){

}

void AnimatedEnemy::updateImage() {
   image = IMG_Load(imagePaths[currentFrame].c_str());
   currentFrame++;
   if(currentFrame < NUMBERFRAMES){
       currentFrame = 0;
   }
}



