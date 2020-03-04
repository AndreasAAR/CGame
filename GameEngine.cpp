//
// Created by AAR on 2020-02-18.
//

#include "GameEngine.h"
#include "Sprite.h"
#include "NPCSprite.h"
#include "AnimatedEnemy.h"
#include "stdio.h"
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
        if (randomPos > windowHeight - 100)
            randomPos -= 300;
        if (randomPos < 200)
            randomPos += 300;
        string path = bPath+"Resources/pokeball/frame0.png";
       addSprite(new NPCSprite(0, randomPos, bPath + "Resources/pokeball/frame0.png", renderer, RIGHT));

    }

}

void GameEngine::gameLoop() {
    bool runOn = true;
    //Put into a template func!
    while (runOn) {

        //TODO
        // Put spawning in installable function later
        spawnSprites();

        SDL_Event keyPress;
        while (SDL_PollEvent(&keyPress)) {
            switch (keyPress.type) {
                case SDL_QUIT:
                   runOn = false;
            } // switch
        } // inre while
        SDL_RenderClear(renderer);
        //Where sprites are added, collisionchecked and removed
        manageSprites(&keyPress);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
} // yttre while

void GameEngine::manageSprites(SDL_Event* keyPress){
    for (int i = 0; i < sprites.size(); i++) {
        //insert collisioncheck också!
                //Rect to manage collisions in movement func!
                 bool collision;
        Sprite* collSprite;
        collSprite = NULL;
        for(int j = 0; j < sprites.size(); j++){
            Sprite* otherSprite = sprites[j];
            if(j != i){
                collision = collidedOther(sprites[i],otherSprite);
                if(collision){
                    collSprite = sprites[i];
                }
            }
         }
        if(offScreen(sprites[i])){
            spritesToDelete.push_back(sprites[i]);
        }else{
            sprites[i]->tick(0,0,keyPress);
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

bool GameEngine::collidedOther(Sprite *other, Sprite *current){

    //These variables hold the topleft and bottomright
    //corner coordinates!
    struct Point{
        int x;
        int y;
    };
    Point otherTopLeft = { other->getRect().x , other->getRect().y};
    Point otherBotRight = { otherTopLeft.x +  other->getRect().w ,
                            otherTopLeft.y + other->getRect().h };
    Point currentTopLeft ={current->getRect().x, current->getRect().y};
    Point currentBotRight = {currentTopLeft.x + current->getRect().w,currentTopLeft.y + current->getRect().h};


   //Checks if one is above other
   if(currentBotRight.y < otherTopLeft.y || otherBotRight.y < currentTopLeft.y){
       return false;
   }
   //Checks if one is left of other
   if(currentBotRight.x < otherBotRight.x || currentTopLeft.x > otherBotRight.x){
      return false;

   }
    cout<<"We had a collission!"<<endl;
   return  true;

};



GameEngine::GameEngine(GUI *gui, SDL_Renderer *renderer,int windowHeight, int windowWidth) {
    string bPath = SDL_GetBasePath();
    this->renderer = renderer;
    this->gui = gui;
    this->windowWidth= windowWidth;
    this->windowHeight = windowHeight;
    addSprite(new PlayerSprite(300, 300, bPath + "Resources/Protagonist.png", renderer, LEFT));
}


