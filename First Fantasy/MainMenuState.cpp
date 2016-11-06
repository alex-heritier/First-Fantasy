//
//  MainMenuState.cpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include "MainMenuState.hpp"
#include "Log.hpp"

namespace ff {
    
    MainMenuState::MainMenuState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
    State(window, resourceManager, stateStack)
    {}
    
    void MainMenuState::onEnter()
    {
        log(LogLevel::INFO, "Entering main menu state");
    }
    
    void MainMenuState::onExit()
    {
        log(LogLevel::INFO, "Exiting main menu state");
    }
    
    void MainMenuState::onKeyPress(sf::Event &event)
    {
        switch (event.key.code) {
            case sf::Keyboard::Right:
                changeState("world_map");
                break;
            default:
                break;
        }
    }
    
    void MainMenuState::update(unsigned long delta)
    {
    }
    
    void MainMenuState::display()
    {
        // Load a sprite to display
        sf::Texture &texture = getResourceManager().getTexture("mainMenuBG");
        sf::Sprite sprite(texture);
        
        // Create a graphical text to display
        sf::Font &font = getResourceManager().getFont("introFont");
        sf::Text text("Main Menu", font, 50);
        text.setPosition(0, 540);
        text.setColor(sf::Color::Black);
        
        // Update the window
        getWindow().draw(sprite);
        getWindow().draw(text);
    }
}
