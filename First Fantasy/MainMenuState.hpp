//
//  MainMenuState.hpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "State.hpp"
#include "StateStack.hpp"

namespace ff {
    class MainMenuState : public State {
    public:
        MainMenuState(sf::RenderWindow &, ResourceManager &, StateStack &);
        void onEnter();
        void onExit();
        void onKeyPress(sf::Event &);
        void update(unsigned long);
        void display();
        
    };
}

#endif /* MainMenuState_hpp */
