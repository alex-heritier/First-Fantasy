//
//  StateStack.hpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef StateStack_hpp
#define StateStack_hpp

#include <SFML/Graphics.hpp>

#include <iostream>
#include <stack>
#include <unordered_map>
#include <memory>

#include "State.hpp"
#include "ResourceManager.hpp"

namespace ff {
    class StateStack {
    public:
        StateStack(sf::RenderWindow &, ResourceManager &, std::string);
        void change(std::string);
        void swap(std::string);
        void end();
        State &top();
    private:
        // variables
        std::stack<State *> mStack;
        std::unordered_map<std::string, std::unique_ptr<State> > mStates;
        // methods
        StateStack();
        State &getState(std::string);
    };
}

#endif /* StateStack_hpp */
