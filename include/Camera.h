#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <sstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Settings.h"
#include "Player.h"

using namespace std;

class Camera
{
    public:
Settings opts;
SDL_Rect camsize;
SDL_Rect minimapsize;
SDL_Rect gamesize;
SDL_Surface *camsurf;
SDL_Surface *gamesurf;
Player		*players;

Camera();
Camera(Settings opt, SDL_Rect cam, SDL_Rect game, SDL_Surface	*gameview, SDL_Surface	*camview, Player	*gamers);

void updateCamera()
{

	// offset from player from half cam size
	// blocks movement at maximum width/height - camsize

	gamesize.x = players[0].pos_player.x;
	gamesize.y = players[0].pos_player.y;

	/*switch( e.key.keysym.sym ){
		case SDLK_LEFT:
			if (players[0].pos_player.x - gamesize.w/2 >= 0)
				gamesize.x = players[0].pos_player.x - gamesize.w/2;
			break;
		case SDLK_RIGHT:
			if (players[0].pos_player.x + gamesize.w/2 <= gamesurf->w){
				gamesize.x = players[0].pos_player.x - gamesize.w/2;
			}
			break;
		case SDLK_UP:
			if (players[0].pos_player.y - gamesize.h/2 >= 0)
				gamesize.y = players[0].pos_player.y - gamesize.h/2;
			break;
		case SDLK_DOWN:
			if (players[0].pos_player.y + gamesize.h/2 <= gamesurf->h){
				gamesize.y = players[0].pos_player.y - gamesize.h/2;
			}
			break;
		case SDLK_f:
			gamesize.w += 20;
			gamesize.h += 20;
			break;
		case SDLK_r:
			gamesize.w -= 20;
			gamesize.h -= 20;
			break;
		default:
			break;
	}*/
}
	
};
							
#endif