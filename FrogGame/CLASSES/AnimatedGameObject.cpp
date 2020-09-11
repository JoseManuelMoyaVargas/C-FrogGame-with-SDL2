//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "AnimatedGameObject.hpp"


AnimatedGameObject::AnimatedGameObject(SDL_Rect pos_, int speed_, Direction dir_,int wL,int numOfFrames,int fraPerSecond):GameObject(pos_,speed_,dir_,wL){
    
    frameNumber=0;
    numberOfChunks=1;
    numberOfFrames=numOfFrames;
    framesPerSecond=fraPerSecond;
}
   

int AnimatedGameObject::getFrameNumber(){
    return frameNumber;
}

void AnimatedGameObject::animate(){
    /**We put that one second has 60 chunks of 16 miliseconds  so--> */
    int numOfChunksToChangeFrame=60/framesPerSecond;
    
    if((numberOfChunks % numOfChunksToChangeFrame ) == 0){
        frameNumber++;
    }
    
    if(frameNumber==numberOfFrames){
        frameNumber=0;
    }
       
    numberOfChunks++;
       
};

void AnimatedGameObject::setFrameNumber(int frameNum){
    frameNumber=frameNum;
}
