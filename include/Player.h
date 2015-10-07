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
SDL_Rect pos_player;
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
Player(SDL_Surface* Screen,SDL_Rect pos_player, int playerid);

    bool spawn_missileX()
    {/*
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
			missiles[nb_missiles] = missile;



				printf("2");



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
		*/

    }
    void onClose()
    {
		if (player_img != NULL) {
			SDL_FreeSurface(player_img);
		}
	for (int  i = nb_missiles; i>0; i--) {
		if (missiles[i] != NULL){
			SDL_FreeSurface(missiles[i]);}
	}

    }

	
SDL_Surface* loadSurface_player( std::string path, SDL_Surface*	screen )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}
	void updatePlayer() {

					/*		if (shoot == true){
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
				}*/
							if (player_img != NULL) {
							SDL_BlitSurface(player_img, NULL, screen, &pos_player );
							}

	}

	void	player_controls(SDL_Event e){


		
									switch( e.key.keysym.sym ){
									case SDLK_LEFT:
										pos_player.x -= 20 * speedX;
										break;
									case SDLK_RIGHT:
										pos_player.x += 20 * speedX;
										break;
									case SDLK_UP:
										pos_player.y -= 20 * speedX;
										break;
									case SDLK_DOWN:
										pos_player.y += 20 * speedX;
										break;
										default:
											break;
									}
	}
	
	
};


#endif