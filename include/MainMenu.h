#ifndef DEF_MAINMENU
#define DEF_MAINMENU

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Enemy.h"
#include "Player.h"

class MainMenu
{
    public:
SDL_Surface* window;
SDL_Surface* bg;
SDL_Rect pos_item_1, pos_item_2, pos_item_3, pos_item_4, pos_player1;
Enemy *Enemies;
Player Player1;
int max_enemies;
int nb_enemies;
int state;
SDL_Rect stretchRect;

MainMenu();
MainMenu(SDL_Surface*	Screen);


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
	Enemies[0] = Enemy(screen,1,pos_item_1,7);

	nb_enemies++;
	pos_item_2.x = 500;
	pos_item_2.y = 300;
	Enemies[1] = Enemy(screen,2, pos_item_2,10);

	nb_enemies++;
	pos_item_3.x = 600;
	pos_item_3.y = 20;
	Enemies[2] = Enemy(screen,3,pos_item_3,20);

	nb_enemies++;
	pos_item_4.x = 100;
	pos_item_4.y = 200;
	Enemies[3] = Enemy(screen,4,pos_item_4,5);
	
	pos_player1.x = 50;
	pos_player1.y = 600;
	Player1 = Player(screen,pos_player1,1);


};


void	collision_check(Player PlayerColl, Enemy* EnemyColl){
if (PlayerColl.nb_missiles>0){
	for (int i = 0; i< nb_enemies+1; i++){
		for (int y = 0; y< PlayerColl.nb_missiles; y++){
			if (EnemyColl[i].state != 0) {
						if (((PlayerColl.missiles_player[y].pos_missile.x <= EnemyColl[i].pos_enemy.x + EnemyColl[i].img_enemy->w) &&
							(PlayerColl.missiles_player[y].pos_missile.x + PlayerColl.missiles_player[y].img_missile->w >= EnemyColl[i].pos_enemy.x)) && 
							((PlayerColl.missiles_player[y].pos_missile.y + PlayerColl.missiles_player[y].img_missile->h >= EnemyColl[i].pos_enemy.y) &&
							(PlayerColl.missiles_player[y].pos_missile.y <= EnemyColl[i].pos_enemy.y+ EnemyColl[i].img_enemy->h))) {
								if ((EnemyColl[i].state == 1) && (EnemyColl[i].health - PlayerColl.damages <= 0) && (PlayerColl.missiles_player[y].state_missile == 1)) {
									printf("enemy dead");
									EnemyColl[i].state = 0;
								}
								else if ((EnemyColl[i].health > 0) && (PlayerColl.missiles_player[y].state_missile == 1)) {
									printf("enemy hurt");
									PlayerColl.missiles_player[y].state_missile = 0;
									EnemyColl[i].fillbar.w = (EnemyColl[i].health * EnemyColl[i].img_enemy->w) / EnemyColl[i].basehealth;
									SDL_FillRect(EnemyColl[i].healthbar, &EnemyColl[i].fillbar, SDL_MapRGB(EnemyColl[i].healthbar->format, 255, 30, 0));
									SDL_BlitSurface( EnemyColl[i].healthbar, NULL, EnemyColl[i].screen_enemy, &EnemyColl[i].healthpos );
									EnemyColl[i].health = EnemyColl[i].health - 1;//PlayerColl.damages;
								}
						}
			}
		}
	}
}
	// add collision player and stuff, case object, switch with objet type
};

void	updateMenu(){
	SDL_BlitScaled(bg, NULL, window, &stretchRect);
	if (nb_enemies >= 0){
		for (int i = 0; i < nb_enemies+1; i++) {
			//addcheck if dead no update
			Enemies[i].updateEnemy();
			if ((Enemies[i].id == 1) && (Enemies[i].state == 0)){
				//quit game
				state=-1;
			}
			else if ((Enemies[i].id == 2) && (Enemies[i].state == 0)){
				state=1; //newgame
			}
			else if ((Enemies[i].id == 4) && (Enemies[i].state == 0)){
				state=2; // map editor
			}
		}
	}
	Player1.updatePlayer();
	collision_check(Player1, Enemies);
	//printf("%d updateMainMenu \n", state);
};

void onClose() {
	//SDL_FreeSurface( background );
	//background = NULL;
};


};

#endif