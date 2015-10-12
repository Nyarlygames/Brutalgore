#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Gun.h"
#include "include/Player.h"
#include "include/Game.h"
#include "include/MainMenu.h"
//#include "PlayerController.h";
using namespace std;

SDL_Surface*	screenGame;
SDL_Rect pos_player_base;
Game::Game() 
{
}
Game::Game(SDL_Surface*	Screen, SDL_Window *window){
	

	pos_player_base.x = 50;
	pos_player_base.y = 600;
	state = 1;
	PlayerGame = Player(Screen, pos_player_base,1);
	screenGame = Screen;
	/*Root = MainMenu(Screen);
	PlayerGame = Root.Player1;*/
	windows_game = window;
}