#ifndef MAIN_H
#define MAIN_H
#include "Player.h"
#include "Gun.h"
#include "MainMenu.h"
#include "Game.h"
#include "Missile.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "Settings.h"

int SCREEN_WIDTH = 1;
int SCREEN_HEIGHT = 1;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* background = NULL;
Game GameObj;
MainMenu MenuObj;
TTF_Font *font = NULL;
Mix_Music*	mus = NULL;
int stateMain = 1;
SDL_Color textColor = { 255, 255, 255 };
SDL_Rect *testrec;
Settings set;

bool init();
void createCfg();
bool loadCfg(char *filename);
bool loadMedia();
void close();
int main( int argc, char* args[] );

#endif