//
//  GameEngine.cpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "GameEngine.hpp"
#include "State.hpp"
#include "StateStack.hpp"
#include "ResourcePath.hpp"

//////////////////////
// Helper Functions //
//////////////////////
/****************************************************/

int calculateFrameSleepTime(sf::Time time, int fps)
{
    int timePassed = time.asMilliseconds();
    int sleepTime = (1000.0 / fps) - timePassed;
    //std::cout << "sleepTime is " << sleepTime << std::endl;
    if (sleepTime < 0) sleepTime = 0;
    return sleepTime;
}


//////////////////////
// Class Methods    //
//////////////////////
/****************************************************/

namespace ff {
    
    GameEngine::GameEngine():
        mWindow(sf::VideoMode(800, 600), "SFML window"),
        mResourceManager(ResourceManager()),
        mStateStack(StateStack(mWindow, mResourceManager, "splash")),
        FPS(60)
    {}
    
    //////////////////////
    // Process Input    //
    //////////////////////
    void GameEngine::processInput(std::vector<sf::Event> &eventList)
    {
        // Process events
        sf::Event event;
        while (mWindow.pollEvent(event))
        {
            // add event to eventList
            eventList.push_back(event);
        }
    }
    
    //////////////////////
    // Update State     //
    //////////////////////
    void GameEngine::updateState(std::vector<sf::Event> &eventList, unsigned long tick)
    {
        State &currentState = mStateStack.top();
        currentState.update(eventList, tick);
    }
    
    //////////////////////
    // Update Display   //
    //////////////////////
    void GameEngine::updateDisplay()
    {
        mWindow.clear();
        State &currentState = mStateStack.top();
        currentState.display();
    }
    
    //////////////////////
    // Show Tick Time   //
    //////////////////////
    void GameEngine::showFPS(int time)
    {
        std::string msg = std::to_string(time);
        sf::Font &font = mResourceManager.getFont("introFont");
        sf::Text text(msg, font, 50);
        
        text.setPosition(740, 540);
        text.setColor(sf::Color::Green);
        mWindow.draw(text);
    }
    
    //////////////////////
    // Run              //
    //////////////////////
    int GameEngine::run()
    {
        // Start the game loop
        sf::Clock timer;
        unsigned long lastLoopElapsedTime = 0;
        while (mWindow.isOpen()) {
            timer.restart();
            
            std::vector<sf::Event> eventList;
            processInput(eventList);
            updateState(eventList, lastLoopElapsedTime);
            updateDisplay();
            
            // show fps
            showFPS(1000 / (1000.0 / 60 + lastLoopElapsedTime / 1000));
            
            // display what was drawn on window
            mWindow.display();
            
            // sleep to pad frame time
            sf::Time elapsedTime = timer.getElapsedTime();
            lastLoopElapsedTime = elapsedTime.asMicroseconds();
            
            int sleepTime = calculateFrameSleepTime(elapsedTime, FPS);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        }
        
        return EXIT_SUCCESS;
    }
}
