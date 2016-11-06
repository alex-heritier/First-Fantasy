//
//  WorldMapState.cpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include "WorldMapState.hpp"
#include "ResourcePath.hpp"
#include "Log.hpp"

namespace ff {
    
    WorldMapState::WorldMapState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        State(window, resourceManager, stateStack)
    {}
    
    void WorldMapState::onEnter()
    {
        log(LogLevel::INFO, "Entering world map state");
        
        mBattleMusic.openFromFile(resourcePath() +  "victory.wav");
        mBattleMusic.play();
    }
    
    void WorldMapState::onExit()
    {
        log(LogLevel::INFO, "Exiting world map state");
        
        mBattleMusic.stop();
    }
    
    void WorldMapState::onKeyPress(sf::Event &event)
    {
        switch (event.key.code) {
            // Right arrow pressed : go to main menu state
            case sf::Keyboard::Right:
                changeState("splash");
                break;
            default:
                break;
        }
    }
    
    void WorldMapState::update(unsigned long delta)
    {
    }
    
    void WorldMapState::display()
    {
        // Load a sprite to display
        sf::Texture &texture = getResourceManager().getTexture("worldMapBG");
        sf::Sprite sprite(texture);
        
        // Create a graphical text to display
        sf::Font &font = getResourceManager().getFont("introFont");
        sf::Text text("World Map", font, 50);
        text.setPosition(500, 0);
        text.setColor(sf::Color::Black);
        
        // Update the window
        getWindow().draw(sprite);
        getWindow().draw(text);
    }
}
