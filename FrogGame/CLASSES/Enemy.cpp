//
//  Enemy.cpp
//  Created by Jose Manuel Moya Vargas on 04/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Enemy.hpp"
#include "GameObject.hpp"


Enemy::Enemy(int x, int y, int speed_, Direction dir_,int wL,typeEnemy type, typeCar tC):GameObject({x,y,type==Truck?60:30,25},speed_,dir_,wL){
    //We call superclass constructor.
    typeC=tC;
}
   
bool Enemy::CheckEnemyCollision(SDL_Rect playerPos){
    return GameObject::CheckCollision(this->getPosition(), playerPos);
}

typeCar Enemy::getType(){
    return typeC;
}
