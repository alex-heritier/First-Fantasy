//
//  State.hpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

namespace ff {
    class StateStack; // prevent circular include
    
    class State {
    public:
        State();
        State(sf::RenderWindow &, ResourceManager &, StateStack &);
        virtual ~State();
        virtual void onEnter(State &);
        virtual void onExit() = 0;
        virtual void update(std::vector<sf::Event> &, unsigned long);
        virtual void display() = 0;
    protected:
        // variables
        sf::RenderWindow *mWindow;
        ResourceManager *mResourceManager;
        StateStack *mStateStack;
        State *mParentState;
        // methods
    };
}

#endif /* State_hpp */
