//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "Log.hpp"
#include "GameObject.hpp"

Log::Log(int x ,int y, int speed_, Direction dir_,logSize size,int wL):GameObject({x,y,size==Long?100:80,25},speed_,dir_,wL){
    //We call superclass constructor.
    lostFrog=nullptr;
}
   
bool Log::CheckLogCollision(const SDL_Rect playerPos){
    return GameObject::CheckCollision(this->getPosition(), playerPos);
}

void Log::addLostFrog( LostFrog * lf){
    lostFrog=lf;
}
void Log::moveObject(){
    GameObject::moveObject();
    if(lostFrog!=nullptr){
        lostFrog->moveLostFrogInLog(getPosition(),getSpeed());
    }
}

