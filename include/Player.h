#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Gun.h"
#include "Missile.h"
using namespace std;

class Player
{
    public:
		
SDL_Surface* player_img;
SDL_Rect pos_player;
Gun weapon1;
bool	shoot;
SDL_Surface* screen;
Missile*	missiles_player;
int nb_missiles;
int nb_missiles_max;
int damages;
//Missile*	missiles_player;
//Missile* Missiles;
int hp;
int speedX;
Player();
Player(SDL_Surface* Screen,SDL_Rect pos_player, int playerid);

    void onClose()
    {
		if (player_img != NULL) {
			SDL_FreeSurface(player_img);
		}
	for (int  i = nb_missiles; i>0; i--) {
	//	if (missiles[i] != NULL){
		//	SDL_FreeSurface(missiles[i]);}
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

		if (player_img != NULL) {
			SDL_BlitSurface(player_img, NULL, screen, &pos_player );
		}
		if (nb_missiles >= 1){
			for (int i = 0; i <= nb_missiles-1; i++) {
				missiles_player[i].updateMissile();
			}
		}

	}
	
	void spawn_missile(){
		int xmouse, ymouse;
		SDL_Rect dest_missiles;
	SDL_GetMouseState(&xmouse,&ymouse);	
	dest_missiles.x = xmouse;
	dest_missiles.y = ymouse;
		if (nb_missiles < nb_missiles_max) {
			missiles_player[nb_missiles] = Missile(screen, 1, pos_player,dest_missiles);
			nb_missiles++;
		}
	}
   

	void	player_controls(SDL_Event e){


		
									switch( e.key.keysym.sym ){
									case SDLK_LEFT:
										pos_player.x -= 10 * speedX;
										break;
									case SDLK_RIGHT:
										pos_player.x += 10 * speedX;
										break;
									case SDLK_UP:
										pos_player.y -= 10 * speedX;
										break;
									case SDLK_DOWN:
										pos_player.y += 10 * speedX;
										break;
										default:
											break;
									}
									
					
					switch (e.type) {
					case (SDL_MOUSEBUTTONDOWN):
							  /* If the left button was pressed. */
						   switch (e.button.button) {
						   case SDL_BUTTON_LEFT: 
							  spawn_missile();
							   printf("click");
							   break;
						   case SDL_BUTTON_RIGHT: 
							   printf("clickdroit");
							   break;
								}
					}
	}
	
	
};


#endif