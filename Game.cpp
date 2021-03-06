#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Gun.h"
#include "include/Player.h"
#include "include/Camera.h"
#include "include/Game.h"
#include "include/MainMenu.h"
#include "Settings.h"
using namespace std;

Game::Game() {}
Game::Game(SDL_Surface*	Screen, SDL_Window *window, Settings s){
	state = 0;
	windows_game = window;
	set = s;
	mainscreen = Screen;
	setGame(1, s.height, s.width);
}

