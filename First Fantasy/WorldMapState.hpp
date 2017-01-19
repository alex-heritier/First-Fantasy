//
//  WorldMapState.hpp
//  First Fantasy
//
//  Created by Alex on 11/2/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef WorldMapState_hpp
#define WorldMapState_hpp

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "State.hpp"
#include "StateStack.hpp"

namespace ff {
    class WorldMapState : public State {
    public:
        WorldMapState(sf::RenderWindow &, ResourceManager &, StateStack &);
        void onEnter(void *);
        void onExit();
        void update(unsigned long);
        void display();
    private:
        // variables
        sf::Music mBattleMusic;
    };
}

#endif /* WorldMapState_hpp */
