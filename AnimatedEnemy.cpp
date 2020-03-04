//
// Created by AAR on 2020-02-27.
//

#include "AnimatedEnemy.h"
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>
typedef std::vector<std::string> stringvec;

AnimatedEnemy::AnimatedEnemy(int xPos, int yPos, const string &path, SDL_Renderer *renderer, Direction direction
                               ) :
        NPCSprite (xPos, yPos, path, renderer, direction){
}




void AnimatedEnemy::updateImage() {

    string currentPath;
    currentPath += "frame"+to_string(currentFrame);
    currentPath+=".png";
   image = IMG_Load(currentPath.c_str());
   currentFrame++;
   if(currentFrame < numberFrames){
       currentFrame = 0;
   }
}




