//
//  Alligator.cpp
//  Created by Jose Manuel Moya Vargas on 04/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Alligator.hpp"
#include "AnimatedGameObject.hpp"


Alligator::Alligator(int x ,int y, int speed_, Direction dir_,int wL,int framesPerSecond):AnimatedGameObject({x,y,120,25},speed_,dir_,wL,2,framesPerSecond){
    //We call superclass constructor.
}
   
bool Alligator::CheckAlligatorCollision(const SDL_Rect playerPos){
    SDL_Rect rect1=this->getPosition();
    rect1.w=rect1.w-40;//If we fall in the head we died.;
    return AnimatedGameObject::CheckCollision(rect1, playerPos);
}

