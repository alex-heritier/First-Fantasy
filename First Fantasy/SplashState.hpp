//
//  SplashState.hpp
//  First Fantasy
//
//  Created by Alex on 10/8/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef SplashState_hpp
#define SplashState_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.hpp"
#include "State.hpp"
#include "StateStack.hpp"

namespace ff {
    class SplashState : public State {
    public:
        SplashState(sf::RenderWindow &, ResourceManager &, StateStack &);
        void onEnter();
        void onExit();
        void update(unsigned long);
        void display();
    private:
        // variables
        unsigned int mSplashHeight;
        sf::Sound mStartupSound;
        // methods
    };
}

#endif /* SplashState_hpp */
