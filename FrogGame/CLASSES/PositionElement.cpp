//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "PositionElement.hpp"

PositionElement::PositionElement(int x, int y){
    position.x=x;
    position.y=y;
    position.w=0;
    position.h=0;
}

void PositionElement::addElement(int spaceWithPreviousElement,GameObject * ob){
    position.w=position.w + spaceWithPreviousElement;

    ob->setPosition(position.w,position.y);
    
    position.w=position.w + ob->getPosition().w;
    

    if(position.h  < ob->getPosition().h){
        position.h =ob->getPosition().h;
    }

}

SDL_Rect PositionElement::getPosition(){
    return position;
}

