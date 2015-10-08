#include "init_sdl_devices.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

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
		// Inilialize SDL_mixer , exit if fail
if( SDL_Init(SDL_INIT_AUDIO) < 0 ) exit(1);
// Setup audio mode
Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);
///ix_Music *mus , *mus2 ;  // Background Music 
//Mix_Chunk *wav , *wav2 ;  // For Sounds
//mus = Mix_LoadMUS("./mixer/ff2prlde.mid");
//wav = Mix_LoadWAV("./mixer/po_p2k.wav");
//wav2 = Mix_LoadWAV("./mixer/start.wav");

		//Create window
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
			pos_item_1.x = 0;
			pos_item_1.y = 0;
			pos_item_2.x = 300;
			pos_item_2.y = 400;
			pos_item_3.x = 600;
			pos_item_3.y = 800;
			pos_player.x = 500;
			pos_player.y = 100;
		}
	}

	return success;
}