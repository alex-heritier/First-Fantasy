//
//  GameEngine.hpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <SFML/Graphics.hpp>

#include <vector>

#include "ResourceManager.hpp"
#include "StateStack.hpp"

namespace ff {
    class GameEngine {
    public:
        GameEngine();
        int run();
    private:
        // variables
        const int FPS;
        sf::RenderWindow mWindow;
        ResourceManager mResourceManager;
        StateStack mStateStack;
        
        // methods
        void processInput(std::vector<sf::Event> &);
        void updateState(std::vector<sf::Event> &, unsigned long);
        void updateDisplay();
        void showFPS(int);
    };
}

#endif /* GameEngine_hpp */
