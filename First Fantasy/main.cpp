
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "GameEngine.hpp"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int argc, char const **argv)
{
    ff::GameEngine gameEngine;
    return gameEngine.run();
}
