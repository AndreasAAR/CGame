#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <SDL_video.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "GUI.h"
#include <vector>
#include "NPCSprite.h"

using namespace std;


string bPath = SDL_GetBasePath();


int main() {
    // Initialize SDL2
    // Create an application window with the following settings:
    GUI* gui = new GUI("PokeDodgeBall", 800,500);
    SDL_Window* window = gui->getWin();
    SDL_Renderer* renderer = gui->getRen();

    NPCSprite* bulMove =  new NPCSprite(150,150,bPath+"Resources/Protagonist.png",renderer);

    vector<Sprite*> sprites =  {bulMove};
    vector<Sprite*> spritesToRemove;

    bool runOn = true;

    // form new destination rect
    // The window is open: could enter program loop here (see SDL_PollEvent())
    // Close and destroy the window
    // Clean up

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
    return 0;

}

