//
//  highScoresWindow.cpp
//  Created by Jose Manuel Moya Vargas on 09/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "highScoresWindow.hpp"


HighScoreMenu::HighScoreMenu(SDL_Renderer* renderer,SDL_Rect windowRect):Menu(renderer,windowRect,"scoreMenu"){
    highScoresPositions[0].x=windowRect.w/2-50;
    highScoresPositions[0].y=115;
    highScoresPositions[0].w=150;
    highScoresPositions[0].h=50;
    
    screenHighScores = SDL_CreateRGBSurface(0, 70, 70, 32,
                                  0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    
    charset = SDL_LoadBMP("resources/cs8x8.bmp");
    highScoreTitle=loadTexture(renderer,"resources/highScoresTitle.png");
    
    positionTitle.x=80;
    positionTitle.y=0;
    positionTitle.w=300;
    positionTitle.h=80;
    
    
    for( int i=1;i<10;i++){
        highScoresPositions[i]=highScoresPositions[0];
        highScoresPositions[i].y=highScoresPositions[i-1].y+40;
    }
    
    for(int i=0;i<10;i++){
        screenHighScoresArray[i]= SDL_CreateRGBSurface(0, 70, 70, 32,
                                         0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    }
    
    
}

void HighScoreMenu::render(){}

void HighScoreMenu::render2(){
        std::vector <double> highScores;
        highScores=readFileHighScores();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, highScoreTitle, NULL, &positionTitle);
        for(int i=0;i<10;i++){
            //sprintf(textHighScores, "%.1lf", 1.0);
            if(highScores.size()>i){
                sprintf(textHighScores, "%.1lf", highScores.at(i));
            }else{
                 sprintf(textHighScores, "%.1lf",0.0);
            }
            DrawString(screenHighScoresArray[i],0,0,textHighScores,charset);
            scrtexHighScoresArray[i]=SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                       SDL_TEXTUREACCESS_STREAMING,
                                       70, 70);
            SDL_UpdateTexture(scrtexHighScoresArray[i], NULL, screenHighScoresArray[i]->pixels, screenHighScoresArray[i]->pitch);
            SDL_RenderCopy(renderer, scrtexHighScoresArray[i], NULL, &highScoresPositions[i]);
            
            
        }
    SDL_RenderPresent(renderer);
        
}
    
    
  
    
    
    
    


