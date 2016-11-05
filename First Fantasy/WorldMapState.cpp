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
    
    void WorldMapState::onEnter(State &parentState)
    {
        mParentState = &parentState;
        log(LogLevel::INFO, "Entering main menu state");
        
        mBattleMusic.openFromFile(resourcePath() +  "victory.wav");
        mBattleMusic.play();
    }
    
    void WorldMapState::onExit()
    {
        log(LogLevel::INFO, "Exiting main menu state");
        
        mBattleMusic.stop();
    }
    
    void WorldMapState::update(std::vector<sf::Event> &eventList, unsigned long tick)
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
                mStateStack->change("splash");
            }
        }
    }
    
    void WorldMapState::display()
    {
        // Load a sprite to display
        sf::Texture &texture = mResourceManager->getTexture("worldMapBG");
        sf::Sprite sprite(texture);
        
        // Create a graphical text to display
        sf::Font &font = mResourceManager->getFont("introFont");
        sf::Text text("World Map", font, 50);
        text.setPosition(500, 0);
        text.setColor(sf::Color::Black);
        
        // Update the window
        mWindow->draw(sprite);
        mWindow->draw(text);
    }
}
