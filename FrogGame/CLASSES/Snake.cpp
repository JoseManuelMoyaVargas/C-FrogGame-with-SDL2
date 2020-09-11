//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "Snake.hpp"
#include "AnimatedGameObject.hpp"


Snake::Snake(int x ,int y, int speed_,int wL):AnimatedGameObject({x,y,60,25},speed_,Right,wL,10,5){
    //We call superclass constructor.
}
   
bool Snake::CheckSnakeCollision(const SDL_Rect playerPos){
    SDL_Rect rect1=this->getPosition();
    rect1.x= rect1.x+48;//If we touchthe head we died.;
    rect1.w=rect1.w-48;
    return AnimatedGameObject::CheckCollision(rect1, playerPos);
}
