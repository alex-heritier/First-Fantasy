//
//  KeyboardManager.cpp
//  First Fantasy
//
//  Created by Alex on 11/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <iostream>
#include <algorithm>

#include "KeyboardManager.hpp"

// helper data
static const sf::Keyboard::Key _keys[] = {
    sf::Keyboard::Left,
    sf::Keyboard::Right,
    sf::Keyboard::Up,
    sf::Keyboard::Down,
    sf::Keyboard::Return,
    sf::Keyboard::Z,
    sf::Keyboard::X,
};
static const int _keyCount = sizeof(_keys) / sizeof(_keys[0]);

// helper functions
bool listHas(std::list<sf::Keyboard::Key> &list, sf::Keyboard::Key key)
{
    return std::find(list.begin(), list.end(), key) != list.end();
}

std::list<sf::Keyboard::Key> KeyboardManager::mPressedKeys;
std::list<sf::Keyboard::Key> KeyboardManager::mReleasedKeys;
std::list<sf::Keyboard::Key> KeyboardManager::mTappedKeys;

bool KeyboardManager::isKeyPressed(sf::Keyboard::Key key)
{
    return listHas(mPressedKeys, key);
}

bool KeyboardManager::isKeyTapped(sf::Keyboard::Key key)
{
    return listHas(mTappedKeys, key);
}

bool KeyboardManager::isKeyReleased(sf::Keyboard::Key key)
{
    return listHas(mReleasedKeys, key);
}

void KeyboardManager::update()
{
    /*
    if (!mPressedKeys.empty()) {
        std::cout << "Pressed keys: ";
        for (auto i = mPressedKeys.begin(); i != mPressedKeys.end(); i++) {
            std::cout << *i << " ";
        }
        std::cout << std::endl;
    }
     */
    
    // clear key release list
    mReleasedKeys.clear();
    
    // update lists
    for (int i = 0; i < _keyCount; i++) {
        const sf::Keyboard::Key &key = _keys[i];
        if (sf::Keyboard::isKeyPressed(key)) {  // key is pressed
            if (listHas(mTappedKeys, key)) { // if key was a tap
                mTappedKeys.remove(key);    // no longer a tap
                mPressedKeys.push_back(key);    // is now a press
            } else if (!listHas(mPressedKeys, key)) {   // if key not a press
                mTappedKeys.push_back(key); // is now a tap
            }
        } else {    // key is not being pressed
            if (listHas(mTappedKeys, key)) {
                // if key was tapped
                mTappedKeys.remove(key);    // no longer tapped
                mReleasedKeys.push_back(key);   // is now released
            } else if (listHas(mPressedKeys, key)) {
                // if key was pressed
                mPressedKeys.remove(key);   // is no longer pressed
                mReleasedKeys.push_back(key);   // is now released
            }
        }
    }
}

KeyboardManager::KeyboardManager() {}
