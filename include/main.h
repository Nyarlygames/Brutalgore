#ifndef MAIN_H
#define MAIN_H
#include "Player.h"
#include "Gun.h"
#include "MainMenu.h"
#include "Game.h"
#include "Missile.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "Settings.h"

int SCREEN_WIDTH = 1;
int SCREEN_HEIGHT = 1;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* background = NULL;
Game GameObj;
MainMenu MenuObj;
TTF_Font *font = NULL;
Mix_Music*	mus = NULL;
int stateMain = 1;
SDL_Color textColor = { 255, 255, 255 };
SDL_Rect *testrec;
Settings set;

extern SDL_Surface* loadSurface_main( std::string path, SDL_Surface*	screen )
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}
bool init();
void createCfg();
bool loadCfg(char *filename);
bool loadMedia();
void close();
int main( int argc, char* args[] );

#endif