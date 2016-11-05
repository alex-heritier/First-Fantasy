//
//  StateStack.cpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "StateStack.hpp"
#include "State.hpp"
#include "BlankState.hpp"
#include "SplashState.hpp"
#include "IntroState.hpp"
#include "MainMenuState.hpp"
#include "WorldMapState.hpp"
#include "ResourceManager.hpp"
#include "Log.hpp"

namespace ff {
    
    StateStack::StateStack(sf::RenderWindow &window, ResourceManager &resourceManager, std::string firstState)
    {
        mStates["blank"] = std::unique_ptr<State>(new BlankState(window, resourceManager, *this));
        mStates["splash"] = std::unique_ptr<State>(new SplashState(window, resourceManager, *this));
        mStates["intro"] = std::unique_ptr<State>(new IntroState(window, resourceManager, *this));
        mStates["main_menu"] = std::unique_ptr<State>(new MainMenuState(window, resourceManager, *this));
        mStates["world_map"] = std::unique_ptr<State>(new WorldMapState(window, resourceManager, *this));
        
        mStack.push(&getState("blank"));
        change(firstState);
    }
    
    void StateStack::change(std::string stateName)
    {
        State &oldTop = top();
        State &newTop = getState(stateName);
        oldTop.onExit();
        mStack.push(&newTop);
        newTop.onEnter(oldTop);
    }
    
    void StateStack::swap(std::string stateName)
    {
        if (mStack.size() == 1) {   // only has blank state
            log(LogLevel::ERROR, "can't swap from the blank state.");
        }
        State &oldTop = top();
        State &newTop = getState(stateName);
        oldTop.onExit();
        mStack.pop();
        mStack.push(&newTop);
        newTop.onEnter(top());
    }
    
    ff::State &StateStack::top()
    {
        return *mStack.top();
    }
    
    ff::State &StateStack::getState(std::string stateName)
    {
        return *mStates[stateName];
    }
}
