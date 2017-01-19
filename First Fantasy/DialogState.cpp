//
//  DialogState.cpp
//  First Fantasy
//
//  Created by Alex on 11/8/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <vector>

#include "DialogState.hpp"
#include "Log.hpp"
#include "KeyboardManager.hpp"

namespace ff {
    
    DialogState::DialogState(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
    State(window, resourceManager, stateStack),
    mMaxLineLength(43)
    {}
    
    void DialogState::onEnter(void *data, std::string message)
    {
        Logger(LogType::INFO).put("Entering dialog state");
        
        // get data
        mText = std::string(static_cast<const char *>(data));
    }
    
    void DialogState::onExit(std::string message)
    {
        Logger(LogType::INFO).put("Exiting dialog state");
        
    }
    
    void DialogState::update(unsigned long)
    {
        // on Z
        if (KeyboardManager::isKeyTapped(sf::Keyboard::Z)) {
            endState("end_dialog");
            return;
        }
        // on left
        else if (KeyboardManager::isKeyTapped(sf::Keyboard::Left)) {
            return;
        }
        // on right
        else if (KeyboardManager::isKeyTapped(sf::Keyboard::Right)) {
            return;
        }
    }
    
    void DialogState::display()
    {
        // draw text box
        sf::RectangleShape outerTextBox(sf::Vector2f(780, 160));
        outerTextBox.setPosition(10, 430);
        outerTextBox.setFillColor(sf::Color(69,69,69));
        sf::RectangleShape innerTextBox(sf::Vector2f(760, 140));
        innerTextBox.setPosition(20, 440);
        innerTextBox.setFillColor(sf::Color(100,100,100));
        
        // draw text
        sf::Font &font = getResourceManager().getFont("dialogFont");
        sf::Text text(mText, font, 30);
        text.setPosition(25, 440);
        text.setColor(sf::Color::Black);
        
        // draw parent state first
        getParent().display();
        getWindow().draw(outerTextBox);
        getWindow().draw(innerTextBox);
        getWindow().draw(text);
    }
}
