//
// Created by AAR on 2020-02-27.
//

#ifndef CGAME_ANIMATEDENEMY_H
#define CGAME_ANIMATEDENEMY_H


#include <vector>
#include "NPCSprite.h"
class AnimatedEnemy : public NPCSprite {
public:
    AnimatedEnemy(int xPos, int yPos, const string &path, SDL_Renderer *renderer, Direction direction
                      );

    void tick(Sprite* sprite) override{
        NPCSprite::tick(sprite);
        updateImage();
    }
    void updateImage();
private:
    int numberFrames;
    int currentFrame = 0;
};


#endif //CGAME_ANIMATEDENEMY_H