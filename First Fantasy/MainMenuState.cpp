//
//  MainMenuState.cpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include "MainMenuState.hpp"
#include "Log.hpp"
#include "KeyboardManager.hpp"

namespace ff {
    
    MainMenuState::MainMenuState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
    State(window, resourceManager, stateStack)
    {}
    
    void MainMenuState::onEnter(void *data)
    {
        Logger(LogType::INFO).put("Entering main menu state");
    }
    
    void MainMenuState::onExit()
    {
        Logger(LogType::INFO).put("Exiting main menu state");
    }
    
    void MainMenuState::update(unsigned long delta)
    {
        if (KeyboardManager::isKeyTapped(sf::Keyboard::Return)) {
            swapState("world_map");
            return;
        }
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
