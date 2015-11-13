#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <sstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Settings
{
    public:
		int width;
		int height;
		Settings();
		Settings(int w, int h);


void updateSettings(SDL_Event e)
{
}
	
};
							
#endif