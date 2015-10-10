/*#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
class PlayerController
{
    public:
		
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
										quit = true;									break;
								case SDL_KEYDOWN :
									switch( e.key.keysym.sym ){
										case SDLK_LEFT:
											player.pos_playerX.x -=20 * player.speedX;
											break;
										case SDLK_RIGHT:
											player.pos_playerX.x +=20 * player.speedX;
											break;
										case SDLK_UP:
											player.pos_playerX.y -=20 * player.speedX;
											break;
										case SDLK_DOWN:
											player.pos_playerX.y +=20 *player.speedX;
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
							   player.shoot = true;
										player.spawn_missileX();
							   break;
								}

					}
}
}
}
#endif*/