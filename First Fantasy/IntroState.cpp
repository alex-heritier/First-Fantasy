//
//  IntroState.cpp
//  First Fantasy
//
//  Created by Alex on 11/3/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include "IntroState.hpp"
#include "ResourcePath.hpp"
#include "Log.hpp"

namespace ff {
    
    IntroState::IntroState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        State(window, resourceManager, stateStack)
    {}
    
    void IntroState::onEnter(State &parentState)
    {
        mParentState = &parentState;
        log(LogLevel::INFO, "Entering intro state");
        
        mMainTheme.openFromFile(resourcePath() + "golden_sun.wav");
        mMainTheme.play();
    }
    
    void IntroState::onExit()
    {
        log(LogLevel::INFO, "Exiting intro state");
        
        mMainTheme.stop();
    }
    
    void IntroState::update(std::vector<sf::Event> &eventList, unsigned long tick)
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
            
            // Enter button pressed : go to main menu state
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
                mStateStack->change("main_menu");
            }
        }
    }
    
    void IntroState::display()
    {
        // Load a sprite to display
        sf::Texture &texture = mResourceManager->getTexture("worldMapBG");
        sf::Sprite sprite(texture);
        
        // Create a graphical text to display
        sf::Font &font = mResourceManager->getFont("introFont");
        sf::Text text("Intro", font, 50);
        text.setPosition(500, 0);
        text.setColor(sf::Color::Black);
        
        // Update the window
        mWindow->draw(sprite);
        mWindow->draw(text);
    }
}
