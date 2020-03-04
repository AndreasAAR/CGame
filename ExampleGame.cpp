#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <SDL_video.h>
#include <SDL_image.h>
#include "Sprite.h"
#include "GUI.h"
#include <vector>
#include "NPCSprite.h"
#include "GameEngine.h"

using namespace std;


string bPath = SDL_GetBasePath();
int windowHeight = 800;
int windowWidth =  500;

int main() {
    // Initialize SDL2
    // Create an application window with the following settings:
    GUI* gui = new GUI("PokeDodgeBall", windowHeight,windowWidth);
    SDL_Window* window = gui->getWin();
    SDL_Renderer* renderer = gui->getRen();
    GameEngine* engine = new GameEngine(gui,renderer,windowHeight, windowWidth);
    engine->gameLoop();
}

