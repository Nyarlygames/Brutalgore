#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "Gun.h";
#include "include/Player.h";
using namespace std;


SDL_Surface* player_img;
SDL_Surface* missile_player;
SDL_Rect pos_playerX;
Gun weapon1;
bool	shoot = false;
SDL_Surface* screen = NULL;

SDL_Rect spawn_missiles[20];
SDL_Rect dest_missiles[20];
SDL_Surface*	missiles[20];
int nb_missiles = 0;
int nb_missiles_max = 20;
int damages = 1;

Player::Player() 
{
 pos_playerX.x = 600;
 pos_playerX.y = 300;
}
 
 
Player::Player(SDL_Surface* Screen,SDL_Surface* missile_img,SDL_Surface* player_avatar, SDL_Rect pos_player) 
{
	screen = Screen;
	missile_player = missile_img;
	player_img = player_avatar;
	pos_playerX = pos_player;
	nb_missiles = 0;
	nb_missiles_max = 20;
	for (int i=0; i<= nb_missiles_max;i++) {
			missiles[i] = missile_img;
	}
	if(player_img == NULL) {
		printf("player img not loaded");
	}
	if(player_avatar == NULL) {
		printf("player img not sent");
	}
	if(missile_player == NULL) {
		printf("missile img not loaded for player");
	}
 pos_player.x = 600;
 pos_player.y = 300;
 }

    void onClose()
    {
		if (player_img != NULL) {
			SDL_FreeSurface(player_img);
		}
    }