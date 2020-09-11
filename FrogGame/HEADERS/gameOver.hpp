//
//  gameOver.hpp
//  Created by Jose Manuel Moya Vargas on 07/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

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
