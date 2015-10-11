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
#include "include/Game.h"
//#include "include\Toolbox.h"

MainMenu::MainMenu() 
{
}

MainMenu::MainMenu(SDL_Surface*	Screen){
	max_enemies = 50;
	nb_enemies = 0;
	state=1;
	window = Screen;
	setMenu(Screen);
}
