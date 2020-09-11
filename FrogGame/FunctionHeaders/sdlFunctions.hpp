//
//  sdlFunctions.hpp
//  proyectoSDLModificable2
//
//  Created by Jose Manuel Moya Vargas on 03/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef sdlFunctions_hpp
#define sdlFunctions_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
/**SDL initialization and destruction*/

/**SDL*/
bool InitSDL();
void quitSDL();
/**IMG*/
bool InitIMG();
void quitIMG();

bool initAnything();

void quitAnything();

/*HELPER FUNCTIONS*/

SDL_Window *CreateWindow(SDL_Rect windowRect);
SDL_Renderer * CreateRenderer(SDL_Window * window);
void DestroyWindow(SDL_Window * window);
void DestroyRenderer(SDL_Renderer* renderer);
SDL_Texture* loadTexture(SDL_Renderer* renderer,const std::string &str);



void loadAnimatedTextures2(SDL_Renderer* renderer,SDL_Texture * arrayTextures[],int numberOfFrames,const std::string &path);


/**DRAW*/
void DrawString(SDL_Surface *screen, int x, int y, const char *text, SDL_Surface *charset);


//SAVE points to file

void savePointsToFile(double pointUser);

std::vector<double> readFileHighScores();


#endif /* sdlFunctions_hpp */
