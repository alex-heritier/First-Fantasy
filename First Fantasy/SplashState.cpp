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
        State(window, resourceManager, stateStack),
        mTick(0)
    {}
    
    void SplashState::onEnter(State &parentState)
    {
        mParentState = &parentState;
        log(LogLevel::INFO, "Entering splash state");
        
        mStartupSound.setBuffer(mResourceManager->getSound("splashSound"));
        mStartupSound.play();
    }
    
    void SplashState::onExit()
    {
        log(LogLevel::INFO, "Exiting splash state");
        
        mTick = 0;
        mSplashHeight = 0;
        mStartupSound.stop();
        mStartupSound.resetBuffer();
    }
    
    void SplashState::update(std::vector<sf::Event> &eventList, unsigned long tick)
    {
        // respond to input
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
            
            if (event.type == sf::Event::KeyPressed) {
                // Enter or X buttons pressed : go to intro animation
                if (event.key.code == sf::Keyboard::Return
                    || event.key.code == sf::Keyboard::X) {
                    mStateStack->swap("intro");
                    return;
                }
            }
        }
        
        // set splash height
        mTick++;
        mSplashHeight = (mTick * 4) > 250 ? 250 : mTick * 4;
        
        if (mTick > 200)
            mStateStack->swap("intro");
    }
    
    void SplashState::display()
    {
        // Clear rectangle
        sf::RectangleShape clearRect(sf::Vector2f(800, 600));
        clearRect.setFillColor(sf::Color::White);
        
        // Load a sprite to display
        sf::Texture &texture = mResourceManager->getTexture("splashImg");
        sf::Sprite sprite(texture);
        
        sprite.setPosition(150, mSplashHeight);
        
        // Update the window
        mWindow->draw(clearRect);
        mWindow->draw(sprite);
    }
}
