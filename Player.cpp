#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Gun.h"
#include "include/Player.h"
#include "include/Missile.h"
//#include "PlayerController.h";
using namespace std;

SDL_Surface* player_img;
SDL_Rect pos_player;
Gun weapon1;
bool	shoot = false;
SDL_Surface* screen = NULL;

SDL_Rect spawn_missiles[20];
SDL_Rect dest_missiles[20];
int damages = 1;
int speedX;

Player::Player() 
{
 pos_player.x = 600;
 pos_player.y = 300;
}
  
Player::Player(SDL_Surface* Screen,SDL_Rect pos_playerX, int id) 
{
 nb_missiles = 0;
 nb_missiles_max = 20;
	screen = Screen;
	pos_player = pos_playerX;
 speedX = 10;
 missiles_player = new Missile[nb_missiles_max];

 
 switch (id) {
 case 1 :
	player_img = loadSurface_player( "img\\player1.png", screen );
	if( player_img == NULL )
	{
		printf( "Failed to load PNG image!\n", screen );
	}
	break;
 case 2:
	player_img = loadSurface_player( "img\\player2.png", screen );
	if( player_img == NULL )
	{
		printf( "Failed to load PNG image!\n", screen );
	}
	break;
 case 3:
	player_img = loadSurface_player( "img\\player3.png", screen );
	if( player_img == NULL )
	{
		printf( "Failed to load PNG image!\n", screen );
	}
	break;
 }
}


