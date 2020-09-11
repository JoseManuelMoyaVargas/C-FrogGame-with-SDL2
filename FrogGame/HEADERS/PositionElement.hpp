//
//  PositionElement.hpp
//  Created by Jose Manuel Moya Vargas on 05/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef PositionElement_hpp
#define PositionElement_hpp

#include "sdlFunctions.hpp"
#include "GameObject.hpp"

class PositionElement {
    
private:
    SDL_Rect position;
    
public:
    PositionElement(int x, int y);
    void addElement(int spaceWithPreviousElement,GameObject * ob);
    SDL_Rect getPosition();
    
};


#endif /* PositionElement_hpp */
