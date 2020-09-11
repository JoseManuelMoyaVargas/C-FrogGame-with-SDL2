//
//  Menu.hpp
//  Created by Jose Manuel Moya Vargas on 05/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "sdlFunctions.hpp"

class Menu{
    
protected:
    
    SDL_Renderer* renderer;
    SDL_Rect windowRect;
    std::string name;
    
 
    
public:
    Menu(SDL_Renderer* renderer,SDL_Rect windowRect,const std::string name);
    virtual void render();
    std::string getName();
   
};


#endif /* Menu_hpp */
