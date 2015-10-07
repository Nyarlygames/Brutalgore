#include "include/MainMenu.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "include/Enemy.h"
#include "include/Player.h"
//#include "include\Toolbox.h"

	

SDL_Rect mainmenu_3;
Enemy	menu1,menu2,menu3;
SDL_Surface* window = NULL;
SDL_Rect pos_item_1, pos_item_2, pos_item_3, pos_player1;
Enemy Enemy_1;
Enemy *Enemies;
Player Player1;
int max_enemies = 200;
int nb_enemies = 0;

SDL_Surface* loadMenuPic( std::string path, SDL_Surface*	screen )
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
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
};

void	setMenu(SDL_Surface	*screen){

	window = screen;

	pos_item_1.x = 10;
	pos_item_1.y = 20;
	Enemies = new Enemy[max_enemies];
	Enemies[0] = Enemy(screen,1,pos_item_1);
	nb_enemies++;

	pos_item_2.x = 500;
	pos_item_2.y = 300;
	Enemies[1] = Enemy(screen,2, pos_item_2);
	nb_enemies++;
	
	pos_item_3.x = 600;
	pos_item_3.y = 20;
	Enemies[2] = Enemy(screen,3,pos_item_3);
	
	pos_player1.x = 50;
	pos_player1.y = 600;
	Player1 = Player(screen,pos_player1,1);

};


void	updateMenu(SDL_Surface	*screen){
	if (nb_enemies >= 0){
		for (int i = 0; i < nb_enemies+1; i++) {
			Enemies[i].updateEnemy();
		}
	}
	Player1.update_player();
	SDL_Event e;

								//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					switch (e.type) {
						case SDL_KEYDOWN :
							//User requests quit
							switch (e.type) {
								case SDL_KEYDOWN :
											Player1.player_controls(e.key.keysym.sym);
											break;
							
							}
					}
					
				}
};
