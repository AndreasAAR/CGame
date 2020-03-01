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
    Sprite* enemytype;
    int spawnCounter = 0;

    GUI* gui;
    GameEngine(GUI* gui, SDL_Renderer* renderer, int windowHeight, int windowWidth);
    void gameLoop();
    void addSprites(std::vector<Sprite*> sprites);

private:
    int windowWidth;
    int windowHeight;
   void addSprite(Sprite* sprite);
   bool offScreen(Sprite* sprite);
    void manageSprites(SDL_Event* event);
    void deleteSprites();
    bool collidingScreen(SDL_Rect* rect, SDL_Window* window);
    void spawnSprites();
    SDL_Rect collidedOther(Sprite *other, Sprite *current);
};


#endif //CGAME_GAMEENGINE_H
