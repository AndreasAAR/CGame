//
// Created by AAR on 2020-02-27.
//

#ifndef CGAME_ANIMATEDENEMY_H
#define CGAME_ANIMATEDENEMY_H


#include <vector>
#include "NPCSprite.h"
class AnimatedEnemy : public NPCSprite {
public:
    AnimatedEnemy(int xPos, int yPos, const string &path, SDL_Renderer *renderer, Direction direction, string imagePath,
                      string imageFolder, int NUMBERFRAMES);

    void tick(int collisionX, int collisionY) override{
        NPCSprite::tick(collisionX, collisionY);
        updateImage();

    }
    void updateImage();
private:
    int NUMBERFRAMES = 5;
    int currentFrame = 0;
    std::vector<string> imagePaths;
};


#endif //CGAME_ANIMATEDENEMY_H
