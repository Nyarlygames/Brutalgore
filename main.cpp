/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include "Player.h"
#include "Gun.h"
#include "include/Gun.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
//#include "include\Toolbox.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1680;
const int SCREEN_HEIGHT = 1050;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	

//Current displayed PNG image
SDL_Surface* gScreenSurface2 = NULL;
SDL_Surface* background = NULL;
SDL_Surface* menu_item_1 = NULL;
SDL_Surface* menu_item_2 = NULL;
SDL_Surface* menu_item_3 = NULL;
SDL_Surface* player_pic = NULL;
SDL_Surface* player2_pic = NULL;
SDL_Surface* player3_pic = NULL;
SDL_Surface* missile = NULL;
SDL_Surface* gun1 = NULL;
SDL_Surface* gun2 = NULL;
SDL_Rect pos_item_1;
SDL_Rect pos_item_2;
SDL_Rect pos_item_3;
SDL_Rect pos_player;
SDL_Rect player1_pos;
SDL_Rect message_1;
Player player1;
Player player2;
Player player3;
Gun weap2;

TTF_Font *font = NULL;
SDL_Surface *message = NULL;
std::stringstream stuff;

Mix_Music*	mus = NULL;
int speed = 1;
int hpmenu1 = 5;
int hpmenu2 = 2;
int hpmenu3 = 1;
int hpplayer = 5;
SDL_Color textColor = { 255, 255, 255 };

void missile_die(SDL_Surface*	missile) {

}

SDL_Surface* loadSurface2( std::string path, SDL_Surface*	screen )
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface2->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

void missile_hit(SDL_Surface*	target, SDL_Surface*	missile) {
//	stuff.pop
	if (target == menu_item_3) {
		hpmenu3 -= player1.damages;
		if (hpmenu3 == 0) {
		SDL_FreeSurface(menu_item_3);
		menu_item_3 = NULL;
		menu_item_3 = loadSurface2( "img\\menu-exit-dead.png", gScreenSurface2);
		}
	}
	if (target == menu_item_2) {
		hpmenu2 -= player1.damages;
		if (hpmenu2 == 0) {
		SDL_FreeSurface(menu_item_2);
		menu_item_2 = NULL;
		menu_item_2 = loadSurface2( "img\\menu-options-dead.png", gScreenSurface2 );
		}
	}
	if (target == menu_item_1) {
		hpmenu1 -= 5;
		if (hpmenu1 == 0) {
		SDL_FreeSurface(menu_item_1);
		menu_item_1 = NULL;
		menu_item_1 = loadSurface2( "img\\menu-play-dead.png", gScreenSurface2 );
		}
	}
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
		// Inilialize SDL_mixer , exit if fail
if( SDL_Init(SDL_INIT_AUDIO) < 0 ) exit(1);
// Setup audio mode
Mix_OpenAudio(22050,AUDIO_S16SYS,2,640);
///ix_Music *mus , *mus2 ;  // Background Music 
//Mix_Chunk *wav , *wav2 ;  // For Sounds
//mus = Mix_LoadMUS("./mixer/ff2prlde.mid");
//wav = Mix_LoadWAV("./mixer/po_p2k.wav");
//wav2 = Mix_LoadWAV("./mixer/start.wav");

if (TTF_Init() == -1)
{
	printf ("TTF failed");
}
else
{
    font = TTF_OpenFont( "lazy.ttf", 28 );
	if (font != NULL) {
		printf("font loaded");
		stuff << "Test : " << hpmenu1;
		message = TTF_RenderText_Solid( font, stuff.str().c_str(), textColor );
	}
}


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
				gScreenSurface2 = SDL_GetWindowSurface( gWindow );
			}
			pos_item_1.x = 0;
			pos_item_1.y = 0;
			message_1.x = 0;
			message_1.y = 0;
			pos_item_2.x = 300;
			pos_item_2.y = 400;
			pos_item_3.x = 600;
			pos_item_3.y = 800;
			weap2.pos_gun.x = 20;
			weap2.pos_gun.x = 20;
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
mus = Mix_LoadMUS("mus/test3.mp3");
		if( mus == NULL )
	{
	//	Mix_PlayMusic(mus,1);
		success = false;
	}
	//Load PNG surface
	background = loadSurface2( "img\\background.png" , gScreenSurface2);
	if( background == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	menu_item_1 = loadSurface2( "img\\menu-play.png", gScreenSurface2 );
	if( menu_item_1 == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	menu_item_2 = loadSurface2( "img\\menu-options.png", gScreenSurface2 );
	if( menu_item_2 == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	menu_item_3 = loadSurface2( "img\\menu-exit.png", gScreenSurface2 );
	if( menu_item_2 == NULL )
	{
		printf( "Failed to load PNG image!\n", gScreenSurface2 );
		success = false;
	}
	player_pic = loadSurface2( "img\\player1.png", gScreenSurface2 );
	if( player_pic == NULL )
	{
		printf( "Failed to load PNG image!\n", gScreenSurface2 );
		success = false;
	}
	player2_pic = loadSurface2( "img\\player2.png", gScreenSurface2 );
	if( player2_pic == NULL )
	{
		printf( "Failed to load PNG image!\n", gScreenSurface2 );
		success = false;
	}
	player3_pic = loadSurface2( "img\\player3.png", gScreenSurface2 );
	if( player3_pic == NULL )
	{
		printf( "Failed to load PNG image!\n", gScreenSurface2 );
		success = false;
	}
	missile = loadSurface2( "img\\missile.png", gScreenSurface2 );
	if ( missile == NULL )
	{
		printf( "Failed to load PNG image!\n" , gScreenSurface2);
		success = false;
	}
	gun1 = loadSurface2( "img\\gun1.png", gScreenSurface2 );
		if ( gun1 == NULL )
	{
		printf( "Failed to load PNG image!\n", gScreenSurface2 );
		success = false;
	}
	gun2 = loadSurface2( "img\\gun2.png", gScreenSurface2 );
		if ( gun2 == NULL )
	{
		printf( "Failed to load PNG image!\n", gScreenSurface2 );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface( background );
	background = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	
	SDL_FreeSurface(background);
	background = NULL;
	
	SDL_FreeSurface(menu_item_1);
	menu_item_1 = NULL;
	SDL_FreeSurface(menu_item_2);
	menu_item_2 = NULL;
	SDL_FreeSurface(menu_item_3);
	menu_item_3 = NULL;
		player1.onClose();
		player2.onClose();
		player3.onClose();
	// CLEAN MISSILES HERE
//SDL_FreeSurface(missile);
	//missile = NULL;
    Mix_FreeMusic( mus );
    Mix_CloseAudio();
    Mix_CloseAudio();

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


//bool isinside(SDL_Rect* target, 


int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			if (player_pic == NULL){
				printf("null playerpic before loading player");
			}
			SDL_Rect p1_pos, p2_pos, p3_pos, p4_pos;
			p1_pos.x = 100;
			p1_pos.y = 300;
			player1 = Player(gScreenSurface2, missile, player_pic, p1_pos);
			p2_pos.x = 50;
			p2_pos.y = 20;
			player2 = Player(gScreenSurface2, missile, player2_pic, p2_pos);
			p3_pos.x = 800;
			p3_pos.y = 700;
			player3 = Player(gScreenSurface2, missile, player3_pic, p3_pos);
			weap2.gun = gun2;



//Mix_PlayMusic(mus,1); //Music loop=1
			//Main loop flag
			bool quit = false;
			bool shoot = false;
			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
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
										quit = true;
									break;
								case SDL_KEYDOWN :
									switch( e.key.keysym.sym ){
										case SDLK_LEFT:
											player1.pos_playerX.x -= 20 * player1.speedX;
											player2.pos_playerX.x -= 20 * player2.speedX;
											player3.pos_playerX.x -= 20 * player3.speedX;
											break;
										case SDLK_RIGHT:
											player1.pos_playerX.x += 20 * player1.speedX;
											player2.pos_playerX.x += 20 * player2.speedX;
											player3.pos_playerX.x += 20 * player3.speedX;
											break;
										case SDLK_UP:
											player1.pos_playerX.y -= 20 * player1.speedX;
											player2.pos_playerX.y -= 20 * player2.speedX;
											player3.pos_playerX.y -= 20 * player3.speedX;
											break;
										case SDLK_DOWN:
											player1.pos_playerX.y += 20 * player1.speedX;
											player2.pos_playerX.y += 20 * player2.speedX;
											player3.pos_playerX.y += 20 * player3.speedX;
											break;
										case SDLK_ESCAPE:
											quit=true;
											break;
										default:
											break;
									}
							}
						case (SDL_MOUSEBUTTONDOWN):
							  /* If the left button was pressed. */
						   switch (e.button.button) {
						   case SDL_BUTTON_LEFT: 
							   printf("click");
							   player1.shoot = true;
										player1.spawn_missileX();
							   break;
								}

					}
				}
				//Apply the PNG image
				SDL_BlitSurface( background, NULL, gScreenSurface2, NULL );
				//Apply the PNG image
				SDL_BlitSurface( menu_item_1, NULL, gScreenSurface2, &pos_item_1 );
				//Apply the PNG image
				SDL_BlitSurface( menu_item_2, NULL, gScreenSurface2, &pos_item_2 );
			
				SDL_BlitSurface( menu_item_3, NULL, gScreenSurface2, &pos_item_3 );
				
				player1.update();
				player2.update();
				player3.update();


				

			
				//SDL_BlitSurface( player1.player_pic, NULL, gScreenSurface2, &player1.pos_player);
				SDL_BlitSurface( weap2.gun, NULL, gScreenSurface2, &player1.pos_playerX );
					
				
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
				}
			}
	}

	//Free resources and close SDL
	close();

	return 0;
}