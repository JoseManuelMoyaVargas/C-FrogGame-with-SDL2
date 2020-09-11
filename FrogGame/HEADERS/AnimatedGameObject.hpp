//  Copyright © Jose Manuel Moya Vargas. All rights reserved.

#ifndef AnimatedGameObject_hpp
#define AnimatedGameObject_hpp

#include <stdio.h>

#include "GameObject.hpp"

class AnimatedGameObject : public GameObject
{
protected:
    int frameNumber;
    int numberOfFrames;
    int numberOfChunks;
    int framesPerSecond;
    

public:
    AnimatedGameObject(SDL_Rect pos_, int speed_, Direction dir_,int wL,int numberOfFrames,int framesPerSecond);
    int getFrameNumber();
    void setFrameNumber(int frameNum);
    virtual void animate();
    
};




#endif /* AnimatedGameObject_hpp */
