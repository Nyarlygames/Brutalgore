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

Game::Game() {}
Game::Game(SDL_Surface*	Screen, SDL_Window *window){
	state = 0;
	screenGame = Screen;
	windows_game = window;
}