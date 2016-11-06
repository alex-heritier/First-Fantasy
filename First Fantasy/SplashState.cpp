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

namespace ff {
    
    SplashState::SplashState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
    State(window, resourceManager, stateStack)
    {}
    
    void SplashState::onEnter()
    {
        log(LogLevel::INFO, "Entering splash state");
        
        mStartupSound.setBuffer(getResourceManager().getSound("splashSound"));
        mStartupSound.play();
    }
    
    void SplashState::onExit()
    {
        log(LogLevel::INFO, "Exiting splash state");
        
        mSplashHeight = 0;
        mStartupSound.stop();
        mStartupSound.resetBuffer();
    }
    
    void SplashState::onKeyPress(sf::Event &event)
    {
        switch (event.key.code) {
            // Enter or X buttons pressed : go to intro animation
            case sf::Keyboard::Escape:
            case sf::Keyboard::X:
                swapState("intro");
                break;
            default:
                break;
        }
    }
    
    void SplashState::update(unsigned long delta)
    {
        // set splash height
        mSplashHeight = (tick() * 4) > 250 ? 250 : (unsigned int)(tick() * 4);
        
        if (time() > sf::milliseconds(3000).asMicroseconds())
            swapState("intro");
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
