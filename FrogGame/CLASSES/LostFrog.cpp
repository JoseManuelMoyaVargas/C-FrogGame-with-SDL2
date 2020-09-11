//  Copyright © Jose Manuel Moya Vargas. All rights reserved.

#include "LostFrog.hpp"

LostFrog::LostFrog(){
    position.w=18;
    position.h=18;
    position.x=-1;
    dir=Right;
    onLog=true;
}

void LostFrog::moveLostFrogInLog(SDL_Rect logPos, int logSpeed){
  
    if(onLog){
        position.y=logPos.y;
        if(position.x==-1){//If true, is the first time we call this function.
            position.x=logPos.x+logPos.w/2;//we put the lost frog in the middle of the log.
        }
        
        
        if((position.x+position.w)>=(logPos.x+logPos.w)){
            position.x=(logPos.x+logPos.w)-position.w;
            dir=Left;
        }
        
        if(position.x<=logPos.x){
            position.x=logPos.x;
            dir=Right;
        }
        
       if(dir==Right){
             position.x=position.x+logSpeed+1;
        }
       if(dir==Left){
            position.x=position.x+logSpeed-1;
        }
    }
}

bool LostFrog::CheckLostFrogCollision(const SDL_Rect playerPos){
    bool collision=GameObject::CheckCollision(position, playerPos);
    onLog=!collision;
    return collision;
}

void LostFrog::moveLostFrogInFrog(SDL_Rect playerPos){
    position.x=playerPos.x+2;
    position.y=playerPos.y+1;
}

void LostFrog::resetLostFrog(){
    position.x=-1;
    dir=Right;
    onLog=true;
}


SDL_Rect LostFrog::getPosition(){
    return position;
}
