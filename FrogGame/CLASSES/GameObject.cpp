//
//  GameObject.cpp
//  Created by Jose Manuel Moya Vargas on 04/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "GameObject.hpp"


    GameObject::GameObject(SDL_Rect pos_, int speed_, Direction dir_,int wL){
        position = pos_;
        speed = speed_;
        dir = dir_;
        widthLimit=wL;
        
    }

    void GameObject::moveObject(){
        if(dir == Direction::Right){
            position.x += speed;

            if(position.x >= widthLimit){
                position.x = 0;
            }
        }else{
            position.x -= speed;

            if((position.x + position.w) <= 0){
                position.x =widthLimit - position.w;
            }
        }
    }
    
    bool GameObject::CheckCollision(const SDL_Rect rect1, const SDL_Rect rect2){
        int left1 = rect1.x;
        int right1 = rect1.x + rect1.w;
        int top1 = rect1.y;
        int bottom1 = rect1.y + rect1.h;

        int left2 = rect2.x;
        int right2 = rect2.x + rect2.w;
        int top2 = rect2.y;
        int bottom2 = rect2.y + rect2.h;

        if(left1 > right2) return false; 
        if(right1 < left2) return false;
        if(top1 > bottom2) return false;
        if(bottom1 < top2) return false;

        return true;
    }
 
//void GameObject::animate() {}

SDL_Rect GameObject::getPosition(){
    
    return position;
}
int GameObject::getSpeed(){
    return speed;
}
Direction GameObject::getDirection(){
    return dir;
}

void GameObject::setPosition(int x,int y){
    position.x=x;
    position.y=y;
}


    
     

