#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "include/Enemy.h"
#include "include/Player.h"
#include "include/Game.h"
#include "include/MainMenu.h"

MainMenu::MainMenu() 
{
}

MainMenu::MainMenu(SDL_Surface*	Screen){
	max_enemies = 50;
	nb_enemies = 0;
	state=0;
	window = Screen;
	setMenu(Screen);

	bg = loadMenuPic( "img\\background.png" , window);
	if( bg == NULL )
	{
		printf( "Failed to load MenuBG image!\n" );
	}
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = 1920;
	stretchRect.h = 1080;

}