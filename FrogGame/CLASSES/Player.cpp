//
//  Player.cpp
//  Created by Jose Manuel Moya Vargas on 06/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "Player.hpp"

    Player::Player(SDL_Rect w){
        windowRect=w;
        movementFactor = 45;
        playerPos.w = 20;
        playerPos.h = 20;
    
        frameNumber=0;
        moveCompleted=true;
        faceDirection=Up;
        
        
        
        ResetPlayerPos();
    }

    void Player::movePlayer(Direction dir,int speed){
        switch (dir) {
            case Right:
                playerPos.x += speed;
                if(playerPos.x >windowRect.w){
                    playerPos.x=windowRect.w-playerPos.w;
                }
                break;
            case Left:
                playerPos.x -= speed;
                if(playerPos.x <0){
                    playerPos.x=0;
                }
                break;
            case Up:
                playerPos.y -= speed;
                break;
            case Down:
                playerPos.y += speed;
                if((playerPos.y+playerPos.h) >windowRect.h){
                    playerPos.y=windowRect.h-playerPos.h;
                }
                break;
        }
    }


SDL_Rect  Player::getPlayerPos(){
   
    return playerPos;
}
void Player::ResetPlayerPos(){
    playerPos.x = (windowRect.w /2) - (playerPos.w /2);
    playerPos.y = windowRect.h -25;
    frameNumber=0;
    moveCompleted=true;
    
}

void Player::setPosition(SDL_Rect newPosition){
    playerPos.x=newPosition.x;
    playerPos.y=newPosition.y;
}

void Player::movePlayer2(Direction dir,int xDestiny,int yDestiny){
    
    
    switch (dir) {
        case Right:
            faceDirection=Right;
            if(playerPos.x<xDestiny-1){
                playerPos.x += 14;
                frameNumber=1;
                moveCompleted=false;
            }else {
                playerPos.x += 1;
                frameNumber=0;
                moveCompleted=true;
            }
            
            if(playerPos.x >windowRect.w){
                playerPos.x=windowRect.w-playerPos.w;
            }
            
            break;
        case Left:
            faceDirection=Left;
            if(playerPos.x>xDestiny+1){
                playerPos.x -= 14;
                frameNumber=1;
                moveCompleted=false;
            }else {
                playerPos.x -= 1;
                frameNumber=0;
                moveCompleted=true;
            }
            
            if(playerPos.x <0){
                playerPos.x=0;
            }
            break;
        case Up:
            faceDirection=Up;
            if(playerPos.y>yDestiny+1){
                playerPos.y -= 14;
                frameNumber=1;
                moveCompleted=false;
            }else{
                playerPos.y -= 1;
                frameNumber=0;
                moveCompleted=true;
            }
           
            break;
        case Down:
            faceDirection=Down;
            if(playerPos.y<yDestiny-1){
                playerPos.y += 14;
                frameNumber=1;
                moveCompleted=false;
            }else{
                playerPos.y += 1;
                frameNumber=0;
                moveCompleted=true;
            }
            if((playerPos.y+playerPos.h) >windowRect.h){
                playerPos.y=windowRect.h-playerPos.h;
            }
            
            break;
    }

    
}

bool Player::isMoveCompleted(){
    return moveCompleted;
}

int Player::getFrameNumber(){
    return frameNumber;
}

Direction Player::getFaceDirection(){
    return faceDirection;
}
