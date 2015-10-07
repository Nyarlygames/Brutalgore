#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>
#include <iostream>
#include "Player.h"
#include "MainMenu.h"
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Game
{
    public:
		

Game();
Player PlayerGame;
MainMenu	Root;
int state;
Game(SDL_Surface*	Screen);

    void onClose()
    {
    }
	
void updateGame() {
	Root.updateMenu();
}
	
SDL_Surface* loadSurface_player( std::string path, SDL_Surface*	screen )
{
}

	/*void	player_controls(SDL_Keycode e){
	
			
								switch( e ){

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
	}*/
	
};


#endif