//
//  GameObject.hpp
//  Created by Jose Manuel Moya Vargas on 04/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp
#include "sdlFunctions.hpp"


enum Direction{
    Left,
    Right,
    Up,
    Down
};



class GameObject{
    
private:
    SDL_Rect position;
    int speed;
    Direction dir;
    

    int widthLimit;
    /**Constructor*/
    
public:
    GameObject(SDL_Rect pos_, int speed_, Direction dir_,int wL);
    virtual void moveObject();
    static bool CheckCollision(const SDL_Rect rect1, const SDL_Rect rect2);
    
    //void animate();
    
    SDL_Rect getPosition();
    int getSpeed();
    Direction getDirection();
    
    void setPosition(int x,int y);
    
    

    
};

#endif /* GameObject_hpp */

