#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Missile.h"
//#include "PlayerController.h";
using namespace std;

Missile::Missile() 
{
}
Missile::Missile(SDL_Surface*	Screen, int id, SDL_Rect pos_player){
	
	
	pos_missile = pos_player;
	screen_missile = Screen;
	
 
 switch (id) {
 case 1 :
	img_missile = loadSurface_missile( "img\\missile1.png", Screen );
	if( img_missile == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 case 2:
	img_missile = loadSurface_missile( "img\\missile2.png", Screen );
	if( img_missile == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 case 3:
	img_missile = loadSurface_missile( "img\\missile3.png", Screen );
	if( img_missile == NULL )
	{
		printf( "Failed to load PNG image!\n", Screen );
	}
	break;
 }
}