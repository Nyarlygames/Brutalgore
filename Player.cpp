#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Gun.h"
#include "include/Player.h"
//#include "PlayerController.h";
using namespace std;

SDL_Surface* player_img;
SDL_Surface* missile_player;
SDL_Rect pos_player;
Gun weapon1;
bool	shoot = false;
SDL_Surface* screen = NULL;

SDL_Rect spawn_missiles[20];
SDL_Rect dest_missiles[20];
SDL_Surface*	missiles[20];
int nb_missiles = 0;
int nb_missiles_max = 20;
int damages = 1;
int speedX;

Player::Player() 
{
 pos_player.x = 600;
 pos_player.y = 300;
}
  
Player::Player(SDL_Surface* Screen,SDL_Rect pos_playerX, int id) 
{
	screen = Screen;
	missile_player = loadSurface_player( "img\\missile.png", screen );
	pos_playerX = pos_player;
	nb_missiles = 0;
	nb_missiles_max = 20;
	for (int i=0; i<= nb_missiles_max;i++) {
			missiles[i] = missile_player;
	}
	if(missile_player == NULL) {
		printf("missile img not loaded for player");
	}
	pos_player.x = pos_playerX.x;
	pos_player.y = pos_playerX.y;
 speedX = 10;

 
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
