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



}

