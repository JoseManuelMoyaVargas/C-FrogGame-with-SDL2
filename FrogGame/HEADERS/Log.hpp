//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#ifndef Log_hpp
#define Log_hpp

#include "GameObject.hpp"
#include "LostFrog.hpp"

enum logSize{Long,Short};
class Log : public GameObject
{
private:
    LostFrog * lostFrog;
    
    
public:
    Log(int x, int y, int speed_, Direction dir_,logSize size,int wL);
    bool CheckLogCollision(const SDL_Rect playerPos);
    void addLostFrog( LostFrog * lf);
    void moveObject();
};

#endif /* Log_hpp */
