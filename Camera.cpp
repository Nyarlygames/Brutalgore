#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Camera.h"
#include "include/Settings.h"
using namespace std;

Camera::Camera() 
{
}
Camera::Camera(Settings opt, int x, int y, int posx, int posy, int maxtilex, int maxtiley){
	opts = opt;
	nbtilesx = x;
	nbtilesy = y;
	pos.x = posx;
	pos.y = posy;
	tiles.w = opt.width/maxtilex;
	tiles.h = opt.height/maxtiley;
	pos.w = nbtilesx * tiles.w;
	pos.h = nbtilesy * tiles.h;
			//		printf("Width cam : %i, Height cam : %i, Tilew : %i, Tileh : %i, nbtilesx : %i, nbtilesy : %i \n",pos.w, pos.h, tiles.w, tiles.h, nbtilesx, nbtilesy);
}