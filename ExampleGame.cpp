#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <SDL_video.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "GUI.h"


using namespace std;


string bPath = SDL_GetBasePath();
string path = bPath + "/Enemy.png";

int main() {
              // Initialize SDL2



    // Create an application window with the following settings:


    GUI* gui = new GUI("PokeDodgeBall", 800,500);
    SDL_Window* window = gui->getWin();
    SDL_Renderer* renderer = gui->getRen();



    SDL_Surface* bild = IMG_Load(path.c_str());
    SDL_Texture* tx = SDL_CreateTextureFromSurface(renderer, bild);
    SDL_FreeSurface(bild);
    SDL_Rect protRect = {5,5,bild->w,bild->h};


    Sprite* bulbasaur =  new Sprite(300,300,bPath+"Resources/Protagonist.png",renderer);


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
        SDL_RenderCopy(renderer, tx, NULL, &protRect);
        bulbasaur->draw();
        SDL_RenderPresent(renderer);

    } // yttre while
    SDL_DestroyTexture(tx);


    SDL_Quit();
    return 0;

}

