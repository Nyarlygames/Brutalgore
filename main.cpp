#define _CRT_SECURE_NO_WARNINGS

#include "include/Player.h"
#include "include/Gun.h"
#include "include/MainMenu.h"
#include "include/Game.h"
#include "include/Missile.h"
#include "include/main.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <cstring>
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 50;
const char* const DELIMITER = " ";

void createCfg() {
  ofstream defaultCfg ("options.bgo",ofstream::binary);
  defaultCfg <<"width 1920" << endl;
  defaultCfg <<"height 1080" << endl;
  defaultCfg.close();
  printf("created default cfg \n");
}

bool loadCfg(char	*filename) {
		// create a file-reading object
	ifstream fin;
	fin.open(filename); // open a file
	if (!fin.good()) {
		createCfg();
		return false; 
	}
  
	while (!fin.eof())
	{
		char buf[MAX_CHARS_PER_LINE];
		fin.getline(buf, MAX_CHARS_PER_LINE);
    
		int n = 0; // a for-loop index
    
		// array to store memory addresses of the tokens in buf
		const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0

		// parse the line
		token[0] = strtok(buf, DELIMITER); // first token
		if (token[0]) // zero if line is blank
		{
			for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
			{
				token[n] = strtok(0, DELIMITER); // subsequent tokens
				if (!token[n]) {
						break;
				}// no more tokens
			}
		}
		
		if (n>0){
			if (strcmp(token[0], "width") == 0){
				SCREEN_WIDTH = atoi(token[1]);
			}
			else if (strcmp(token[0], "height") == 0){
				SCREEN_HEIGHT = atoi(token[1]);
			}
		}
			
	}
	fin.close();
	return (true);

}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		if( SDL_Init(SDL_INIT_AUDIO) < 0 ) exit(1);
		Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);

		if (TTF_Init() == -1)
		{
			printf ("TTF failed");
		}
		else
		{
			font = TTF_OpenFont( "lazy.ttf", 28 );
		}

		if (loadCfg("options.bgo") == false){
			printf ("failed to load opt, created default, retry \n");
			if (loadCfg("options.bgo") == true) {
				printf("cfg loaded\n");
			}
			else {
				printf("cfgload failed\n");
			}
		}

		gWindow = SDL_CreateWindow( "BrutalGore", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if( !( IMG_Init( imgFlags ) & imgFlags ) )
			{
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface( gWindow );
			}
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true;

	mus = Mix_LoadMUS("mus/test3.mp3");
	if( mus == NULL )
	{
	//	Mix_PlayMusic(mus,1);
		success = false;
	}

	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	
    Mix_FreeMusic( mus );
    Mix_CloseAudio();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}



int main( int argc, char* args[] )
{
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			GameObj = Game(gScreenSurface, gWindow);
			MenuObj = MainMenu(gScreenSurface);
			stateMain=0;
			//Mix_PlayMusic(mus,1); //Music loop=1

			bool quit = false;
			SDL_Event e;
			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					switch (e.type) {
						case SDL_QUIT :
							quit = true;
							break;
						case SDL_KEYDOWN :
							MenuObj.Player1.player_controls(e);
							switch (e.type) {
								case SDL_QUIT :
									quit = true;
									break;
								case SDL_KEYDOWN :
									switch( e.key.keysym.sym ){
										case SDLK_ESCAPE:
											quit=true;
											break;
										default:
											break;
									}
							}
						case (SDL_MOUSEBUTTONDOWN):
							MenuObj.Player1.player_controls(e);
							switch (e.button.button) {
								case SDL_BUTTON_LEFT: 
								   //printf("click");
								  break;
							   case SDL_BUTTON_RIGHT: 
								   //printf("clickdroit");
								  // GameObj.state = 2;
							   break;
							}
					}
				}

				switch(stateMain) {
				case 0:
					//main menu
					if (MenuObj.state == 1)
						MenuObj.updateMenu();
					else if (MenuObj.state == -1)
						quit = true;
					else
						stateMain = MenuObj.state;
					break;
				case 1:
					GameObj.updateGame();
					//game loop
					break;
				case 2:
					//
					break;
				}

				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}
	close();

	return 0;
}