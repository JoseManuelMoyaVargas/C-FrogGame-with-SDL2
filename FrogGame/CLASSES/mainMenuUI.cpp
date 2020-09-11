//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "mainMenuUI.hpp"


MainMenu::MainMenu(SDL_Renderer* renderer,SDL_Rect windowRect):Menu(renderer,windowRect,"mainMenu"){
    
     MainMenu::mainMenuTexture = loadTexture(renderer,"resources/mainMenu.png");
     mainMenuPos.x=0;
     mainMenuPos.y=0;
     mainMenuPos.w=windowRect.w;
     mainMenuPos.h=windowRect.h;
}

void MainMenu::render(){
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, mainMenuTexture, NULL, &mainMenuPos);
    
    SDL_RenderPresent(renderer);
}
