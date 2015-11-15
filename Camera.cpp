#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Camera.h"
#include "include/Settings.h"
#include "include/Player.h"
using namespace std;

Camera::Camera() 
{
}

Camera::Camera(Settings opt, SDL_Rect cam, SDL_Rect game, SDL_Surface	*gameview, SDL_Surface	*camview, Player	*gamers){
	opts = opt;
	camsize = cam;
	players = gamers;
	gamesize = game;
	gamesurf = gameview;
	camsurf = camview;
	minimapsize.w = 200;
	minimapsize.h = 200;
	minimapsize.x = 20;
	minimapsize.y = opts.height - minimapsize.h - 20;
}