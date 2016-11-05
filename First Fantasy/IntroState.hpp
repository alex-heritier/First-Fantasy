//
//  IntroState.hpp
//  First Fantasy
//
//  Created by Alex on 11/3/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef IntroState_hpp
#define IntroState_hpp

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "State.hpp"
#include "StateStack.hpp"

namespace ff {
    class IntroState : public State {
    public:
        IntroState(sf::RenderWindow &, ResourceManager &, StateStack &);
        void onEnter(State &);
        void onExit();
        void update(std::vector<sf::Event> &, unsigned long);
        void display();
    private:
        // variables
        sf::Music mMainTheme;
    };
}


#endif /* IntroState_hpp */