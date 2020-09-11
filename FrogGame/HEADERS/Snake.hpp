//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include "AnimatedGameObject.hpp"

class Snake : public AnimatedGameObject
{

public:
    Snake(int x ,int y,  int speed_,int wL);
    bool CheckSnakeCollision(const SDL_Rect playerPos);
};
#endif /* Snake_hpp */
