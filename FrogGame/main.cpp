#include "sdlFunctions.hpp"
#include "GameObject.hpp"
#include "mainMenuUI.hpp"
#include "gameWindow.hpp"
#include "gameOver.hpp"
#include "Log.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "PositionElement.hpp"
#include "Alligator.hpp"
#include "Snake.hpp"

#include "highScoresWindow.hpp"



SDL_Window * window;
SDL_Renderer* renderer;

SDL_Rect windowRect = {1000, 200, 450,545};// 530};
int rows[11]={100,135,170,205,245,278,320,355,390,425,460};

/**Variables to check if we pass the  river bank*/
int grassPos=310;
bool reachRiverbank=false;


Menu * activeMenu;

Player * ptrPlayer;

Snake * snake;

Log * currentLog;
Turtle * currentTurtle;

/**LOST FROG*/
LostFrog * lostFrog;

/*SAVE STATE*/
GameWindow * gameWindow;
HighScoreMenu * ptrHighScoreMenu;
MainMenu * ptrMainMenu;
GameOver * ptrGameOverMenu;


/** VARIABLES FOR THE TIMER*/

int t1, t2;
double timeLive=40.0;
double delta, worldTime, miliPaused=0.0, timePaused=0.0,sumTimePaused=0.0, timeToShow=0.0;
 
/**Quit points up of the frogger*/
double miliTimePointsUpShown=0.0;
bool pointsUpFrogShown=false;


/*VARIABLES FOR POINTS USER*/
double pointsUser=0.0;
int furtherYposition=windowRect.h;

/***/
bool withLostFrog;

void RunGame();
void addSnake(PositionElement * pos,int speed);
bool CheckLostFrogCollision();

void checkReachTheGrass();

void reset();

void saveState();
void loadState();


/**STAGES*/

std::vector<Log *> ptrToLogs;
std::vector<Enemy *> ptrToEnemies;
std::vector<Turtle *> ptrToTurtles;

std::vector<Alligator *> ptrToAlligators;
Alligator * currentAlligator;

void addRowLogs2(Direction dir,logSize size,PositionElement * pos,int maxHighSpeed,LostFrog * lostFrog,int numLogs);
void addTurtlesRow2(PositionElement * pos,int maxHighSpeed,int numberOfTurtlesPerGroup ,int numberOfGroups);
void addEnemies2(Direction dir,PositionElement * pos,int maxHighSpeed,typeEnemy type, typeCar typeC,int numEnemies);
void addCocodrile(PositionElement * pos,int speed);
void moveLogs2();
void moveAlligators();
void moveTurtles2();
void moveEnemies2();

bool CheckAlligatorCollision2();
bool CheckEnemyCollisions2();
bool CheckLogCollision2();
bool CheckTurtlesCollision2();

void loadStage(bool ini,int stageNumber);

/**

 */
int yDestiny=0;
int xDestiny=0;

int main(int argc, const char * argv[]) {
    initAnything();
    
    window=CreateWindow(windowRect);
    renderer=CreateRenderer(window);
    
    /**LOST FROG*/
    lostFrog = new LostFrog();
    
    
    int xposition = rand() % windowRect.w;
    PositionElement position0(xposition,rows[0]);
    addRowLogs2(Right,Long,&position0,3,nullptr,2);
    addCocodrile(&position0,3);
    
    xposition = rand() % windowRect.w;
    PositionElement position1(xposition,rows[1]);
    addTurtlesRow2(&position1,3,3,4);

    
    xposition = rand() % windowRect.w;
    PositionElement position2(xposition,rows[2]);
    addRowLogs2(Left,Short,&position2,2,nullptr,2);
    
    xposition = rand() % windowRect.w;
    PositionElement position3(xposition,rows[3]);
    addRowLogs2(Right,Long,&position3,3,lostFrog,3);
    
    xposition = rand() % windowRect.w;
    PositionElement position4(xposition,rows[4]);
    addTurtlesRow2(&position4,5,2,3);

   
    xposition = rand() % windowRect.w;
    PositionElement position10(xposition,rows[5]);
    addSnake(&position10,3);
    
    xposition = rand() % windowRect.w;
    PositionElement position9(xposition,rows[6]);
    addEnemies2(Left,&position9,3,Truck,Car1,3);

    xposition = rand() % windowRect.w;
    PositionElement position5(xposition,rows[7]);
    addEnemies2(Right,&position5,3,Car,Car2,3);

    
    xposition = rand() % windowRect.w;
    PositionElement position6(xposition,rows[8]);
    addEnemies2(Left,&position6,3,Car,Car3,3);
    
    xposition = rand() % windowRect.w;
    PositionElement position7(xposition,rows[9]);
    addEnemies2(Right,&position7,3,Car,Car4,3);
    
    
    xposition = rand() % windowRect.w;
    PositionElement position8(xposition,rows[10]);
    addEnemies2(Left,&position8,3,Car,Car5,3);
    
    
    /**Rendering background.*/

    /**Run Game*/
    RunGame();
    

    quitAnything();
    
    return 0;
}


void RunGame(){

    bool loop=true;
    bool paused=false;
    bool quitMenuActive=false;
    bool gameOverActive=false;
    withLostFrog=false;
    
    bool showHighScoreMenu=false;
    
    bool onLog=false;
    bool onTurtle=false;
    bool onAlligator=false;
    
    
    
    SDL_Event event;
    
    Player p1(windowRect);
    ptrPlayer=&p1;
    HighScoreMenu highScoreMenu(renderer,windowRect);
    MainMenu mainMenu(renderer,windowRect);
    GameOver gameOverMenu(renderer,windowRect);
    gameWindow= new GameWindow(renderer,windowRect,ptrPlayer,ptrToLogs,ptrToEnemies,ptrToTurtles,ptrToAlligators,snake,lostFrog);
    
    activeMenu= &mainMenu;

    /**TIMER**/
    t1 = SDL_GetTicks();
    worldTime = 0;
    
    while(loop){
        /**TIMER */
        t2 = SDL_GetTicks();
        delta = (t2 - t1) * 0.001;
        t1 = t2;
        worldTime += delta;
        timeToShow=timeLive- worldTime+sumTimePaused;
        if(timeToShow<=0){
            reset();
        }
        gameWindow->drawTime(timeToShow);
        /** -TIMER*/
        
        /*POINTS**/
        gameWindow->drawPoints(pointsUser);
        
        while(SDL_PollEvent(&event)){
            
             if(event.type == SDL_QUIT){
                 loop=false;
             }else if(event.type == SDL_KEYDOWN){
                 
                 switch(event.key.keysym.sym){
                     case SDLK_1:
                         
                         if(activeMenu->getName()=="mainMenu"){
                             //activeMenu= &gameWindow;
                             activeMenu= gameWindow;
                         }
                     break;
                     case SDLK_2:
                        if(activeMenu->getName()=="mainMenu"){
                            loop=false;
                        }
                     break;
                    case SDLK_r:
                         if(activeMenu->getName()=="mainMenu"){
                             loadState();
                             activeMenu=gameWindow;
                         }
                    break;
                         
                    case SDLK_3:
                         SDL_Event highScoreevent;
                         showHighScoreMenu=true;
                         highScoreMenu.render2();
                         while(showHighScoreMenu==true){
                             while(SDL_PollEvent(&highScoreevent)){
                               if (highScoreevent.type == SDL_QUIT){
                                  showHighScoreMenu=false;
                                  loop=false;
                                }
                         else if(highScoreevent.type == SDL_KEYDOWN){
                                
                             if (highScoreevent.key.keysym.sym == SDLK_3){
                                        showHighScoreMenu = false;
                                        activeMenu=&mainMenu;
                                }
                            }
                            }//while of pause.
                             
                         }
                       
                    break;
        
                     case SDLK_p:
                        SDL_Event pauseEvent;
                        paused = true;
                        
                            if(activeMenu->getName()=="gameWindow"){
                                miliPaused=SDL_GetTicks();
                                //gameWindow.showPauseMenu();
                                gameWindow->showPauseMenu();
                                while(paused){
                                    while(SDL_PollEvent(&pauseEvent)){
                                        if (pauseEvent.type == SDL_QUIT){
                                            paused=false;
                                            loop=false;
                                        }
                                        else if(pauseEvent.type == SDL_KEYDOWN){
                                            if (pauseEvent.key.keysym.sym == SDLK_p){
                                                paused = false;
                                            }
                                        }
                                    }//while of pause.
                                }
                                timePaused=SDL_GetTicks()-miliPaused;
                                sumTimePaused=sumTimePaused+(timePaused/1000);
                            }//if(activeMenu->getName()=="gameWindow"){
                        
                     break;
                    
                     case SDLK_q:
                         SDL_Event quitEvent;
                         quitMenuActive = true;
                         
                         if(activeMenu->getName()=="gameWindow"){
                             miliPaused=SDL_GetTicks();
                             //gameWindow.showQuitMenu();
                             gameWindow->showQuitMenu();
                             while(quitMenuActive){
                                 while(SDL_PollEvent(&quitEvent)){
                                     if (quitEvent.type == SDL_QUIT){
                                         quitMenuActive=false;
                                         loop=false;
                                     }else if(quitEvent.type == SDL_KEYDOWN){
                                         if (quitEvent.key.keysym.sym == SDLK_y){
                                             quitMenuActive=false;
                                             loop=false;
                                         }else  if (quitEvent.key.keysym.sym == SDLK_n){
                                             quitMenuActive=false;
                                         }
                                     }
                                 }//while(SDL_PollEvent(&quitEvent)){
                             }// while(quitMenuActive){
                             timePaused=SDL_GetTicks()-miliPaused;
                             sumTimePaused=sumTimePaused+(timePaused/1000);
                         }//if(activeMenu->getName()=="gameWindow"){
                         break;
                     case SDLK_f:
                         
                         saveState();
                         SDL_Delay(1000);
                         loop=false;
                    
                         break;
                     case SDLK_w:
                         yDestiny=ptrPlayer->getPlayerPos().y-26;
                         
                         if(furtherYposition>yDestiny){
                          pointsUser=pointsUser+10.0;
                          furtherYposition=ptrPlayer->getPlayerPos().y;
                         }

                         p1.movePlayer2(Up,xDestiny,yDestiny);
                         break;
                    case SDLK_UP:
                         
                         yDestiny=ptrPlayer->getPlayerPos().y-26;
                         
                         if(furtherYposition>yDestiny){
                          pointsUser=pointsUser+10.0;
                          furtherYposition=ptrPlayer->getPlayerPos().y;
                         }

                         p1.movePlayer2(Up,xDestiny,yDestiny);
                         break;
                         
                    case SDLK_s:
                         yDestiny=p1.getPlayerPos().y+26;
                         p1.movePlayer2(Down,xDestiny,yDestiny);
                         break;
                    case SDLK_DOWN:
                         yDestiny=p1.getPlayerPos().y+26;
                         p1.movePlayer2(Down,xDestiny,yDestiny);
                         break;
                         
                    case SDLK_d:
                         xDestiny=p1.getPlayerPos().x+26;
                         p1.movePlayer2(Right,xDestiny,yDestiny);
                         
                         break;
                    case SDLK_RIGHT:
                        //p1.movePlayer(Right);
                         xDestiny=p1.getPlayerPos().x+26;
                        p1.movePlayer2(Right,xDestiny,yDestiny);
                         break;
                         
                    case SDLK_a:
                         xDestiny=p1.getPlayerPos().x-26;
                         p1.movePlayer2(Left,xDestiny,yDestiny);
                         //p1.movePlayer(Left);
                         break;
                    case SDLK_LEFT:
                    xDestiny=p1.getPlayerPos().x-26;
                    p1.movePlayer2(Left,xDestiny,yDestiny);
                         break;
                     case SDLK_n:
                         if(activeMenu->getName()=="gameOverMenu"){
                             loop=false;
                         }
                         break;
                    case SDLK_y:
                         if(activeMenu->getName()=="gameOverMenu"){
                             activeMenu=gameWindow;
                             gameWindow->resetGame();
                             reset();
                         }
                    break;
                     
                 }//switch(event.key.keysym.sym)
             
             }//else if(event.type == SDL_KEYDOWN)
        
        }//while(SDL_PollEvent(&event))
        
        if(!p1.isMoveCompleted()){
            if(p1.getFaceDirection()==Up){
                p1.movePlayer2(Up,xDestiny,yDestiny);
            }else if( p1.getFaceDirection()==Right){
                p1.movePlayer2(Right,xDestiny,yDestiny);
            }
            else if( p1.getFaceDirection()==Down){
                p1.movePlayer2(Down,xDestiny,yDestiny);
            }
            else if( p1.getFaceDirection()==Left){
                p1.movePlayer2(Left,xDestiny,yDestiny);
            }
        }
        
        
        activeMenu->render();
        
        if(activeMenu->getName()=="gameWindow"){
            moveLogs2();
            moveAlligators();
            moveTurtles2();
            moveEnemies2();
            snake->moveObject();
        }
        /* We check if we pass the grass*/
        checkReachTheGrass();
        
        SDL_Rect newPosition;
    
        if(CheckEnemyCollisions2()){
            savePointsToFile(pointsUser);
            gameWindow->gameOver();
            reset();
        }
        
        /**ALLIGATOR*/
        
        if(CheckAlligatorCollision2()){
            onAlligator=true;
            newPosition=ptrPlayer->getPlayerPos();
            newPosition.y=currentAlligator->getPosition().y;
            ptrPlayer->setPosition(newPosition);
        }else{
            onAlligator=false;
        }
        
        if(onAlligator){
             ptrPlayer->movePlayer(currentAlligator->getDirection(),currentAlligator->getSpeed());
        }
        
        /**CHECK */
        
       if(snake->CheckSnakeCollision(ptrPlayer->getPlayerPos())){
           savePointsToFile(pointsUser);
           gameWindow->gameOver();
            reset();
        }
        
        /**LOGS */
        if(CheckLogCollision2()){
            onLog=true;
            newPosition=ptrPlayer->getPlayerPos();
            newPosition.y=currentLog->getPosition().y;
            ptrPlayer->setPosition(newPosition);
        }else{
            onLog=false;
        }
        /**We move the player */
        if(onLog){
            ptrPlayer->movePlayer(currentLog->getDirection(),currentLog->getSpeed());
        }
        
        /**TURTLES*/
        if(CheckTurtlesCollision2()){
            onTurtle=true;
        }else{
            onTurtle=false;
        }
        /**We move the */
        if(onTurtle){
            ptrPlayer->movePlayer(currentTurtle->getDirection(),currentTurtle->getSpeed());
            newPosition=ptrPlayer->getPlayerPos();
            newPosition.y=currentTurtle->getPosition().y;
            ptrPlayer->setPosition(newPosition);
        }
        
        /**WE CHECK IF WE FALL IN THE WATER*/
        if((GameObject::CheckCollision(gameWindow->getWaterRect(), ptrPlayer->getPlayerPos()))&&(p1.isMoveCompleted())&&(!onLog)&&(!onAlligator)&&(!onTurtle)){
            savePointsToFile(pointsUser);
            gameWindow->gameOver();
            reset();
        }
       
        if(gameWindow->checkWin(ptrPlayer->getPlayerPos(),&pointsUser,withLostFrog)){
            gameWindow->drawPointsUpFrog(pointsUser,gameWindow->getLastWinRect());
            miliTimePointsUpShown=SDL_GetTicks();
            pointsUpFrogShown=true;
            savePointsToFile(pointsUser);
            reset();
            
            
            if(gameWindow->getWinsPlayer()==5){
                loadStage(false, 2);
            }
        }

        if(((SDL_GetTicks()-miliTimePointsUpShown)/1000>2.0)&&(pointsUpFrogShown==true)){
            gameWindow->quitPointsUpFrog();
            pointsUpFrogShown=false;
        }
     
        
        /**We check collision with the lost frog*/
        if(CheckLostFrogCollision()){
            withLostFrog=true;
        }

        if(withLostFrog==true){
            lostFrog->moveLostFrogInFrog(ptrPlayer->getPlayerPos());
        }
        /**WE CHECK GAME OVER*/
        if(gameWindow->getLivesPlayer()==0){
            activeMenu=&gameOverMenu;
        }
        
        
       
        SDL_Delay(32);
       
    }//while(loop)

}



bool CheckEnemyCollisions2(){
    for(auto &e : ptrToEnemies){
        if(e->CheckEnemyCollision(ptrPlayer->getPlayerPos()))
            return true;
    }
    return false;
}


bool CheckAlligatorCollision2(){
    for(auto &a : ptrToAlligators){
        if(a->CheckAlligatorCollision(ptrPlayer->getPlayerPos())){
            currentAlligator=a;
            return true;
        }
    }
    return false;
}

bool CheckLogCollision2(){
    
        for(auto &p : ptrToLogs){
            if(p->CheckLogCollision(ptrPlayer->getPlayerPos())){
                currentLog=p;
                if(ptrPlayer->getPlayerPos().x<p->getPosition().x){
                    SDL_Rect newPosition=ptrPlayer->getPlayerPos();
                    newPosition.x=p->getPosition().x;
                    ptrPlayer->setPosition(newPosition);
                }else if((ptrPlayer->getPlayerPos().x+ptrPlayer->getPlayerPos().w)>(p->getPosition().x+p->getPosition().w)){
                    SDL_Rect newPosition=ptrPlayer->getPlayerPos();
                    newPosition.x=(p->getPosition().x+p->getPosition().w)-newPosition.w;
                    ptrPlayer->setPosition(newPosition);
                }
                
                return true;
            }
        }
    
       return false;
}


bool CheckTurtlesCollision2(){
    for(auto &t : ptrToTurtles){
        if(t->CheckTurtleCollision(ptrPlayer->getPlayerPos())){
            currentTurtle=t;
            
            if(ptrPlayer->getPlayerPos().x<t->getPosition().x){
                SDL_Rect newPosition=ptrPlayer->getPlayerPos();
                newPosition.x=t->getPosition().x;
                ptrPlayer->setPosition(newPosition);
            }else if((ptrPlayer->getPlayerPos().x+ptrPlayer->getPlayerPos().w)>(t->getPosition().x+t->getPosition().w)){
                SDL_Rect newPosition=ptrPlayer->getPlayerPos();
                newPosition.x=(t->getPosition().x+t->getPosition().w)-newPosition.w;
                ptrPlayer->setPosition(newPosition);
            }
            
            return true;
        }
    }
        currentTurtle=nullptr;
       return false;
    
}


bool CheckLostFrogCollision(){
    if(lostFrog->CheckLostFrogCollision(ptrPlayer->getPlayerPos())){
        return true;
    }
    return false;
}


void addSnake(PositionElement *pos,int speed){
    snake=new Snake(0,0,speed,windowRect.w);
    pos->addElement(0,snake);
    
}


void checkReachTheGrass(){
    if((ptrPlayer->getPlayerPos().y<grassPos)&&(reachRiverbank==false)){
        reachRiverbank=true;
         pointsUser=pointsUser + 50 +(int)timeToShow *10;
        furtherYposition=ptrPlayer->getPlayerPos().y;
    }
}


void reset(){
    pointsUser=0.0;
    furtherYposition=windowRect.h;
    sumTimePaused=0.0;
    worldTime = 0;
    reachRiverbank=false;
    withLostFrog=false;
    lostFrog->resetLostFrog();
}


void saveState(){
    ofstream stateFile;
       stateFile.open ("state.txt",std::ofstream::trunc);

       if (stateFile.is_open())
       {
           stateFile << ptrPlayer->getPlayerPos().x<<endl;
           stateFile << ptrPlayer->getPlayerPos().y<<endl;
           stateFile<<pointsUser<<endl;
           stateFile<<reachRiverbank<<endl;
           stateFile<<furtherYposition<<endl;
           stateFile<<worldTime<<endl;
           stateFile<<gameWindow->getLivesPlayer()<<endl;
           stateFile<<snake->getPosition().x<<endl;
           stateFile<<snake->getPosition().y<<endl;
         
           for(auto *l: ptrToLogs){
               stateFile<<l->getPosition().x<<endl;
               stateFile<<l->getPosition().y<<endl;
           }
           for(auto *a: ptrToAlligators){
               stateFile<<a->getPosition().x<<endl;
               stateFile<<a->getPosition().y<<endl;
               stateFile<<a->getFrameNumber()<<endl;
               
           }
           
           for(auto *t: ptrToTurtles){
               stateFile<<t->getPosition().x<<endl;
               stateFile<<t->getPosition().y<<endl;
               stateFile<<t->getFrameNumber()<<endl;
           }
           
           for(auto *e: ptrToEnemies){
               stateFile<<e->getPosition().x<<endl;
               stateFile<<e->getPosition().y<<endl;
           }
           
           stateFile.close();
       }
}

void loadState(){
    std::ifstream myFile;
    myFile.open("state.txt",std::ifstream::in);

    std::string line;
    int posX,posY,furtherYpos,livesP,posXenemy,posYenemy,posXLog,posYLog,posXAlligator,posYAlligator,turtleX,turtleY,frameNumTurtle,frameAlligator,snakePosX,snakePosY;
    double pointsUs,timeToSh,worldT,sumTimeP;
    bool reachRiver,withLostF;
    if (myFile.is_open())
    {
        
            myFile >> posX;
           
            myFile>> posY;
        
        
            SDL_Rect newPosition={posX,posY,0,0};
            ptrPlayer->setPosition(newPosition);
            
            myFile>> pointsUs;
            pointsUser=pointsUs;
            
            myFile>>reachRiver;
            reachRiverbank=reachRiver;
            
            myFile>>furtherYpos;
            furtherYposition=furtherYpos;
        

            myFile>>worldT;
            worldTime=worldT;
            
            myFile>>livesP;
            gameWindow->setLivesPlayer(livesP);
            
            myFile>>snakePosX;
            myFile>>snakePosY;
            snake->setPosition(snakePosX,snakePosY);
            
        
            for(auto *l: ptrToLogs){
                myFile>>posXLog;
                myFile>>posYLog;
                l->setPosition(posXLog, posYLog);
            }
        
            for(auto *a: ptrToAlligators){
                myFile>>posXAlligator;
                myFile>>posYAlligator;
                a->setPosition(posXAlligator, posYAlligator);
                myFile>>frameAlligator;
                a->setFrameNumber(frameAlligator);
            }
         
        
            for(auto *t: ptrToTurtles){
                myFile>>turtleX;
                myFile>>turtleY;
                myFile>>frameNumTurtle;
                t->setPosition(turtleX, turtleY);
                t->setFrameNumber(frameNumTurtle);
            }
            
            for(auto *e: ptrToEnemies){
                myFile>>posXenemy;
                myFile>>posYenemy;
                e->setPosition(posXenemy, posYenemy);
            }
        
            
        
        
        /*
            for(auto l: ptrToLogs){
                myFile>>posXLog;
                myFile>>posYLog;
                l->setPosition(posXLog, posYLog);
            
            }
        */
    }

    myFile.close();
    
}


void addRowLogs2(Direction dir,logSize size,PositionElement * pos,int speed,LostFrog * lostFrog,int numLogs){
    Log * newLog;
    int speed2= rand() %  speed + 1;
    for(int i=0;i<numLogs;i++){
        newLog= new Log(0,0,speed,dir,size,windowRect.w);
        pos->addElement(size==Long?25:100,newLog);
        ptrToLogs.push_back(newLog);
        //logs.push_back(*newLog);
        
       if((lostFrog!=nullptr)&&(i==1)){
           cout<<"Entramos"<<endl;
           newLog->addLostFrog(lostFrog);
       }
    }
}


void addTurtlesRow2(PositionElement * pos,int maxHighSpeed,int numberOfTurtlesPerGroup ,int numberOfGroups){
     int speed = rand() %  maxHighSpeed + 1;
    Turtle * newTurtle;
    int posX;
    for (int n=0;n<numberOfGroups;n++){
        posX=30;
        
        for(int i=0;i<numberOfTurtlesPerGroup;i++){
           
            newTurtle= new Turtle(0,0,speed,Left,windowRect.w,2);
            if(i==0){
                pos->addElement(posX,newTurtle);
            }else{
                pos->addElement(0,newTurtle);
            }
           ptrToTurtles.push_back(newTurtle);
       }
    }

}


void addCocodrile(PositionElement * pos,int speed){
    Alligator * newAlligator;
    newAlligator= new Alligator(0,0,speed,Right,windowRect.w,2);
    pos->addElement(25,newAlligator);
    ptrToAlligators.push_back(newAlligator);
}

void addEnemies2(Direction dir,PositionElement * pos,int maxHighSpeed,typeEnemy type, typeCar typeC,int numEnemies){

     int speed = rand() %  maxHighSpeed + 1;
    //    Enemy(int x, int y, int speed_, Direction dir_,int wL,typeEnemy type);
    Enemy * newEnemy;
    
    for(int i = 0;i<numEnemies;i++){
        newEnemy= new Enemy(0,0,speed,dir,windowRect.w,type==Truck?Truck:Car,typeC);
        pos->addElement(60,newEnemy);
        ptrToEnemies.push_back(newEnemy);
        
    }
}


void moveLogs2(){
    for(auto &p : ptrToLogs){
        p->moveObject();
    }
}

void moveAlligators(){
    for(auto &a : ptrToAlligators){
        a->moveObject();
    }
}


void moveTurtles2(){
    for(auto &t : ptrToTurtles){
        t->moveObject();
    }
}


void moveEnemies2(){
   for(auto &e : ptrToEnemies){
        e->moveObject();
    }
}

void clear(){
    snake=nullptr;

    currentLog=nullptr;
    currentTurtle=nullptr;

    ptrToLogs.clear();
    ptrToEnemies.clear();
    ptrToTurtles.clear();
    ptrToAlligators.clear();
    currentAlligator=nullptr;

}

void loadStage(bool ini,int stageNumber){
     int maxSpeed=2;
        if(ini==false){
            clear();
        }
        
    
       int xposition = rand() % windowRect.w;
       PositionElement position0(xposition,rows[0]);
        if(stageNumber==1){
            addRowLogs2(Right,Long,&position0,maxSpeed,nullptr,3);
        }else if(stageNumber==2){
              addRowLogs2(Right,Long,&position0,maxSpeed,nullptr,2);
             addCocodrile(&position0,3);
        }
      
       
       xposition = rand() % windowRect.w;
       PositionElement position1(xposition,rows[1]);
       addTurtlesRow2(&position1,maxSpeed,3,4);

       
       xposition = rand() % windowRect.w;
       PositionElement position2(xposition,rows[2]);
       addRowLogs2(Left,Short,&position2,maxSpeed,nullptr,2);
       
       xposition = rand() % windowRect.w;
       PositionElement position3(xposition,rows[3]);
       addRowLogs2(Right,Long,&position3,maxSpeed,lostFrog,3);
       
       xposition = rand() % windowRect.w;
       PositionElement position4(xposition,rows[4]);
       addTurtlesRow2(&position4,maxSpeed,2,3);

      
       xposition = rand() % windowRect.w;
       PositionElement position10(xposition,rows[5]);
       addSnake(&position10,maxSpeed);
       
       xposition = rand() % windowRect.w;
       PositionElement position9(xposition,rows[6]);
       addEnemies2(Left,&position9,maxSpeed,Truck,Car1,3);

       xposition = rand() % windowRect.w;
       PositionElement position5(xposition,rows[7]);
       addEnemies2(Right,&position5,maxSpeed,Car,Car2,3);

       
       xposition = rand() % windowRect.w;
       PositionElement position6(xposition,rows[8]);
       addEnemies2(Left,&position6,maxSpeed,Car,Car3,3);
       
       xposition = rand() % windowRect.w;
       PositionElement position7(xposition,rows[9]);
       addEnemies2(Right,&position7,maxSpeed,Car,Car4,3);
       
       
       xposition = rand() % windowRect.w;
       PositionElement position8(xposition,rows[10]);
       addEnemies2(Left,&position8,maxSpeed,Car,Car5,3);
}

void loadSecondStage(){
       int xposition = rand() % windowRect.w;
       PositionElement position0(xposition,rows[0]);
       addRowLogs2(Right,Long,&position0,3,nullptr,2);
       addCocodrile(&position0,3);
       
       xposition = rand() % windowRect.w;
       PositionElement position1(xposition,rows[1]);
       addTurtlesRow2(&position1,3,3,4);

       
       xposition = rand() % windowRect.w;
       PositionElement position2(xposition,rows[2]);
       addRowLogs2(Left,Short,&position2,2,nullptr,2);
       
       xposition = rand() % windowRect.w;
       PositionElement position3(xposition,rows[3]);
       addRowLogs2(Right,Long,&position3,3,lostFrog,3);
       
       xposition = rand() % windowRect.w;
       PositionElement position4(xposition,rows[4]);
       addTurtlesRow2(&position4,5,2,3);

      
       xposition = rand() % windowRect.w;
       PositionElement position10(xposition,rows[5]);
       addSnake(&position10,3);
       
       xposition = rand() % windowRect.w;
       PositionElement position9(xposition,rows[6]);
       addEnemies2(Left,&position9,3,Truck,Car1,3);

       xposition = rand() % windowRect.w;
       PositionElement position5(xposition,rows[7]);
       addEnemies2(Right,&position5,3,Car,Car2,3);

       
       xposition = rand() % windowRect.w;
       PositionElement position6(xposition,rows[8]);
       addEnemies2(Left,&position6,3,Car,Car3,3);
       
       xposition = rand() % windowRect.w;
       PositionElement position7(xposition,rows[9]);
       addEnemies2(Right,&position7,3,Car,Car4,3);
       
       
       xposition = rand() % windowRect.w;
       PositionElement position8(xposition,rows[10]);
       addEnemies2(Left,&position8,3,Car,Car5,3);
}




