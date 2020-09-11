//
//  LostFrog.hpp
//  Created by Jose Manuel Moya Vargas on 08/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef LostFrog_hpp
#define LostFrog_hpp

#include "sdlFunctions.hpp"
#include "GameObject.hpp"


class LostFrog{
private:
    SDL_Rect position;
    Direction dir;
    bool onLog;
public:
    LostFrog();
    void moveLostFrogInLog(SDL_Rect logPos, int logSpeed);
    bool CheckLostFrogCollision(const SDL_Rect playerPos);
    void moveLostFrogInFrog(SDL_Rect playerPos);
    void resetLostFrog();
    SDL_Rect getPosition();
};

#endif /* LostFrog_hpp */
