/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>

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
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* background = NULL;
SDL_Surface* menu_item_1 = NULL;
SDL_Surface* menu_item_2 = NULL;
SDL_Surface* menu_item_3 = NULL;
SDL_Surface* player = NULL;
SDL_Surface* missile = NULL;
SDL_Rect pos_item_1;
SDL_Rect pos_item_2;
SDL_Rect pos_item_3;
SDL_Rect pos_player;
SDL_Rect spawn_missiles[20];
SDL_Rect dest_missiles[20];
SDL_Surface*	missiles[20] ;
Mix_Music*	mus = NULL;
int speed = 1;
int nb_missiles = -1;
int nb_missiles_max = 19;
int damages = 1;
int hpmenu1 = 5;
int hpmenu2 = 2;
int hpmenu3 = 1;
int hpplayer = 5;

void missile_die(SDL_Surface*	missile) {

}

void missile_hit(SDL_Surface*	target, SDL_Surface*	missile) {
	if (target == menu_item_3) {
		hpmenu3 -= damages;
		if (hpmenu3 == 0) {
		SDL_FreeSurface(menu_item_3);
		menu_item_3 = NULL;
		menu_item_3 = loadSurface( "img\\menu-exit-dead.png" );
		}
	}
	if (target == menu_item_2) {
		hpmenu2 -= damages;
		if (hpmenu2 == 0) {
		SDL_FreeSurface(menu_item_2);
		menu_item_2 = NULL;
		menu_item_2 = loadSurface( "img\\menu-options-dead.png" );
		}
	}
	if (target == menu_item_1) {
		hpmenu1 -= 5;
		if (hpmenu1 == 0) {
		SDL_FreeSurface(menu_item_1);
		menu_item_1 = NULL;
		menu_item_1 = loadSurface( "img\\menu-play-dead.png" );
		}
	}
}


bool spawn_missile() {
	if (nb_missiles >= nb_missiles_max - 1)
		return false;
	else {
	nb_missiles++;
	missiles[nb_missiles] = loadSurface( "img\\missile.png" );
	/*else {
	//missiles[nb_missiles] = loadSurface( "img\\missile.png" );
	if (missile == NULL)
		return false;
	missiles[nb_missiles] = missile;*/
	int x,y = -1;
	spawn_missiles[nb_missiles].x = pos_player.x;
	spawn_missiles[nb_missiles].y = pos_player.y;
	SDL_GetMouseState(&x,&y);	
	dest_missiles[nb_missiles].x = x;
	dest_missiles[nb_missiles].y = y;	
	return true;
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
	background = loadSurface( "img\\background.png" );
	if( background == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	menu_item_1 = loadSurface( "img\\menu-play.png" );
	if( menu_item_1 == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	menu_item_2 = loadSurface( "img\\menu-options.png" );
	if( menu_item_2 == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	menu_item_3 = loadSurface( "img\\menu-exit.png" );
	if( menu_item_2 == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	player = loadSurface( "img\\player.png" );
	if( player == NULL )
	{
		printf( "Failed to load PNG image!\n" );
		success = false;
	}
	missile = loadSurface( "img\\missile.png" );
	if ( missile == NULL )
	{
		printf( "Failed to load PNG image!\n" );
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
	SDL_FreeSurface(player);
	player = NULL;
	for (int  i = nb_missiles; i>=0; i--) {
		SDL_FreeSurface(missiles[i]);
	}
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

SDL_Surface* loadSurface( std::string path )
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
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
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
											pos_player.x -= 10* speed;
											break;
										case SDLK_RIGHT:
											pos_player.x += 10* speed;
											break;
										case SDLK_UP:
											pos_player.y -= 10* speed;
											break;
										case SDLK_DOWN:
											pos_player.y += 10 * speed;
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
							  /* Quit the application */
										if (spawn_missile())
											shoot =true;
							   break;
								}

					}
					


					//User requests quit
					/*if( e.type == SDL_Keycode(SDLK_DOWN) )
					{
						pos_player.y++;
					}
					//User requests quit
					if( e.type == SDL_Keycode(SDLK_LEFT) )
					{
						pos_player.x--;
					}
					//User requests quit
					if( e.type == SDL_Keycode("Up") )
					{
						pos_player.y--;
					}
					//User requests quit
					if( e.type == SDL_Keycode("Right") )
					{
						pos_player.x++;
					}*/
				}
				
				//Apply the PNG image
				SDL_BlitSurface( background, NULL, gScreenSurface, NULL );
				//Apply the PNG image
				SDL_BlitSurface( menu_item_1, NULL, gScreenSurface, &pos_item_1 );
				//Apply the PNG image
				SDL_BlitSurface( menu_item_2, NULL, gScreenSurface, &pos_item_2 );
			
				SDL_BlitSurface( menu_item_3, NULL, gScreenSurface, &pos_item_3 );
				SDL_BlitSurface( player, NULL, gScreenSurface, &pos_player );
				if (shoot == true){
					//for (int i=0; i<nb_missiles; i++) {
						int i = 0;
						for (int i=0; i<nb_missiles; i++) {
						if (missiles[i] != NULL) {
							SDL_BlitSurface(missiles[i], NULL, gScreenSurface, &spawn_missiles[i] );
						if (dest_missiles[i].x <spawn_missiles[i].x)
							spawn_missiles[i].x--;
						if (dest_missiles[i].x > spawn_missiles[i].x)
							spawn_missiles[i].x++;
						if (dest_missiles[i].y <spawn_missiles[i].y)
							spawn_missiles[i].y--;
						if (dest_missiles[i].y > spawn_missiles[i].y)
							spawn_missiles[i].y++;

						if ((spawn_missiles[i].x - dest_missiles[i].x == 0) && (spawn_missiles[i].y - dest_missiles[i].y ==0)){
							missile_die(missiles[i]);
						}

						
						
						if ((spawn_missiles[i].x + missiles[i]->w >= pos_item_3.x) && (spawn_missiles[i].x + missiles[i]->w <= pos_item_3.x + menu_item_3->w)) {
							if ((spawn_missiles[i].y + missiles[i]->h >= pos_item_3.y) && (spawn_missiles[i].y + missiles[i]->h <= pos_item_3.y + menu_item_3->h)) 
							{
								missile_hit(menu_item_3, missiles[i]);
			printf( "hit3!\n", nb_missiles );
							}
						}
						if ((spawn_missiles[i].x + missiles[i]->w >= pos_item_1.x) && (spawn_missiles[i].x + missiles[i]->w <= pos_item_1.x + menu_item_1->w)) {
							if ((spawn_missiles[i].y + missiles[i]->h >= pos_item_1.y) && (spawn_missiles[i].y + missiles[i]->h <= pos_item_1.y + menu_item_1->h)) 
							{
								missile_hit(menu_item_1, missiles[i]);
			printf( "hit1!\n" );
							}
						}
						if ((spawn_missiles[i].x + missiles[i]->w >= pos_item_2.x) && (spawn_missiles[i].x + missiles[i]->w <= pos_item_2.x + menu_item_2->w)) {
							if ((spawn_missiles[i].y + missiles[i]->h >= pos_item_2.y) && (spawn_missiles[i].y + missiles[i]->h <= pos_item_2.y + menu_item_2->h)) 
							{
								missile_hit(menu_item_2, missiles[i]);
			printf( "hit2!\n" );
							}
						}
						}
						
						
						/*	

						if ((spawn_missiles[i].x == pos_item_3.x) && (spawn_missiles[i].y == pos_item_3.y)){
							missile_hit(menu_item_3, missiles[i]);
			printf( "hit!\n" );
						}*/
						}

					
				}
			
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}