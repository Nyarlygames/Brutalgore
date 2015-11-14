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
#include "Settings.h"
//#include "PlayerController.h";
using namespace std;

Game::Game() {}
Game::Game(SDL_Surface*	Screen, SDL_Window *window, Settings s){
	state = 0;
	windows_game = window;
	set = s;
	hidden_window = SDL_CreateWindow( "Hiddendisplay", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, set.width, set.height, SDL_WINDOW_HIDDEN );
	screenGame = SDL_GetWindowSurface( hidden_window );;
	Camerasurf = Screen;
}