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
int hp;
int speedX;
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
	for (int  i = nb_missiles; i>=0; i--) {
		if (missiles[i] != NULL){
			SDL_FreeSurface(missiles[i]);}
	}

    }
	void update() {

							if (shoot == true){
					//for (int i=0; i<nb_missiles; i++) {
						//int i = 0;
						for (int i=0; i<nb_missiles; i++) {
						if (missiles[i] != NULL) {
							SDL_BlitSurface(missiles[i], NULL, screen, &spawn_missiles[i] );
							if (missile_player == NULL){
								printf("can't display missile from player");
							}
							//SDL_BlitSurface(player1.missile_player, NULL, gScreenSurface2, &player1.pos_playerX );
						if (dest_missiles[i].x <spawn_missiles[i].x)
							spawn_missiles[i].x--;
						if (dest_missiles[i].x > spawn_missiles[i].x)
							spawn_missiles[i].x++;
						if (dest_missiles[i].y <spawn_missiles[i].y)
							spawn_missiles[i].y--;
						if (dest_missiles[i].y > spawn_missiles[i].y)
							spawn_missiles[i].y++;
						}
					}
				}
							SDL_BlitSurface(player_img, NULL, screen, &pos_playerX );
							

	}
	/*
	if (SDL_PollEvent( &e ) != 0){
		switch (e.type) {
						case SDL_KEYDOWN :
							//User requests quit
							switch (e.type) {
								case SDL_KEYDOWN :
									switch( e.key.keysym.sym ){
										case SDLK_LEFT:
											pos_playerX.x -=10 * speedX;
											break;
										case SDLK_RIGHT:
											pos_playerX.x +=10 * speedX;
											break;
										case SDLK_UP:
											pos_playerX.y -=10;
											break;
										case SDLK_DOWN:
											pos_playerX.y +=10;
											break;
										default:
											break;
									}
							}
						case (SDL_MOUSEBUTTONDOWN):
							  // If the left button was pressed. 
						   switch (e.button.button) {
						   case SDL_BUTTON_LEFT: 
							   printf("click");
							   shoot = true;
										spawn_missileX();
							   break;
						   }
		}

	}*/
							//update_pos();
	
	/*
void update_pos() {
	SDL_Event e;
	bool quit = false;
			while( !quit )
			{
while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					switch (e.type) {
						case SDL_QUIT :
								quit = true;
							break;
						case SDL_KEYDOWN :
							//User requests quit
							switch (e.type) {
								case SDL_QUIT :
										quit = true;
									break;
								case SDL_KEYDOWN :
									switch( e.key.keysym.sym ){
										case SDLK_LEFT:
											pos_playerX.x -=20 * speedX;
											break;
										case SDLK_RIGHT:
											pos_playerX.x +=20 * speedX;
											break;
										case SDLK_UP:
											pos_playerX.y -=20 * speedX;
											break;
										case SDLK_DOWN:
											pos_playerX.y +=20 *speedX;
											break;
										case SDLK_ESCAPE:
											quit=true;
											break;
										default:
											break;
									}
							}
						case (SDL_MOUSEBUTTONDOWN):
							  // If the left button was pressed. 
						   switch (e.button.button) {
						   case SDL_BUTTON_LEFT: 
							   printf("click");
							   shoot = true;
										spawn_missileX();
							   break;
								}

					}
}
			}};*/
};


#endif