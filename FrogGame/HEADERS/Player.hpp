//
//  Player.hpp
//  Created by Jose Manuel Moya Vargas on 06/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "sdlFunctions.hpp"
#include "GameObject.hpp"
class Player{
public:
    SDL_Rect playerPos;
    int movementFactor;
    SDL_Rect windowRect;
    
    int frameNumber;
    bool moveCompleted;
    Direction faceDirection;
    
public:
    Player(SDL_Rect windowRect);
    void movePlayer(Direction dir,int speed=26);
   
    SDL_Rect getPlayerPos();
    void ResetPlayerPos();
    void setPosition(SDL_Rect newPosition);
    
    
    void movePlayer2(Direction dir,int xDestiny,int yDestiny);
    bool isMoveCompleted();
    int getFrameNumber();
    Direction getFaceDirection();
    
};



#endif /* Player_hpp */
