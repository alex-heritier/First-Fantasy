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
    
    void BlankState::onEnter(void *data, std::string message) { Logger(LogType::INFO).put("Entering blank state"); }
    void BlankState::onExit(std::string message) { Logger(LogType::INFO).put("Exiting blank state"); }
    
    void BlankState::update(unsigned long delta) {}
    
    void BlankState::display()
    {
        sf::RectangleShape blackRect(sf::Vector2f(800, 600));
        blackRect.setFillColor(sf::Color::Black);
        
        getWindow().draw(blackRect);
    }
}
