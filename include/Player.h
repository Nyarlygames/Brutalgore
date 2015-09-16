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
SDL_Rect pos_playerX;
Gun weapon1;
bool	shoot;
SDL_Surface* screen;
int nb_missiles;
int nb_missiles_max;
int damages;
SDL_Rect spawn_missiles[20];
SDL_Rect dest_missiles[20];
SDL_Surface*	missiles[20];
Player();
Player(SDL_Surface* Screen,SDL_Surface* missile_img,SDL_Surface* player_avatar, SDL_Rect pos_player);

    bool spawn_missileX()
    {
							   printf("click");
		printf("spawn");
		if (shoot == true) {
			if (nb_missiles >= nb_missiles_max - 1){
				printf("max missiles");
				printf("1");
				shoot = false;
				return false;
				//player1.spawn_missile();
			}
			else if (nb_missiles <= nb_missiles_max){
			/*else {
			//missiles[nb_missiles] = loadSurface( "img\\missile.png" );
			if (missile == NULL)
				return false;
			missiles[nb_missiles] = missile;*/



				printf("2");
				/*
					if (player1.shoot == true){
					//for (int i=0; i<nb_missiles; i++) {
						//int i = 0;
						for (int i=0; i<=player1.nb_missiles; i++) {
						if (player1.missiles[i] != NULL) {
							SDL_BlitSurface(player1.missiles[i], NULL, gScreenSurface2, &player1.spawn_missiles[i] );
							if (player1.missile_player == NULL){
								printf("can't display missile from player");
							}
							//SDL_BlitSurface(player1.missile_player, NULL, gScreenSurface2, &player1.pos_playerX );
						if (player1.dest_missiles[i].x <player1.spawn_missiles[i].x)
							player1.spawn_missiles[i].x--;
						if (player1.dest_missiles[i].x > player1.spawn_missiles[i].x)
							player1.spawn_missiles[i].x++;
						if (player1.dest_missiles[i].y <player1.spawn_missiles[i].y)
							player1.spawn_missiles[i].y--;
						if (player1.dest_missiles[i].y > player1.spawn_missiles[i].y)
							player1.spawn_missiles[i].y++;




						}
						*/




			int x,y = -1;
			spawn_missiles[nb_missiles].x = pos_playerX.x;
			spawn_missiles[nb_missiles].y = pos_playerX.y;
			SDL_GetMouseState(&x,&y);	
			dest_missiles[nb_missiles].x = x;
			dest_missiles[nb_missiles].y = y;
			nb_missiles+=1;
			return true;
			}
		}
		else {
			printf("3");
			return (shoot);

		}	
		return true;
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