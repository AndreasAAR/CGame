#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <SDL_video.h>
#include <SDL_image.h>



using namespace std;


string bPath = SDL_GetBasePath();

string path = bPath + "/Enemy.png";

int main() {
    std::cout << "GameStart" << std::endl;
    cout<<bPath<<endl;
    int SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    SDL_Window* win = SDL_CreateWindow("Mitt",
                                       SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                       800,500,SDL_WINDOW_SHOWN);

    if (win == nullptr) {
        cerr <<"Fel" <<SDL_GetError() <<endl;
        SDL_Quit();
        exit(-1);
    }

    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    if (ren == nullptr) {
        cerr << "Fel:"  << SDL_GetError() << endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(-1);
    }

    SDL_Surface* bild = IMG_Load(path.c_str());
    SDL_Texture* tx = SDL_CreateTextureFromSurface(ren, bild);
    SDL_FreeSurface(bild);
    SDL_Rect protRect = {5,5,200,300};

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
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tx, NULL, &protRect);

        SDL_RenderPresent(ren);

    } // yttre while
    SDL_DestroyTexture(tx);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);

    SDL_Quit();
    return 0;

}

int drawSprite(){



}