#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Enemy.h"
using namespace std;


SDL_Surface* img_enemy;
SDL_Surface* healthbar;
SDL_Rect healthpos;
SDL_Surface* screen_enemy = NULL;

Enemy::Enemy() 
{
 pos_enemy.x = 0;
 pos_enemy.y = 0;
 state = 1;
}
 
 
Enemy::Enemy(SDL_Surface* Screen, int createid, SDL_Rect sentpos, int starthealth) 
{
 id = createid;
 switch (id) {
 
 case 1 :
	img_enemy = loadSurface_enemy( "img\\menu-exit.png", Screen );
	if( img_enemy == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	img_enemy_dead = loadSurface_enemy( "img\\menu-exit-dead.png", Screen );
	if( img_enemy_dead == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 case 2:
	img_enemy = loadSurface_enemy( "img\\menu-play.png", Screen );
	if( img_enemy == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	img_enemy_dead = loadSurface_enemy( "img\\menu-play-dead.png", Screen );
	if( img_enemy_dead == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 case 3:
	img_enemy = loadSurface_enemy( "img\\menu-options.png", Screen );
	if( img_enemy == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	img_enemy_dead = loadSurface_enemy( "img\\menu-options-dead.png", Screen );
	if( img_enemy_dead == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 }

screen_enemy = Screen;
pos_enemy = sentpos;
health = starthealth;
basehealth = starthealth;
state = 1;
fillbar.w = (health * img_enemy->w) / basehealth;
fillbar.h = 10;
healthpos.x = pos_enemy.x;
healthpos.y = pos_enemy.y -15;
healthbar = SDL_CreateRGBSurface(0, fillbar.w, fillbar.h, 32, 0, 0, 0, 0);

SDL_FillRect(healthbar, NULL, SDL_MapRGB(healthbar->format, 255, 0, 0));

}

void onClose(){
	
	SDL_FreeSurface(img_enemy);
	img_enemy = NULL;

}
