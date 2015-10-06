#ifndef DEF_MAINMENU
#define DEF_MAINMENU

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>



SDL_Surface* loadMenuPic( std::string path, SDL_Surface*	screen );
void updateMenu(SDL_Surface*	screen);
void	setMenu(SDL_Surface	*screen);

#endif