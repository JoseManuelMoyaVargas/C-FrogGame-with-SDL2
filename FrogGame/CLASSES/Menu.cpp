//
//  Menu.cpp
//  Created by Jose Manuel Moya Vargas on 05/01/2020.
//  Copyright © 2020 Jose Manuel Moya Vargas. All rights reserved.
//

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


