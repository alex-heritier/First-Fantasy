//
//  SplashState.cpp
//  First Fantasy
//
//  Created by Alex on 10/8/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>

#include <SFML/Graphics.hpp>

#include "SplashState.hpp"
#include "State.hpp"
#include "Log.hpp"
#include "KeyboardManager.hpp"

namespace ff {
    
    SplashState::SplashState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
    State(window, resourceManager, stateStack)
    {}
    
    void SplashState::onEnter(void *data, std::string message)
    {
        Logger(LogType::INFO).put("Entering splash state");
        
        mStartupSound.setBuffer(getResourceManager().getSound("splashSound"));
        mStartupSound.play();
    }
    
    void SplashState::onExit(std::string message)
    {
        Logger(LogType::INFO).put("Exiting splash state");
        
        mSplashHeight = 0;
        mStartupSound.stop();
        mStartupSound.resetBuffer();
    }
    
    void SplashState::update(unsigned long delta)
    {
        if (KeyboardManager::isKeyTapped(sf::Keyboard::Return)) {
            swapState("intro");
            return;
        }
        
        if (time() > sf::milliseconds(3000).asMicroseconds())
            swapState("intro");
        
        // set splash height
        mSplashHeight = (tick() * 4) > 250 ? 250 : (unsigned int)(tick() * 4);
    }
    
    void SplashState::display()
    {
        // Clear rectangle
        sf::RectangleShape clearRect(sf::Vector2f(800, 600));
        clearRect.setFillColor(sf::Color::White);
        
        // Load a sprite to display
        sf::Texture &texture = getResourceManager().getTexture("splashImg");
        sf::Sprite sprite(texture);
        
        sprite.setPosition(150, mSplashHeight);
        
        // Update the window
        getWindow().draw(clearRect);
        getWindow().draw(sprite);
    }
}
