//
//  Turtle.cpp
//  Created by Jose Manuel Moya Vargas on 06/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Turtle.hpp"

#include "AnimatedGameObject.hpp"


Turtle::Turtle(int x ,int y, int speed_, Direction dir_,int wL,int framesPerSecond):AnimatedGameObject({x,y,25,27},speed_,dir_,wL,5,framesPerSecond){
    //We call superclass constructor.
}
   
bool Turtle::CheckTurtleCollision(const SDL_Rect playerPos){
    
    if((this->getFrameNumber()==3)||(this->getFrameNumber()==4)){//We check if the turtles are diving.
        return false;
    }
    return AnimatedGameObject::CheckCollision(this->getPosition(), playerPos);
}

void Turtle::animate(){
    //We want that the frames 0, 1 and 2 stay longer
    int numOfChunksToChangeFrame=60/this->framesPerSecond;
    
    if(( this->numberOfChunks%151!=0)&&( this->frameNumber!=3)&&( this->frameNumber!=4)){
        
        if((numberOfChunks % numOfChunksToChangeFrame ) == 0){
            this->frameNumber++;
        }
        if( this->frameNumber==3){
            this->frameNumber=0;
        }
    }else{
        
        
        if( this->frameNumber!=4){
            this->frameNumber=3;
        }
        
        if((numberOfChunks % numOfChunksToChangeFrame ) == 0){
            this->frameNumber++;
        }
        
        if(frameNumber==numberOfFrames){
             this->frameNumber=0;
        }
    }
     this->numberOfChunks++;
}


