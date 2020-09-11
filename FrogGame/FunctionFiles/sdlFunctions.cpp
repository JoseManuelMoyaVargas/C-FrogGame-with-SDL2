
//  Copyright © Jose Manuel Moya Vargas. All rights reserved.

#include "sdlFunctions.hpp"

/**SDL*/
bool InitSDL(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
        std::cout << "Failed to initialize SDL : " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}

void quitSDL(){
    SDL_Quit();
}

/**IMG*/

bool InitIMG(){
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);
    
    if((initted&flags) != flags) {
        std::cout << "Failed to initialize IMG: " << IMG_GetError() << std::endl;
        return false;
    }
    return true;
}

void quitIMG(){
    IMG_Quit();
}


bool initAnything(){
    //Init anything.
    if(InitSDL()==false){
        return false;
    }
    if(InitIMG()==false){
        return false;
    }
    
    return true;//everything goes well
}

void quitAnything(){
    quitIMG();
    quitSDL();
}

/**HELPER FUNCTIONS*/

SDL_Window * CreateWindow(SDL_Rect windowRect){
    SDL_Window *  window = SDL_CreateWindow("FROGGER GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowRect.w, windowRect.h, SDL_WINDOW_SHOWN);

    if(window == nullptr){
        std::cout << "Failed to create window: " << SDL_GetError();
        return nullptr;
    }
    return window;
}

void DestroyWindow(SDL_Window * window){
    SDL_DestroyWindow(window);
    window=nullptr;
}

SDL_Renderer * CreateRenderer(SDL_Window *window){
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
   
    if(renderer == nullptr){
        std::cout << "Failed to create renderer : " << SDL_GetError();
        return nullptr;
        
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    return renderer;
}

void DestroyRenderer(SDL_Renderer* renderer){
    SDL_DestroyRenderer(renderer);
    renderer=nullptr;
}



// loads png texture give string of the png's path
SDL_Texture* loadTexture(SDL_Renderer* renderer,const std::string &str){
    // Load image as SDL_Surface
    SDL_Surface* surface = IMG_Load(str.c_str());
    
    // SDL Surface is just the raw pixels, so we convert it to a
    // hardware-optimized texture so we can render it
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // dont need the original trexture, release memory
    SDL_FreeSurface(surface);
    
    return texture;
}



void loadAnimatedTextures2(SDL_Renderer* renderer,SDL_Texture * arrayTextures[],int numberOfFrames,const std::string &path){
    std::string path2;
    for(int i=0;i<numberOfFrames;i++){
        path2 =path+ std::to_string(i+1) + ".png";
       
        arrayTextures[i]=loadTexture(renderer,path2);
    }
}
void DrawString(SDL_Surface *screen, int x, int y, const char *text,
SDL_Surface *charset) {
     int px, py, c;
     SDL_Rect s, d;
     s.w = 8;
     s.h = 8;
     //d.w = 8;
     //d.h = 8;
     d.w=12;
     //d.h=9;
     d.h=20;
     while(*text) {
         c = *text & 255;
         px = (c % 16) * 8;
         py = (c / 16) * 8;
         s.x = px;
         s.y = py;
         d.x = x;
         d.y = y;
         //SDL_BlitSurface(charset, &s, screen, &d);
         SDL_UpperBlitScaled(charset, &s, screen, &d);
         x += 12;//8;
         text++;
         };
 }


void savePointsToFile(double pointsUser){

    ofstream myfile;
    myfile.open ("highScoresUser.txt",std::ofstream::app);

    if (myfile.is_open())
    {
        //double value       = 11.23444556;
        myfile<<endl;
        myfile << pointsUser;
        myfile.close();
    }
}
std::vector<double> readFileHighScores(){
    std::vector<double> highScores;
    
    
    std::ifstream myFile;
    myFile.open("highScoresUser.txt",std::ifstream::in);

    double d;
    
    if (myFile.is_open())
    {
        while(myFile.eof()==false){
        myFile >> d;
        highScores.push_back(d);
        }
    }

    /*SORT*/
    sort(highScores.begin(), highScores.end(), greater<int>());
    
    cout << "LAST HIGH SCORES\n";
    for (auto x : highScores){
          cout << x << " ";
    }
    return highScores;
    myFile.close();
    
}
