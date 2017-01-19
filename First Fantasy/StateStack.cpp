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
#include "DialogState.hpp"
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
        mStates["dialog"] = std::unique_ptr<State>(new DialogState(window, resourceManager, *this));
        mStates["splash"] = std::unique_ptr<State>(new SplashState(window, resourceManager, *this));
        mStates["intro"] = std::unique_ptr<State>(new IntroState(window, resourceManager, *this));
        mStates["main_menu"] = std::unique_ptr<State>(new MainMenuState(window, resourceManager, *this));
        mStates["world_map"] = std::unique_ptr<State>(new WorldMapState(window, resourceManager, *this));
        
        mStack.push(&getState("blank"));
        change(firstState, nullptr);
    }
    
    // push a new state onto the stack
    void StateStack::change(std::string stateName, void *data, std::string message)
    {
        State &oldTop = top();
        State &newTop = getState(stateName);
        oldTop.onExitState(message);
        mStack.push(&newTop);
        newTop.onEnterState(oldTop, data, message);
    }
    
    // replace the top state with a new state
    void StateStack::swap(std::string stateName, std::string message)
    {
        if (mStack.size() == 1) {   // only has blank state
            Logger(LogType::ERROR).put("Cannot swap from the blank state.");
            return;
        }
        State &oldTop = top();
        State &newTop = getState(stateName);
        oldTop.onExitState(message);
        mStack.pop();
        mStack.push(&newTop);
        newTop.onEnterState(top(), nullptr, message);
    }
    
    // pops top state off of stack
    void StateStack::end(std::string message)
    {
        if (mStack.size() == 1) {   // only has blank state
            Logger(LogType::ERROR).put("Cannot end the blank state.");
            return;
        }
        State &oldTop = top();
        oldTop.onExitState(message);
        mStack.pop();
        State &newTop = top();
        newTop.onEnterState(newTop, nullptr, message);
    }
    
    // return top state from the stack
    ff::State &StateStack::top()
    {
        return *mStack.top();
    }
    
    // get a state from the state map
    ff::State &StateStack::getState(std::string stateName)
    {
        return *mStates[stateName];
    }
}
