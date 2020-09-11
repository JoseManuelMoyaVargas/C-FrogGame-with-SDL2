//  Copyright © Jose Manuel Moya Vargas. All rights reserved.


#include "Menu.hpp"

Menu::Menu(SDL_Renderer* renderer,SDL_Rect windowRect,const std::string n){
     Menu::renderer=renderer;
     Menu::windowRect=windowRect;
     Menu::name=n;
}

std::string Menu::getName(){
    return name;
}

void Menu::render(){
    
}


