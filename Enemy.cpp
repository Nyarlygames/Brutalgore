#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Enemy.h"
using namespace std;


SDL_Surface* img;
SDL_Surface* healthbar;
SDL_Rect pos;
SDL_Rect healthpos;
SDL_Surface* screen_enemy = NULL;
int health = 0;

Enemy::Enemy() 
{
 pos.x = 0;
 pos.y = 0;
}
 
 
Enemy::Enemy(SDL_Surface* Screen, int id, SDL_Rect sentpos) 
{
 
 switch (id) {
 
 case 1 :
	img = loadSurface_enemy( "img\\menu-exit.png", Screen );
	if( img == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 case 2:
	img = loadSurface_enemy( "img\\menu-play.png", Screen );
	if( img == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 case 3:
	img = loadSurface_enemy( "img\\menu-options.png", Screen );
	if( img == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 }

screen_enemy = Screen;
pos = sentpos;

healthpos.x = pos.x;
healthpos.y = pos.y -15;
healthbar = SDL_CreateRGBSurface(0, img->w, 10, 32, 0, 0, 0, 0);

SDL_FillRect(healthbar, NULL, SDL_MapRGB(healthbar->format, 255, 0, 0));

}

void onClose(){
	
	SDL_FreeSurface(img);
	img = NULL;

}
