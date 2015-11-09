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
SDL_Rect pos;
SDL_Rect nbtiles;
int nbtilesx, nbtilesy;
Settings opts;
SDL_Rect tiles;
SDL_Surface *camview;

Camera();
Camera(Settings opt, int x, int y, int posx, int posy, int maxtilex, int maxtiley);

void updateCamera(SDL_Event e)
{
	switch (e.type) {
		case SDL_KEYDOWN :
			switch( e.key.keysym.sym ){
				case SDLK_LEFT:
					if (pos.x > 10) {
						printf("POSX2 %i \n", pos.x);
						pos.x -= 10 * 2;
					}
					else (pos.x = 0);
					break;
				case SDLK_RIGHT:
					if (pos.x + pos.w < 1900) {
						printf("POSX %i \n", pos.x + pos.w);
						pos.x += 10 * 2;
					}
					else (pos.x = 1920);
					break;
				case SDLK_UP:
					if (pos.y > 10) {
						printf("POSY2 %i\n", pos.y);
						pos.y -= 10 * 2;
					}
					else (pos.y = 0);
					break;
				case SDLK_DOWN:
					if (pos.y + pos.h < 1060) {
						printf("POSY %i\n", pos.y + pos.h );
						pos.y += 10 * 2;
					}
					else (pos.y = 1080);
					break;
				default:
					printf("test");
					break;
			}
	}

}
	
};
							
#endif