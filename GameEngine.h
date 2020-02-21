//
// Created by AAR on 2020-02-18.
//

#ifndef CGAME_GAMEENGINE_H
#define CGAME_GAMEENGINE_H

#include <vector>
#include "GUI.h"
#include "Sprite.h"



class GameEngine {

    std::vector<Sprite*> spritesToRemove;
    std::vector<Sprite*> sprites;
    SDL_Renderer* renderer;
    GUI* gui;

public:
    GameEngine(GUI* gui, SDL_Renderer* renderer);
    void gameLoop();
    void addSprites(std::vector<Sprite*> sprites);
};


#endif //CGAME_GAMEENGINE_H
