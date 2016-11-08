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
#include "KeyboardManager.hpp"

namespace ff {
    
    IntroState::IntroState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        State(window, resourceManager, stateStack)
    {}
    
    void IntroState::onEnter()
    {
        Logger(LogType::INFO).put("Entering intro state");
        
        
        // setup music
        mMainTheme.openFromFile(resourcePath() + "golden_sun.wav");
        mMainTheme.play();
        
        // setup sprite
        mX = 400;
        mY = 300;
        sf::Texture &texture = getResourceManager().getTexture("FFSpriteSheet");
        mSprite.setTexture(texture);
        mSprite.setTextureRect(sf::IntRect(300, 95, 16, 16));
        mSprite.setPosition(mX, mY);
    }
    
    void IntroState::onExit()
    {
        Logger(LogType::INFO).put("Exiting intro state");
        
        // stop music
        mMainTheme.stop();
    }
    
    void IntroState::update(unsigned long delta)
    {
        // on return
        if (KeyboardManager::isKeyTapped(sf::Keyboard::Return)) {
            swapState("main_menu");
            return;
        }
        
        // on left
        if (KeyboardManager::isKeyPressed(sf::Keyboard::Left)) {
            mSprite.setTextureRect(sf::IntRect(240, 95, 16, 16));
            mX -= 2;
        }
        
        // on right
        else if (KeyboardManager::isKeyPressed(sf::Keyboard::Right)) {
            mSprite.setTextureRect(sf::IntRect(270, 95, 16, 16));
            mX += 2;
        }
        
        // on up
        else if (KeyboardManager::isKeyPressed(sf::Keyboard::Up)) {
            mSprite.setTextureRect(sf::IntRect(330, 95, 16, 16));
            mY -= 2;
        }
        
        // on down
        else if (KeyboardManager::isKeyPressed(sf::Keyboard::Down)) {
            mSprite.setTextureRect(sf::IntRect(300, 95, 16, 16));
            mY += 2;
        }
        
        // update sprite position
        mSprite.setPosition(mX, mY);
    }
    
    void IntroState::display()
    {
        // Create a graphical text to display
        sf::Font &font = getResourceManager().getFont("introFont");
        sf::Text text("Intro", font, 50);
        text.setPosition(500, 0);
        text.setColor(sf::Color::Black);
        
        // Update the window
        getWindow().draw(mSprite);
        getWindow().draw(text);
    }
}
