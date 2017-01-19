//
//  State.cpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <SFML/Graphics.hpp>

#include <iostream>

#include "State.hpp"
#include "StateStack.hpp"
#include "ResourceManager.hpp"

namespace ff {
    
    State::State():
        mWindow(nullptr),
        mResourceManager(nullptr),
        mStateStack(nullptr),
        mParentState(nullptr),
        mTick(0),
        mTime(0)
    {}
    
    State::State(sf::RenderWindow &window, ResourceManager &resourceManager, StateStack &stateStack):
        mWindow(&window),
        mResourceManager(&resourceManager),
        mStateStack(&stateStack),
        mParentState(nullptr),
        mTick(0),
        mTime(0)
    {}
    
    State::~State() {}
    
    void State::onEnterState(State &parentState, void *data, std::string message)
    {
        mParentState = &parentState;
        onEnter(data, message);
    }
    
    void State::onExitState(std::string message)
    {
        mTick = 0;
        mTime = 0;
        onExit(message);
    }
    
    void State::onKeyRelease(sf::Event &event) {}
    void State::onKeyPress(sf::Event &event) {}
    
    void State::updateState(std::vector<sf::Event> &eventList, unsigned long delta)
    {
        mTick++;
        mTime += delta;
        for (auto i = eventList.begin(); i < eventList.end(); i++) {
            sf::Event &event = *i;
            if (event.type == sf::Event::KeyPressed)
                onKeyPress(event);
            else if (event.type == sf::Event::KeyReleased)
                onKeyRelease(event);
        }
        update(delta);
    }
    
    // resource getters
    sf::RenderWindow &State::getWindow() const { return *mWindow; }
    ResourceManager &State::getResourceManager() const { return *mResourceManager; }
    State &State::getParent() const { return *mParentState; }
    
    // state changers
    void State::swapState(std::string stateName, std::string message) { mStateStack->swap(stateName, message); }
    void State::changeState(std::string stateName, void *data, std::string message) { mStateStack->change(stateName, data, message); }
    void State::endState(std::string message) { mStateStack->end(message); }
    
    // state change responders
    void State::onEnter(void *data, std::string message) {}
    void State::onExit(std::string message) {}
    
    // time change getters
    unsigned long State::tick() { return mTick; }
    unsigned long State::time() { return mTime; }
}
