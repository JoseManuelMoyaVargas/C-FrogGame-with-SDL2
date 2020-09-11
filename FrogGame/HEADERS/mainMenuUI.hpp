//
//  mainMenuUI.hpp
//  Created by Jose Manuel Moya Vargas on 05/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef mainMenuUI_hpp
#define mainMenuUI_hpp

#include <stdio.h>
#include "sdlFunctions.hpp"
#include "Menu.hpp"

class MainMenu : public Menu{
    
private:
  
    SDL_Rect mainMenuPos;
    SDL_Texture * mainMenuTexture;
    
public:
    MainMenu(SDL_Renderer* renderer,SDL_Rect windowRect);
    void render();
};



#endif /* mainMenuUI_hpp */
