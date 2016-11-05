//
//  MainMenuState.cpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>

#include "MainMenuState.hpp"
#include "Log.hpp"

namespace ff {
    
    MainMenuState::MainMenuState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        State(window, resourceManager, stateStack)
    {}
    
    void MainMenuState::onEnter(State &parentState)
    {
        mParentState = &parentState;
        log(LogLevel::INFO, "Entering main menu state");
    }
    
    void MainMenuState::onExit()
    {
        log(LogLevel::INFO, "Exiting main menu state");
    }
    
    void MainMenuState::update(std::vector<sf::Event> &eventList, unsigned long tick)
    {
        for (auto i = eventList.begin(); i != eventList.end(); i++) {
            sf::Event &event = *i;
            
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                mWindow->close();
            }
            
            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                mWindow->close();
            }
            
            // Right arrow pressed : go to main menu state
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
                mStateStack->change("world_map");
            }
        }
    }
    
    void MainMenuState::display()
    {
        // Load a sprite to display
        sf::Texture &texture = mResourceManager->getTexture("mainMenuBG");
        sf::Sprite sprite(texture);
        
        // Create a graphical text to display
        sf::Font &font = mResourceManager->getFont("introFont");
        sf::Text text("Main Menu", font, 50);
        text.setPosition(0, 540);
        text.setColor(sf::Color::Black);
        
        // Update the window
        mWindow->draw(sprite);
        mWindow->draw(text);
    }
}
