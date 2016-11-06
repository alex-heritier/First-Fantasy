//
//  ResourceManager.hpp
//  First Fantasy
//
//  Created by Alex on 10/7/16.
//  Copyright © 2016 Alex Heritier. All rights reserved.
//

#ifndef ResourceManager_hpp
#define ResourceManager_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unordered_map>

namespace ff {
    class ResourceManager {
    public:
        ResourceManager();
        sf::Texture &getTexture(std::string);
        sf::Font &getFont(std::string);
        sf::Image &getImage(std::string);
        sf::SoundBuffer &getSound(std::string);
    private:
        // variables
        std::unordered_map<std::string, sf::Texture> mTextures;
        std::unordered_map<std::string, sf::Font> mFonts;
        std::unordered_map<std::string, sf::Image> mImages;
        std::unordered_map<std::string, sf::SoundBuffer> mSounds;
    };
}

#endif /* ResourceManager_hpp */
