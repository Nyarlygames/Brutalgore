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
SDL_Rect pos_item_1X;
SDL_Rect pos_item_2X;
SDL_Rect pos_item_3X;
SDL_Rect pos_playerX;
Gun weapon1;
bool	shoot = false;
SDL_Surface* screen = NULL;

Player::Player() 
{
 pos_player.x = 600;
 pos_player.y = 300;
}
 
 
Player::Player(SDL_Surface* Screen,SDL_Surface* missile_img,SDL_Surface* player_avatar) 
{
	Screen = screen;
	missile_player = missile_img;
	player_img = player_avatar;
	if(player_img == NULL) {
		printf("penis");
	}
	if(player_avatar == NULL) {
		printf("double");
	}
	SDL_Delay(4000);
	if(missile_player == NULL) {
		printf("lolilol");
	}
	SDL_Delay(4000);
 pos_player.x = 600;
 pos_player.y = 300;
 }

    // Méthodes
    bool spawn_missileX()
    {
		if (shoot == true) {

			return (shoot);
		}
		else {
			shoot = true;
			return (shoot);

		}

	
    }
    void onClose()
    {
		if (player_img != NULL) {
			SDL_FreeSurface(player_img);
		}
    }
	void update(){
	}
