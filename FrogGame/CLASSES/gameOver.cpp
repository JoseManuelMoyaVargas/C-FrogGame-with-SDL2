//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "gameOver.hpp"

GameOver::GameOver(SDL_Renderer* renderer,SDL_Rect windowRect):Menu(renderer,windowRect,"gameOverMenu"){
    
     GameOver::gameOverTex = loadTexture(renderer,"resources/gameOver.png");
     gameOverPos.x=0;
     gameOverPos.y=0;
     gameOverPos.w=windowRect.w;
     gameOverPos.h=windowRect.h;
}

void GameOver::render(){
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, gameOverTex, NULL, &gameOverPos);
    
    SDL_RenderPresent(renderer);
}
