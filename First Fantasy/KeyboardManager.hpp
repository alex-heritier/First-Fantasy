//
//  KeyboardManager.hpp
//  First Fantasy
//
//  Created by Alex on 11/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef KeyboardManager_hpp
#define KeyboardManager_hpp

#include <SFML/Graphics.hpp>

#include <list>

class KeyboardManager {
public:
    static bool isKeyPressed(sf::Keyboard::Key);
    static bool isKeyReleased(sf::Keyboard::Key);
    static bool isKeyTapped(sf::Keyboard::Key);
    static void update();
private:
    // methods
    KeyboardManager();
    // variables
    static std::list<sf::Keyboard::Key> mPressedKeys;
    static std::list<sf::Keyboard::Key> mReleasedKeys;
    static std::list<sf::Keyboard::Key> mTappedKeys;
};

#endif /* KeyboardManager_hpp */
