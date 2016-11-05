//
//  BlankState.cpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>

#include "BlankState.hpp"
#include "Log.hpp"

namespace ff {
    
    BlankState::BlankState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        State(window, resourceManager, stateStack)
    {
    }
    
    void BlankState::onEnter(State &parentState)
    {
        log(LogLevel::INFO, "Entering blank state");
    }
    
    void BlankState::onExit()
    {
        log(LogLevel::INFO, "Exiting blank state");
    }
    
    void BlankState::update(std::vector<sf::Event> &, unsigned long tick)
    {
    }
    
    void BlankState::display()
    {
        sf::RectangleShape blackRect(sf::Vector2f(800, 600));
        blackRect.setFillColor(sf::Color::Black);
        
        mWindow->draw(blackRect);
    }
}
