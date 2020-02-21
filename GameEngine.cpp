//
// Created by AAR on 2020-02-18.
//

#include "GameEngine.h"


void GameEngine::gameLoop() {

    bool runOn = true;

    //insert game specific spawning and destruction "EngineTick"

    while (runOn) {
        SDL_Event eve;
        while(SDL_PollEvent(&eve)){
            switch (eve.type) {
                case SDL_QUIT: runOn = false; break;
                case SDL_KEYDOWN:
                    if (eve.key.keysym.sym == SDLK_DOWN)
                        runOn = false;
                    break;
            } // switch
        } // inre while
        SDL_RenderClear(renderer);
        for(int i = 0; i< sprites.size();i++){
            sprites[i]->tick(NULL,NULL);
        }
        SDL_RenderPresent(renderer);
    } // yttre while

    SDL_Quit();

}



GameEngine::GameEngine(GUI *gui, SDL_Renderer *renderer) {
    this->renderer = renderer;
    this->gui = gui;
}


