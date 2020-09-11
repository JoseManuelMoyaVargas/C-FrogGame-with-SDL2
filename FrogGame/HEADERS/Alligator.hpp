//
//  Alligator.hpp
//  Created by Jose Manuel Moya Vargas on 04/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Alligator_hpp
#define Alligator_hpp


#include "AnimatedGameObject.hpp"

class Alligator : public AnimatedGameObject
{

public:
    Alligator(int x ,int y, int speed_, Direction dir_,int wL,int framesPerSecond);
    bool CheckAlligatorCollision(const SDL_Rect playerPos);
};


#endif /* Alligator_hpp */
