//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>

#include "GameObject.hpp"

enum typeEnemy{
    Truck,
    Car
};

enum typeCar{
    Car1,
    Car2,
    Car3,
    Car4,
    Car5
};

class Enemy : public GameObject
{
private:
    typeCar typeC;
public:
    Enemy(int x, int y, int speed_, Direction dir_,int wL,typeEnemy type, typeCar typeC);
    bool CheckEnemyCollision(SDL_Rect playerPos);
    typeCar getType();
};


#endif /* Enemy_hpp */
