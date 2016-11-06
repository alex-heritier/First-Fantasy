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
    
    void IntroState::onEnter()
    {
        log(LogLevel::INFO, "Entering intro state");
        
        mMainTheme.openFromFile(resourcePath() + "golden_sun.wav");
        mMainTheme.play();
    }
    
    void IntroState::onExit()
    {
        log(LogLevel::INFO, "Exiting intro state");
        
        mMainTheme.stop();
    }
    
    void IntroState::onKeyPress(sf::Event &event)
    {
        switch (event.key.code) {
            // Enter button pressed : go to main menu state
            case sf::Keyboard::Right:
                changeState("main_menu");
                break;
            default:
                break;
        }
    }
    
    void IntroState::update(unsigned long delta)
    {
    }
    
    void IntroState::display()
    {
        // Load a sprite to display
        sf::Texture &texture = getResourceManager().getTexture("worldMapBG");
        sf::Sprite sprite(texture);
        
        // Create a graphical text to display
        sf::Font &font = getResourceManager().getFont("introFont");
        sf::Text text("Intro", font, 50);
        text.setPosition(500, 0);
        text.setColor(sf::Color::Black);
        
        // Update the window
        getWindow().draw(sprite);
        getWindow().draw(text);
    }
}
