//
//  BlankState.cpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef BlankState_hpp
#define BlankState_hpp

#include <iostream>

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "StateStack.hpp"
#include "ResourceManager.hpp"

namespace ff {
    class BlankState : public State {
    public:
        BlankState(sf::RenderWindow &, ResourceManager &, StateStack &);
        void onEnter(void *, std::string = "");
        void onExit(std::string = "");
        void update(unsigned long);
        void display();
    };
}

#endif /* BlankState_hpp */
