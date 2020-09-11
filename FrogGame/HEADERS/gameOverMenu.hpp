//
//  gameOverMenu.hpp
//  proyectoSDLModificable2
//
//  Created by Jose Manuel Moya Vargas on 07/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef gameOverMenu_hpp
#define gameOverMenu_hpp

#include "sdlFunctions.hpp"
#include "Menu.hpp"

class GameOverMenu : public Menu{
    
private:
  
    SDL_Rect gameOverPos;
    SDL_Texture * gameOverTexture;
    
public:
    GameOverMenu(SDL_Renderer* renderer,SDL_Rect windowRect);
    void render();
};

#endif /* gameOverMenu_hpp */
