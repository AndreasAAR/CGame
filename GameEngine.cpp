//
// Created by AAR on 2020-02-18.
//

#include "GameEngine.h"
#include "Sprite.h"
#include "NPCSprite.h"
#include "PlayerSprite.h"

void GameEngine::addSprite(Sprite* sprite){
    GameEngine::sprites.push_back(sprite);
}

//Make so sent as
void GameEngine::spawnSprites(){
    string bPath = SDL_GetBasePath();
    spawnCounter++;
    if (spawnCounter % 500 == 0) {
        int randomPos = rand() % windowHeight - 100;
        if (randomPos > windowHeight - 200)
            randomPos -= 300;
        if (randomPos < 200)
            randomPos += 300;
       // addSprite(new NPCSprite(0, randomPos, bPath + "Resources/Protagonist.png", renderer, RIGHT));
    }

}

void GameEngine::gameLoop() {
    bool runOn = true;
    //Put into a template func!
    while (runOn) {

        //TODO
        // Put spawning in installable function later
        spawnSprites();

        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT:
                   runOn = false;
                    break;
                case SDL_KEYDOWN:
                    if (eve.key.keysym.sym == SDLK_DOWN)
                       // runOn = false;
                    break;
            } // switch
        } // inre while
        SDL_RenderClear(renderer);
        //Where sprites are added, collisionchecked and removed
        manageSprites(&eve);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

} // yttre while



void GameEngine::manageSprites(SDL_Event* event){

    for (int i = 0; i < sprites.size(); i++) {
        //insert collisioncheck också!
        int collisionX = NULL;
        int collissionY = NULL;
        if(offScreen(sprites[i])){
            spritesToDelete.push_back(sprites[i]);
        }else{
            sprites[i]->tick(collisionX, collissionY,event);
        }
    }

    deleteSprites();
    collidedSprites.clear();
}

void GameEngine::deleteSprites(){

    for (Sprite* s : spritesToDelete) {
        for (vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();)
            if (*i == s) {
                sprites.erase(i);
                delete s;
            }//if
            else
                i++;
    }//outer for
    spritesToDelete.clear();
}


bool GameEngine::offScreen(Sprite* sprite){

    if(sprite->getRect().x > windowWidth+200){
        return true;
    }
    return false;
}

SDL_Rect GameEngine::collidedOther(Sprite *other, Sprite *current){

};



GameEngine::GameEngine(GUI *gui, SDL_Renderer *renderer,int windowHeight, int windowWidth) {
    string bPath = SDL_GetBasePath();
    this->renderer = renderer;
    this->gui = gui;
    this->windowWidth= windowWidth;
    this->windowHeight = windowHeight;
    addSprite(new PlayerSprite(300, 300, bPath + "Resources/Protagonist.png", renderer, LEFT));
}


