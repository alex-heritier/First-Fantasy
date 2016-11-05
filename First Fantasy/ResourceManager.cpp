//
//  ResourceManager.cpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "ResourceManager.hpp"
#include "ResourcePath.hpp"

namespace ff {
    
    ResourceManager::ResourceManager()
    {
        // load textures
        mTextures["splashImg"] = sf::Texture();
        mTextures["splashImg"].loadFromFile(resourcePath() + "nintendo_splash.png");
        
        mTextures["mainMenuBG"] = sf::Texture();
        mTextures["mainMenuBG"].loadFromFile(resourcePath() + "main_menu.jpg");
        
        mTextures["worldMapBG"] = sf::Texture();
        mTextures["worldMapBG"].loadFromFile(resourcePath() + "world_map.jpg");
        
        // load fonts
        mFonts["introFont"] = sf::Font();
        mFonts["introFont"].loadFromFile(resourcePath() + "sansation.ttf");
        
        // load sounds
        mSounds["splashSound"] = sf::SoundBuffer();
        mSounds["splashSound"].loadFromFile(resourcePath() + "gameboy_start_up.wav");
        
        mSounds["battleWin"] = sf::SoundBuffer();
        mSounds["battleWin"].loadFromFile(resourcePath() + "victory.wav");
        
        mSounds["GSFirstBook"] = sf::SoundBuffer();
        mSounds["GSFirstBook"].loadFromFile(resourcePath() + "golden_sun.wav");
    }
    
    sf::Texture &ResourceManager::getTexture(std::string key)
    {
        return mTextures[key];
    }
    
    sf::Font &ResourceManager::getFont(std::string key)
    {
        return mFonts[key];
    }
    
    sf::SoundBuffer &ResourceManager::getSound(std::string key)
    {
        return mSounds[key];
    }
}
