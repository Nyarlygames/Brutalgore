#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Settings.h"
using namespace std;

Settings::Settings() 
{
}
Settings::Settings(int w, int h){
	width = w;
	height = h;
}