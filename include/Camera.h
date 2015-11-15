#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <sstream>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Settings.h"

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

Camera();
Camera(Settings opt, SDL_Rect cam, SDL_Rect game, SDL_Surface	*gameview, SDL_Surface	*camview);

void updateCamera(SDL_Event e)
{
	/*
							switch( e.key.keysym.sym ){
								case SDLK_ESCAPE:
									quit=true;
									break;
								case SDLK_g:
									stateMain = 1;
									break;
								case SDLK_LEFT:
									if (GameObj.testbg.x >= 10)
										GameObj.testbg.x -=10;
									break;
								case SDLK_RIGHT:
									if (GameObj.testbg.x <= set.width - GameObj.testbg.w - 10){
										GameObj.testbg.x +=10;
									}
									break;
								case SDLK_UP:
									if (GameObj.testbg.y >= 10)
										GameObj.testbg.y -=10;
									break;
								case SDLK_DOWN:
									if (GameObj.testbg.y <= set.height - GameObj.testbg.h - 10){
										GameObj.testbg.y +=10;
									}
									break;
								default:
									break;
							}*/
}
	
};
							
#endif