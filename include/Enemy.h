#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>

class Enemy
{
    public:
		
SDL_Surface* img;
SDL_Surface* healthbar;
SDL_Rect pos;
SDL_Rect healthpos;
SDL_Surface* screen_enemy;
int health;


Enemy();
Enemy::Enemy(SDL_Surface* Screen, int id, SDL_Rect sentpos);

void onClose(){};

void	updateEnemy(){
		if ((screen_enemy != NULL) && (img != NULL)) {
				SDL_BlitSurface( img, NULL, screen_enemy, &pos );
			if (healthbar != NULL)
					SDL_BlitSurface( healthbar, NULL, screen_enemy, &healthpos );
		}


	};


SDL_Surface* loadSurface_enemy( std::string path, SDL_Surface*	screen )
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