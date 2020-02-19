//
// Created by AAR on 2020-02-18.
//

#ifndef CGAME_GAMEENGINE_H
#define CGAME_GAMEENGINE_H

#include <vector>
#include "GUI.h"
#include "Sprite.h"

class GameEngine {

    GUI gui;
    std::vector<Sprite*> spritesToRemove;
    std::vector<Sprite*> sprites;

public:
    GameEngine(GUI gui);
    void gameLoop();
    void addSprites(std::vector<Sprite*> sprites);
};


#endif //CGAME_GAMEENGINE_H
