#ifndef MISSILE_H
#define MISSILE_H

#include <string>
#include <sstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Missile
{
    public:
//Player Player_miss;
SDL_Surface*	screen_missile;
SDL_Rect	pos_missile;
SDL_Surface*	img_missile;
		

Missile();
Missile(SDL_Surface*	Screen, int id, SDL_Rect pos_player);
void updateMissile()
{
	SDL_BlitSurface(img_missile, NULL,screen_missile , &pos_missile );
}
	
SDL_Surface* loadSurface_missile( std::string path, SDL_Surface*	screen )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}
	
};
							
#endif