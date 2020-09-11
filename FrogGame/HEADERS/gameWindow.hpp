//
//  gameWindow.hpp
//  Created by Jose Manuel Moya Vargas on 05/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#ifndef gameWindow_hpp
#define gameWindow_hpp

#include "sdlFunctions.hpp"
#include "Menu.hpp"
#include "Log.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Alligator.hpp"
#include "Turtle.hpp"
#include "Snake.hpp"
#include "GameObject.hpp"

class GameWindow : public Menu{
    
private:
    
/**IU elements of the window*/
    SDL_Rect backgroundPos;
    SDL_Texture * backgroundTexture;

    
    SDL_Rect livePos={windowRect.w/2-70,7,20,17};
    SDL_Texture * liveTexture;


   
    
    //PAUSE
    SDL_Rect pausePos;
    SDL_Texture* pauseTexture;
    
    //QUIT
    SDL_Rect quitGamePos;
    SDL_Texture * quitGameTexture;
    

    //SDL_Rect for the water
    SDL_Rect waterRect={0,100,windowRect.w,170};
    
    /**Frogs of win*/
    
    SDL_Texture * winFrogTexture;
    SDL_Rect winFrogPositions[5]={{15,55,35,35},{15+96,55,35,35},{15+96*2,55,35,35},{15+96*3,55,35,35},{15+96*4,55,35,35}};
    int winPositions[5];

    /*TIMER**/
    SDL_Surface *screen, *charset;
    char text[128];
    SDL_Texture *scrtex;

    SDL_Rect timerPos;
    
    /**POINTS*/
     SDL_Rect pointsPos;
    SDL_Surface *screen2;
    char text2[128];
    SDL_Texture *scrtex2;
    
    /**POINTS UP*/
    SDL_Rect pointsUPPos;
    SDL_Surface *screen3;
    SDL_Texture *scrtex3;
    int lastWinPos;
    
    
    /**PLAYER TEXTUREs*/
    SDL_Texture * playerTexturesPruebaUP[2];
    SDL_Texture * playerTexturesPruebaRIGHT[2];
    SDL_Texture * playerTexturesPruebaDOWN[2];
    SDL_Texture * playerTexturesPruebaLEFT[2];
    
    
/**Objects of the game.*/
    
    SDL_Texture* playerTexture;
    Player * player;
    
    
    SDL_Texture * carsTextures[5];
    std::vector<Enemy> * enemies;
    
    SDL_Texture* logTexture;
    std::vector<Log> * logs;
  
    SDL_Texture * snakesTextures[10];
    Snake * snake;
    
    SDL_Texture * alligatorTextures[2];
    Alligator * alligator;
    
    SDL_Texture * turtlesTextures[5];
    std::vector<Turtle> * turtles;
    
    /**LOST FROG*/
    SDL_Texture * lostFrogTexture;
    LostFrog * lostFrog;
    
    /**Alligator of the wins*/
    SDL_Texture * alligatorWin;
    int numOf16milisecondsChunks=0;
    int numOf16milisecondsWithAlligator=0;
    int alligatorWinPos=-1;
    /**Bee*/
    SDL_Texture * beeTexture;
    int numOf16milisecondsChunksBee=0;
    int numOf16milisecondsWithBee=0;
    int beePos=-1;
    
    
    /**Variables*/
    int livesPlayer;
    
    
    /**STAGES*/
    
    std::vector<Log *> ptrToLogs;
    std::vector<Enemy *> ptrToEnemies;
    std::vector<Turtle *> ptrToTurtles;

    std::vector<Alligator *> ptrToAlligators;
    
    
    
    
public:
    
    GameWindow(SDL_Renderer* renderer,SDL_Rect windowRect,Player * player,std::vector<Log *> ptrToLogs,std::vector<Enemy *> ptrToEnemies, std::vector<Turtle *> ptrToTurtles,std::vector<Alligator *> ptrToAlligators,Snake * ptrSnake,LostFrog * ptrLostFrog);
    
    
    void render();
    void showPauseMenu();
    void showQuitMenu();
   
    
    
    void loadTextures();
    void loadTurtleTextures();
    void loadSnakesTextures();
    void loadAlligatorTextures();
    void loadCarsTextures();

    
    void renderCars2();
    int renderAlligatorWin();
    
    int renderBee();
    
    int getAlligatorWinPos();
    int getBeePos();
    SDL_Rect getWaterRect();
    
    int getLivesPlayer();
    
    

    void setPosWindowElements();
    void ResetPlayerPos();
    void resetGame();
    int checkWinRectCollision(const SDL_Rect playerPos);
    bool checkWin(const SDL_Rect playerPos,double * pointsUser,bool withFrogLost);
    bool checkEatBee(const SDL_Rect playerPos);

    
    void gameOver();
    
    /**TIMER*/
    void drawTime(double time);
    /*POINTS*/
    void drawPoints(double points);
    
    void drawPointsUpFrog(double points,SDL_Rect lastwinRectWin);
    
    /**POINTS UP*/
    SDL_Rect getLastWinRect();
    void quitPointsUpFrog();
    
    /**SET STATE*/
    
    void setLivesPlayer(int lives);
    
    int getWinsPlayer();
    

};


#endif /* gameWindow_hpp */
