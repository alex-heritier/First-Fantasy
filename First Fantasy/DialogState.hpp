//
//  DialogState.hpp
//  First Fantasy
//
//  Created by Alex on 11/8/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef DialogState_hpp
#define DialogState_hpp

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

#include "ResourceManager.hpp"
#include "StateStack.hpp"
#include "State.hpp"

namespace ff {
    class DialogState : public State {
    public:
        DialogState(sf::RenderWindow &, ResourceManager &, StateStack &);
        void onEnter(void *, std::string = "");
        void onExit(std::string = "");
        void update(unsigned long);
        void display();
    private:
        const int mMaxLineLength;
        std::string mText;
    };
}

#endif /* DialogState_hpp */
