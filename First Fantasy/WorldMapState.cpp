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
#include "KeyboardManager.hpp"

namespace ff {
    
    WorldMapState::WorldMapState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        State(window, resourceManager, stateStack)
    {}
    
    void WorldMapState::onEnter(void *data)
    {
        Logger(LogType::INFO).put("Entering world map state");
        
        mBattleMusic.openFromFile(resourcePath() +  "victory.wav");
        mBattleMusic.play();
    }
    
    void WorldMapState::onExit()
    {
        Logger(LogType::INFO).put("Exiting world map state");
        
        mBattleMusic.stop();
    }
    
    void WorldMapState::update(unsigned long delta)
    {
        if (KeyboardManager::isKeyTapped(sf::Keyboard::Right)) {
            swapState("splash");
            return;
        }
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
