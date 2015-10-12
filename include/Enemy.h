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
		
SDL_Surface* img_enemy;
SDL_Surface* img_enemy_dead;
SDL_Surface* healthbar;
SDL_Surface* hpbar;
SDL_Rect pos_enemy;
SDL_Rect healthpos;
SDL_Surface* screen_enemy;
int health;
int id;
int basehealth;
int state;
SDL_Rect fillbar;

Enemy();
Enemy::Enemy(SDL_Surface* Screen, int createid, SDL_Rect sentpos, int basehealth);

void onClose(){};

void updateEnemy(){
	if ((screen_enemy != NULL) && (img_enemy != NULL)) {
		if (state == 1) {
			SDL_BlitSurface( img_enemy, NULL, screen_enemy, &pos_enemy );
		}
		else {
			SDL_BlitSurface( img_enemy_dead, NULL, screen_enemy, &pos_enemy );
		}
		if ((health != basehealth) && (state == 1)) {
			fillbar.w = (health * img_enemy->w) / basehealth;
			hpbar = SDL_CreateRGBSurface(0, img_enemy->w - fillbar.w, 10, 32, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
			SDL_FillRect(hpbar, NULL, SDL_MapRGB(hpbar->format, 255, 255, 255));
			SDL_BlitSurface( healthbar, NULL, screen_enemy, &healthpos );
			SDL_BlitSurface( hpbar, NULL, screen_enemy, &healthpos );

		}
		else if ((state == 0) || (health <= 0)) {
			healthbar = SDL_CreateRGBSurface(0, img_enemy_dead->w, 10, 32, 0, 0, 0, 0);
			SDL_FillRect(healthbar, NULL, SDL_MapRGB(healthbar->format, 255, 255, 0));
			SDL_BlitSurface( healthbar, NULL, screen_enemy, &healthpos );
		}
		else {
			SDL_BlitSurface( healthbar, NULL, screen_enemy, &healthpos );
		}
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