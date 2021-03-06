# C-FrogGame-with-SDL2
Frog Game version using C++ and [SDL2 library](https://www.libsdl.org/)


## Screenshots

![image1]( https://github.com/JoseManuelMoyaVargas/C-FrogGame-with-SDL2/blob/master/screenshots/mainMenu.png)
 
 * We can push '1' if we want to play the game.
 * '2' is used to quit the game.
 * Pressing 3 shows the 10 best results of the game that are obtained from a text file where they are stored.
 * If we want to continue the game where we stopped we can press 'r'.
 
### Pressing 3
 ![image2](https://github.com/JoseManuelMoyaVargas/C-FrogGame-with-SDL2/blob/master/screenshots/highScoresMenu.png)
 

### Playing the game

 ![image3](https://github.com/JoseManuelMoyaVargas/C-FrogGame-with-SDL2/blob/master/screenshots/workingGameGIF.gif)
 * Player controls a frog using arrow keys ↑,↓,←,→ or W, S, A, D keys
 * Pressing the 'p' key during the game causes the game to stop
 * The frog has 40 seconds to pass to the other side, otherwise it loses a life.
 * Points:
 1. Advance one position =10 points
 2. Leading Frogger to the nest on the safe riverbank = 50pts + the remaining time in seconds * 10pts 
 3. Successfully leading the lost frog (purple frog) = 200 pts
 4. Eating a bee = 200 pts
 
 *  Pressing the f key in an arbitrary moment saves the game state
 

