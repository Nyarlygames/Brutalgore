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

void updateCamera(SDL_Rect fullboard)
{
	if ((gamesize.w + gamesize.x > fullboard.w) || (gamesize.x < 0)){
		if ((players[0].pos_player.x > gamesize.w/2) && (players[0].pos_player.x < fullboard.w - gamesize.w/2))
			gamesize.x = players[0].pos_player.x - gamesize.w/2;
	}
	if ((gamesize.h + gamesize.y > fullboard.h) || (gamesize.y < 0)){
		if ((players[0].pos_player.y > gamesize.h/2) && (players[0].pos_player.y < fullboard.h - gamesize.h/2))
			gamesize.y = players[0].pos_player.y - gamesize.h/2;
	}
	
	if ((gamesize.w + gamesize.x <= fullboard.w) && (gamesize.x >= 0)){
		gamesize.x = players[0].pos_player.x - gamesize.w/2;
	}
	if ((gamesize.h + gamesize.y <= fullboard.h) && (gamesize.y >= 0)){
		gamesize.y = players[0].pos_player.y - gamesize.h/2;
	}
}
	
};
							
#endif