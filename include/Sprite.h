#ifndef Sprite_H
#define Sprite_H

#include <string>
#include <sstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
//The surface contained by the window

namespace Sprite
{
    class Sprite
    {
    public:
		SDL_Surface* loadSurface( std::string path, SDL_Surface*	screen ) {};
	};
} 

#endif