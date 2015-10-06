#include "include/MainMenu.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
//#include "include\Toolbox.h"

	
SDL_Surface* menu_item_12 = NULL;
SDL_Rect mainmenu_1;
SDL_Surface* window = NULL;

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
	
	menu_item_12 = loadMenuPic( "img\\menu12.png", screen );
	mainmenu_1.x = 100;
	mainmenu_1.y = 300;
	window = screen;



};


void	updateMenu(SDL_Surface	*screen){
	
		if ((window != NULL) && (menu_item_12 != NULL))
		SDL_BlitSurface( menu_item_12, NULL, window, &mainmenu_1 );
					
};
