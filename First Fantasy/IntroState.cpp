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
    
    void IntroState::onEnter(void *data, std::string message)
    {
        if (message == "") {
            Logger(LogType::INFO).put("Entering intro state");
            
            // setup music
            mMainTheme.openFromFile(resourcePath() + "golden_sun.wav");
            mMainTheme.play();
            
            // setup sprite
            mX = 400;
            mY = 300;
            sf::Texture &texture = getResourceManager().getTexture("FFSpriteSheet");
            mSprite.setTexture(texture);
            mSprite.setTextureRect(sf::IntRect(299, 95, 16, 16));
            mSprite.setPosition(mX, mY);
            mSprite.scale(2, 2);
        } else if (message == "end_dialog") {
            mMainTheme.play();
        }
    }
    
    void IntroState::onExit(std::string message)
    {
        if (message == "") {
            Logger(LogType::INFO).put("Exiting intro state");
            
            // reset sprite
            mSprite.scale(0.5, 0.5);
            
            // stop music
            mMainTheme.stop();
        } else if (message == "begin_dialog") {
            mMainTheme.pause();
        }
    }
    
    void IntroState::update(unsigned long delta)
    {
        // on return
        if (KeyboardManager::isKeyTapped(sf::Keyboard::Return)) {
            swapState("main_menu");
            return;
        }
        
        // on left
        const int moveStep = 2;
        if (KeyboardManager::isKeyPressed(sf::Keyboard::Left)) {
            mSprite.setTextureRect(sf::IntRect(240, 95, 16, 16));
            mX -= moveStep;
        }
        // on right
        else if (KeyboardManager::isKeyPressed(sf::Keyboard::Right)) {
            mSprite.setTextureRect(sf::IntRect(270, 95, 16, 16));
            mX += moveStep;
        }
        // on up
        else if (KeyboardManager::isKeyPressed(sf::Keyboard::Up)) {
            mSprite.setTextureRect(sf::IntRect(330, 95, 16, 16));
            mY -= moveStep;
        }
        // on down
        else if (KeyboardManager::isKeyPressed(sf::Keyboard::Down)) {
            mSprite.setTextureRect(sf::IntRect(299, 95, 16, 16));
            mY += moveStep;
            // on X
        } else if (KeyboardManager::isKeyTapped(sf::Keyboard::X)) {
            changeState("dialog", (void *)"Lorem ipsum dolor sit amet, consectetur.\nCras dui turpis, iaculis ut dapibus quis.\nNunc odio eros, facilisis vel efficitur.", "begin_dialog");
            return;
        }
        
        // update sprite position
        mSprite.setPosition(mX, mY);
    }
    
    void IntroState::display()
    {
        // create a background color
        sf::RectangleShape rect(sf::Vector2f(800, 600));
        rect.setFillColor(sf::Color::Green);
        rect.setPosition(0, 0);
        
        // Create a graphical text to display
        sf::Font &font = getResourceManager().getFont("introFont");
        sf::Text text("Intro", font, 50);
        text.setPosition(500, 0);
        text.setColor(sf::Color::Black);
        
        // Update the window
        getWindow().draw(rect);
        getWindow().draw(mSprite);
        getWindow().draw(text);
    }
}
