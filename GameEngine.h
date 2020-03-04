//
// Created by AAR on 2020-02-18.
//

#ifndef CGAME_GAMEENGINE_H
#define CGAME_GAMEENGINE_H

#include <vector>
#include "GUI.h"
#include "Sprite.h"

using namespace std;

class GameEngine {
public:

    vector<Sprite*>  spritesToDelete;
    vector<Sprite*>  collidedSprites;
    vector<Sprite*>  sprites;
    SDL_Renderer* renderer;
    int spawnCounter = 0;

    GUI* gui;
    GameEngine(GUI* gui, SDL_Renderer* renderer, int windowHeight, int windowWidth);
    void gameLoop();

private:
    bool lost = false;
    int windowWidth;
    int windowHeight;
   void addSprite(Sprite* sprite);
   bool offScreen(Sprite* sprite);
    void deleteSprites();
    bool collidingScreen(SDL_Rect rect, SDL_Window* window);
    void spawnSprites();
    bool collidedOther(Sprite *other, Sprite *current);
    void manageSprites(SDL_Event* keyPress);
};


#endif //CGAME_GAMEENGINE_H
