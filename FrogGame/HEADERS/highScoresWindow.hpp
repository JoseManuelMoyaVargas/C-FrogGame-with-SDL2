//  Copyright © Jose Manuel Moya Vargas. All rights reserved.

#ifndef highScoresWindow_hpp
#define highScoresWindow_hpp

#include <stdio.h>

#include "sdlFunctions.hpp"
#include "Menu.hpp"

class HighScoreMenu : public Menu{
    
private:

    SDL_Rect highScoreMenuPos;
    SDL_Surface *screenHighScores, *charset;
    char textHighScores[128];
    SDL_Texture *scrtexHighScores;
    
    
    SDL_Texture * highScoreTitle;
    SDL_Rect positionTitle;
    
    SDL_Rect highScoresPositions[10];

    /* */
    SDL_Surface *screenHighScoresArray[10];
    SDL_Texture *scrtexHighScoresArray[10];
    
    
public:
    HighScoreMenu(SDL_Renderer* renderer,SDL_Rect windowRect);
    void render();
    void render2();
};


#endif /* highScoresWindow_hpp */
