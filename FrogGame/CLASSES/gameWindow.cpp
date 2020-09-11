//
//  gameWindow.cpp
//  Created by Jose Manuel Moya Vargas on 05/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

#include "gameWindow.hpp"
#include "Menu.hpp"

void GameWindow::loadTextures(){
    /**WE  LOAD TEXTURES OF WINDOW ELEMENTS*/
    backgroundTexture=loadTexture(renderer,"resources/background.png");
    pauseTexture =loadTexture(renderer,"resources/pause.png");
    quitGameTexture = loadTexture(renderer,"resources/quitgame.png");
    winFrogTexture=loadTexture(renderer,"resources/winFrog.png");
    alligatorWin=loadTexture(renderer,"resources/alligatorWin.png");
    beeTexture=loadTexture(renderer,"resources/bee.png");
    liveTexture=loadTexture(renderer,"resources/lives.png");
    
    /**Objects of the game.*/
    playerTexture = loadTexture(renderer,"resources/frog.png");
    lostFrogTexture = loadTexture(renderer,"resources/lostFrog.png");
    logTexture=loadTexture(renderer,"resources/logLong.png");
    loadSnakesTextures();
    loadTurtleTextures();
    loadAlligatorTextures();
    loadCarsTextures();
    
    /**P*/
    playerTexturesPruebaUP[0]= loadTexture(renderer,"resources/frogs/frog1up.png");
    playerTexturesPruebaUP[1]= loadTexture(renderer,"resources/frogs/frog2up.png");
    
    

    playerTexturesPruebaDOWN[0]= loadTexture(renderer,"resources/frogs/frog1down.png");
    playerTexturesPruebaDOWN[1]= loadTexture(renderer,"resources/frogs/frog2down.png");
    
    playerTexturesPruebaLEFT[0]= loadTexture(renderer,"resources/frogs/frog1left.png");
    playerTexturesPruebaLEFT[1]= loadTexture(renderer,"resources/frogs/frog2left.png");
    
    playerTexturesPruebaRIGHT[0]= loadTexture(renderer,"resources/frogs/frog1right.png");
    playerTexturesPruebaRIGHT[1]= loadTexture(renderer,"resources/frogs/frog2right.png");
    /**TIMER */
    screen = SDL_CreateRGBSurface(0, 70, 70, 32,
                                  0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    
    
    charset = SDL_LoadBMP("resources/cs8x8.bmp");
    
    /**POINTS*/
    screen2 = SDL_CreateRGBSurface(0, 70, 70, 32,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    
    
    screen3=SDL_CreateRGBSurface(0, 70, 70, 32,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    DrawString(screen3,20,20,"0.0", charset);
    scrtex3 = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_STREAMING,
                               70, 70);
    
    SDL_UpdateTexture(scrtex3, NULL, screen3->pixels, screen3->pitch);
    
    SDL_SetTextureColorMod(scrtex3,0,255,0);
}

void GameWindow::loadSnakesTextures(){
    loadAnimatedTextures2(renderer,snakesTextures,10,"resources/snakesIMG/snake");
}
void GameWindow::loadTurtleTextures(){
    loadAnimatedTextures2(renderer,turtlesTextures,5,"resources/turtlesIMG/turtle");
}
void GameWindow::loadAlligatorTextures(){
    loadAnimatedTextures2(renderer,alligatorTextures,2,"resources/alligatorIMG/alligator");
}

void GameWindow::loadCarsTextures(){
    loadAnimatedTextures2(renderer,carsTextures,5,"resources/carsIMG/car");
}



void GameWindow::renderCars2(){
    int texture;
    SDL_Rect carPos;
    for(auto &c : ptrToEnemies){
        carPos =c->getPosition();
        switch (c->getType()) {
            case Car1:
                texture=0;
                break;
            case Car2:
                texture=1;
            break;
            case Car3:
                texture=2;
            break;
            case Car4:
                texture=3;
            break;
            case Car5:
                texture=4;
            break;
        
        }
        
        SDL_RenderCopy(renderer, carsTextures[texture],NULL, &carPos);
    }
    
}

int GameWindow::renderAlligatorWin(){
    numOf16milisecondsChunks++;
    std::vector<int> noWinPositions;
    
    for(int i=0;i<5;i++){
        if(winPositions[i]==0){
            noWinPositions.push_back(i);
        }
    }
    int r;
    if(noWinPositions.size()!=0){
        r=rand()%noWinPositions.size();
        if(numOf16milisecondsChunks%120==0){//We want to render the alligatorgame every 4 second-->1 second has 60 chunks of 16 miliseconds
            return noWinPositions.at(r);
        }
    }
    return -1;
}

int GameWindow::renderBee(){
    numOf16milisecondsChunksBee++;
    std::vector<int> noWinPositions;
    
    for(int i=0;i<5;i++){
        if(winPositions[i]==0){
            noWinPositions.push_back(i);
        }
    }
    int r;
    if(noWinPositions.size()!=0){
        r=rand()%noWinPositions.size();
        if(numOf16milisecondsChunksBee%160==0){//We want to render the alligatorgame every 4 second-->1 second has 60 chunks of 16 miliseconds
            return noWinPositions.at(r);
        }
    }
    return -1;
}


void GameWindow::setPosWindowElements(){
    backgroundPos.x = 0;
    backgroundPos.y = 30;
    backgroundPos.w = windowRect.w;
    backgroundPos.h = windowRect.h-45;
  

    /* Pause*/
    pausePos.x=0;
    pausePos.y=0;
    pausePos.w=windowRect.w;
    pausePos.h=windowRect.h;
    
    /**Quit*/
    quitGamePos.x=0;
    quitGamePos.y=0;
    quitGamePos.w=windowRect.w;
    quitGamePos.h=windowRect.h;
    
    /**TIMER*/
    timerPos.x=windowRect.w-50;
    timerPos.y=windowRect.h-50;
    timerPos.w=55;
    timerPos.h=50;
    
    /**POINTS*/
    pointsPos.x=0;
    pointsPos.y=windowRect.h-50;
    pointsPos.w=70;
    pointsPos.h=50;
   
    /**POINTS UP*/
    pointsUPPos.w=50;
    pointsUPPos.h=50;
    pointsUPPos.x=-50;
    pointsUPPos.y=-50;
    

}

void GameWindow::ResetPlayerPos(){
    player->ResetPlayerPos();
}



void GameWindow::render(){
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, backgroundTexture, NULL, &backgroundPos);
    
    /**We render the lives*/
    SDL_Rect pos;
    pos=livePos;
    for(int i=0;i<livesPlayer;i++){
         SDL_RenderCopy(renderer, liveTexture ,NULL, &pos);
        pos.x=pos.x+pos.w+3;;
    }
 
    /**Render bee */
    
    if((beePos==-1)||(beePos==alligatorWinPos)){
        beePos=renderBee();
    }else{
        //We render the alligator
        SDL_RenderCopy(renderer, beeTexture, NULL, &winFrogPositions[beePos]);
        numOf16milisecondsWithBee++;
        if(numOf16milisecondsWithBee%60==0){
            beePos=-1;
        }

    }
    
    if((alligatorWinPos==-1)||(beePos==alligatorWinPos)){
        alligatorWinPos=renderAlligatorWin();
    }else{
        //We render the alligator
        SDL_RenderCopy(renderer, alligatorWin, NULL, &winFrogPositions[alligatorWinPos]);
        numOf16milisecondsWithAlligator++;
        if(numOf16milisecondsWithAlligator%60==0){
            alligatorWinPos=-1;
        }

    }
    

    
    /**Logs*/
    SDL_Rect logPos;
    
    for(auto &p : ptrToLogs){
        logPos =p->getPosition();
        SDL_RenderCopy(renderer, logTexture, NULL, &logPos);
    }
    
    /**Turtles*/
   
     SDL_Rect turtlePos;
    
    for(auto &t : ptrToTurtles){
        turtlePos=t->getPosition();
        SDL_RenderCopy(renderer, logTexture, NULL, &logPos);
        t->animate();
        SDL_RenderCopy(renderer, turtlesTextures[t->getFrameNumber()], NULL, &turtlePos);
    }
   
    
    /**Enemies*/
    renderCars2();
  
    
    SDL_Rect alligatorPos;
    for(auto &a : ptrToAlligators){
        a->animate();
        alligatorPos =a->getPosition();
        SDL_RenderCopy(renderer,alligatorTextures[a->getFrameNumber()], NULL, &alligatorPos);
    }
    
    
    /**Snake*/
    
    
    SDL_Rect snakePos=snake->getPosition();
    snake->animate();
    SDL_RenderCopy(renderer,snakesTextures[snake->getFrameNumber()], NULL, &snakePos);
    
    
    
   
    
    /**PLAYER PRUEBA*/
    SDL_Rect playerPos=player->getPlayerPos();
    
    if(player->getFaceDirection()==Up){
        
        SDL_RenderCopy(renderer, playerTexturesPruebaUP[player->getFrameNumber()], NULL, &playerPos);
        
    }else if (player->getFaceDirection()==Right){
        
        SDL_RenderCopy(renderer, playerTexturesPruebaRIGHT[player->getFrameNumber()], NULL, &playerPos);
        
    }else if(player->getFaceDirection()==Down){
        
        SDL_RenderCopy(renderer, playerTexturesPruebaDOWN[player->getFrameNumber()], NULL, &playerPos);
        
    }else if(player->getFaceDirection()==Left){
        
        SDL_RenderCopy(renderer, playerTexturesPruebaLEFT[player->getFrameNumber()], NULL, &playerPos);
        
    }
    
    for( int i=0;i<5;i++){
        if(winPositions[i]==1){
             SDL_RenderCopy(renderer, winFrogTexture, NULL, &winFrogPositions[i]);
        }
    }
    
    
    /**Lost frog*/
    
    SDL_Rect lostFrogPos=lostFrog->getPosition();
    SDL_RenderCopy(renderer, lostFrogTexture, NULL, &lostFrogPos);
    
    
    /**TIMER*/
    SDL_RenderCopy(renderer, scrtex, NULL, &timerPos);
    //POINTS
    SDL_RenderCopy(renderer, scrtex2, NULL, &pointsPos);
    
    
    SDL_RenderCopy(renderer, scrtex3, NULL, &pointsUPPos);
    //POINTS UP FROG

    
    
    SDL_RenderPresent(renderer);
}


void GameWindow::showPauseMenu(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, pauseTexture, NULL, &pausePos);
    SDL_RenderPresent(renderer);
}
void GameWindow::showQuitMenu(){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, quitGameTexture, NULL, &quitGamePos);
    SDL_RenderPresent(renderer);
}


int GameWindow::checkWinRectCollision(const SDL_Rect playerPos){
    for(int i=0;i<5;i++){
        if(GameObject::CheckCollision(winFrogPositions[i], playerPos)){
            return i;
        }
    }
           return -1;
}

bool GameWindow::checkWin(const SDL_Rect playerPos,double * pointsUser,bool withFrogLost){
    int num =checkWinRectCollision(playerPos);
    if(num!=-1){
        if(winPositions[num]==0){
            //We check if it is an alligator
            if(getAlligatorWinPos()==num){
                gameOver();
                return false;
            }else {
                if(checkEatBee(playerPos)){
                *pointsUser=*pointsUser+200;
                }
                
                if(withFrogLost==true){
                    *pointsUser=*pointsUser+200;
                }
                lastWinPos=num;
                
                beePos=-1;
                winPositions[num]=1;
                ResetPlayerPos();
                return true;
            }
            
        }else if(winPositions[num]==1){
            gameOver();
            return false;
            //We have fall in a position that we fell before.
        }
    }else{
        if(playerPos.y<=(75)){
            //We have fall in a position that has no posibility to win
            gameOver();
            return false;
        }
    }
    return false;
}
bool GameWindow::checkEatBee(const SDL_Rect playerPos){
    int num =checkWinRectCollision(playerPos);
    if(num!=-1){
        //We check if it is an alligator
        if(getBeePos()==num){
            return true;
        }
    }
    return false;
}


void GameWindow::gameOver(){
    ResetPlayerPos();
    livesPlayer--;
    numOf16milisecondsChunks=0;
    alligatorWinPos=-1;
    
}

void GameWindow::resetGame(){
    for(int i=0;i<5;i++){
        winPositions[i]=0;
    }
    ResetPlayerPos();
    livesPlayer=5;
    
}


int GameWindow::getAlligatorWinPos(){
    return  alligatorWinPos;
}

int GameWindow::getBeePos(){
    return  beePos;
}


SDL_Rect GameWindow::getWaterRect(){
    return waterRect;
}

void GameWindow::drawTime(double time){
    sprintf(text, "%.1lf s ", time);
    
    //draw(renderer,screen,charset,text,scrtex);
    DrawString(screen,5,20,text, charset);
    scrtex = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                                  SDL_TEXTUREACCESS_STREAMING,
                                  70, 70);
    SDL_UpdateTexture(scrtex, NULL, screen->pixels, screen->pitch);
    if(time<=10){
        SDL_SetTextureColorMod(scrtex,255,0,0); //Con esto ponemos el color de las letras a rojo.
       if(time<=0){
           SDL_SetTextureColorMod(scrtex,0,0,0);
           gameOver();
           
       }
    }
}

void GameWindow::drawPoints(double pointsUser){
    sprintf(text2, "%.1lf", pointsUser);
    
    DrawString(screen2,5,22,text2, charset);

    scrtex2 = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_STREAMING,
                               70, 70);
    SDL_UpdateTexture(scrtex2, NULL, screen2->pixels, screen2->pitch);
    
}

void GameWindow::drawPointsUpFrog(double pointsUser,SDL_Rect lastwinRectWin){
    pointsUPPos.x=lastwinRectWin.x-5;
    pointsUPPos.y=lastwinRectWin.y-pointsUPPos.h;
    
    sprintf(text2, "%.1lf", pointsUser);
    
    DrawString(screen3,0,20,text2, charset);
    scrtex3 = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
                               SDL_TEXTUREACCESS_STREAMING,
                               70, 70);
    
    SDL_UpdateTexture(scrtex3, NULL, screen3->pixels, screen3->pitch);
    
    SDL_SetTextureColorMod(scrtex3,0,255,0);
    //POINTS UP FROG
}

int GameWindow::getLivesPlayer(){
    return livesPlayer;
}

SDL_Rect GameWindow::getLastWinRect(){
    return winFrogPositions[lastWinPos];
    
}

void GameWindow::quitPointsUpFrog(){
    pointsUPPos.x=-50;
    pointsUPPos.y=-50;
    
}


void GameWindow::setLivesPlayer(int lives){
    livesPlayer=lives;
}


/***/

GameWindow::GameWindow(SDL_Renderer* renderer,SDL_Rect windowRect,Player * p,std::vector<Log *> ptrToL,std::vector<Enemy *> ptrToE, std::vector<Turtle *> ptrToT,std::vector<Alligator *> ptrToA,Snake * ptrSnake,LostFrog * ptrLostFrog):Menu(renderer,windowRect,"gameWindow"){
    
    GameWindow::loadTextures();
    GameWindow::setPosWindowElements();
    
    player=p;
    ptrToLogs=ptrToL;
    ptrToEnemies=ptrToE;
    ptrToTurtles=ptrToT;
    ptrToAlligators=ptrToA;
    snake=ptrSnake;
    lostFrog=ptrLostFrog;
    
    livesPlayer=5;
    GameWindow::resetGame();
    
}


int GameWindow::getWinsPlayer(){
    int num=0;
    for(int i=0;i<5;i++){
        if(winPositions[i]==1){
            num++;
        }
    }
    
    return num;
    
}
