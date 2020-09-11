//
//  Turtle.hpp
//  Created by Jose Manuel Moya Vargas on 06/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Turtle_hpp
#define Turtle_hpp


#include "AnimatedGameObject.hpp"

class Turtle : public AnimatedGameObject
{

public:
    Turtle(int x ,int y, int speed_, Direction dir_,int wL,int framesPerSecond);
    bool CheckTurtleCollision(const SDL_Rect playerPos);
    void animate();
};

#endif /* Turtle_hpp */
