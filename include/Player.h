#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Gun.h"

class Player
{
    public:
		
//Player1();
    //Player(std::string nomArme, int degatsArme);
  //  ~Player();


		SDL_Surface* player_img;
SDL_Surface* missile_player;
SDL_Rect pos_item_1;
SDL_Rect pos_item_2;
SDL_Rect pos_item_3;
SDL_Rect pos_player;
Gun weapon1;
bool	shoot;
SDL_Surface* screen;
Player();
Player(SDL_Surface* Screen,SDL_Surface* missile_img,SDL_Surface* player_avatar);

    bool spawn_missile()
    {
		shoot = true;
		return (shoot);
    }
    void onClose()
    {
		if (player_img != NULL) {
			SDL_FreeSurface(player_img);
		}

    }
	void update() {};
};

#endif