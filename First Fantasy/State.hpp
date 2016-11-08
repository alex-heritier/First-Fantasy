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
        virtual void onEnterState(State &) final;
        virtual void onExitState() final;
        virtual void updateState(std::vector<sf::Event> &, unsigned long) final;
        virtual void display() = 0;
    protected:
        // methods
        virtual sf::RenderWindow &getWindow() const final;
        virtual ResourceManager &getResourceManager() const final;
        virtual State &getParent() const final;
        virtual void swapState(std::string) final;
        virtual void changeState(std::string) final;
        virtual unsigned long tick() final;
        virtual unsigned long time() final;
        virtual void onEnter() = 0;
        virtual void onExit() = 0;
        virtual void onKeyPress(sf::Event &);
        virtual void onKeyRelease(sf::Event &);
        virtual void update(unsigned long) = 0;
    private:
        // variables
        sf::RenderWindow *const mWindow;
        ResourceManager *const mResourceManager;
        StateStack *const mStateStack;
        State *mParentState;
        unsigned long mTick;    // incremented by 1 every update
        unsigned long mTime;    // incremented by delta every update
    };
}

#endif /* State_hpp */
