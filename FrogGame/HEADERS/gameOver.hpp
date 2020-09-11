//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#ifndef gameOver_hpp
#define gameOver_hpp

#include "sdlFunctions.hpp"
#include "Menu.hpp"

class GameOver : public Menu{
    
private:
  
    SDL_Rect gameOverPos;
    SDL_Texture * gameOverTex;
    
public:
    GameOver(SDL_Renderer* renderer,SDL_Rect windowRect);
    void render();
};


#endif /* gameOver_hpp */
