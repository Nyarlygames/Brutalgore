#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Settings.h"
#include <SDL.h>
#include <SDL_image.h>

const int MAX_MAP_CHARS = 512;
const int MAX_MAP_TOKENS = 500;
char* const MAP_DELIMITER = " ";
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

using namespace std;

class Game
{
    public:
		
Player *Players;
SDL_Window *windows_game;
int state;
SDL_Surface *bg_game;
int nbplayers;
int mapid;
int sizex, sizey;
SDL_Rect stretchRectGame;
SDL_Surface*	screenGame;
SDL_Surface*	Camerasurf;
const char *bgname;
SDL_Surface** tileset;
SDL_Surface*** tiles;
SDL_Rect tilesize;
SDL_Rect tilecollide;
SDL_Rect testbg;
Settings set;
SDL_Rect testdest;
SDL_Rect tileborder;
SDL_Surface *testcam;
SDL_Surface *test2;
int camcontrol;

Game();
Game(SDL_Surface*	Screen, SDL_Window *window, Settings set);

void onClose(){}
	
void updateGame() {
	SDL_BlitScaled(bg_game, NULL, screenGame, &stretchRectGame);
		/*	testcam = SDL_CreateRGBSurface(0, testbg.w, testbg.h, 32, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
			SDL_FillRect(testcam, NULL, SDL_MapRGB(testcam->format, 255, 255, 255));
			SDL_BlitSurface( testcam, NULL, screenGame, &testbg );*/
	if ((sizex > 0) && (sizey > 0)) {
		for (int xline = 0; xline < sizex; xline++) {
			for (int yline = 0; yline < sizey; yline++) {
				// tilesize.w & tilesize.h if better cam
					tilecollide.w = set.width / sizey;
					tilecollide.h = set.height / sizex;
					tilecollide.x = yline * tilecollide.w;
					tilecollide.y = xline * tilecollide.h;
					camcontrol = inCamera(testbg, tilecollide);
					switch (camcontrol) {
						case 1 :
							SDL_BlitScaled(tiles[xline][yline], NULL, screenGame, &tilecollide);
							break;
						case 2 :
							tileborder.x = testbg.x;
							tileborder.y = testbg.y;
							tileborder.w =tilecollide.x + tilecollide.w - testbg.x;
							tileborder.h =tilecollide.y + tilecollide.h - testbg.y;
								/*test2 = SDL_CreateRGBSurface(0, tilecollide.w, tilecollide.h, 32, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
								SDL_FillRect(test2, NULL, SDL_MapRGB(test2->format, 10, 10, 10));
								SDL_BlitSurface( test2, NULL, screenGame, &tileborder );*/
							SDL_BlitScaled(tiles[xline][yline], NULL, screenGame, &tileborder);
							break;
						case -1:
							break;
					};
			}
		}
	}
	if (nbplayers > 0) {
		for (int playblit = 0; playblit < nbplayers; playblit++) {
			Players[playblit].updatePlayer();
		}
	}
	
	//SDL_BlitScaled(screenGame, &testbg, Camerasurf, &testdest);
}

void loadMap(int mapnumber) {
	printf("Loading a map \n");
	ifstream fin;
	switch (mapnumber){
	case 1:
		fin.open("maps\\map01.bgm");
		break;
	case 2:
		fin.open("maps\\map02.bgm");
		break;
	default:
		fin.open("maps\\GameSettings.bgm");
		// object or map for game settings? best case scenario : menu map everywhere
		break;
	}

	if (fin.good()){
		int map_pos = 0;
		while (!fin.eof())
		{
			char buf[MAX_MAP_CHARS];
			fin.getline(buf, MAX_MAP_CHARS);
			int n = 0;
			const char* token[MAX_MAP_TOKENS] = {};
			token[0] = strtok(buf, MAP_DELIMITER);
			if (token[0])
			{
				for (n = 1; n < MAX_MAP_TOKENS; n++)
				{
				token[n] = strtok(0, MAP_DELIMITER);
					if (!token[n]) {
							break;
					}
				}
			}

			if (n>0) {
				if (!strcmp(token[0], "BG")){
					cout << "background url : " << token[0] << " " << token[1] << endl;
					bgname = token[1];
					//to debug
					cout << bgname << endl;
				}
				else if (!strcmp(token[0], "Players")){
					cout << "Players: " << token[0] << " nb " << token[1] << endl;
					nbplayers = atoi(token[1]);
					Players = new Player[atoi(token[1])]; 
				}
				else if (!strcmp(token[0], "Player")){
					cout << "Player: " << token[0] << " id " << token[1] << " x " << token[2] << " y " << token[2] << endl;
					SDL_Rect pos_player_base;
					pos_player_base.x=atoi(token[2]);
					pos_player_base.y=atoi(token[3]);
					Players[atoi(token[1])-1] = Player(screenGame, pos_player_base, atoi(token[1]));
				}
				else if (!strcmp(token[0], "Size")){
					sizex = atoi(token[1]);
					sizey = atoi(token[2]);
					tiles = new SDL_Surface**[sizex];
					cout << "Map size: X = " << token[1] << " Y = " << token[1] << endl;
				}
				else if (!strcmp(token[0], "TileSet")){
					tileset = new SDL_Surface* [atoi(token[1])];
					for (int tileid = 0;  tileid < atoi(token[1]); tileid ++) {
						switch (atoi(token[tileid+2])) {
						case 0:
								tileset[tileid] = loadGamePic( "img\\tileset\\0.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 1:
								tileset[tileid] = loadGamePic( "img\\tileset\\1.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 2:
								tileset[tileid] = loadGamePic( "img\\tileset\\2.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 3:
								tileset[tileid] = loadGamePic( "img\\tileset\\3.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 4:
								tileset[tileid] = loadGamePic( "img\\tileset\\4.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 5:
								tileset[tileid] = loadGamePic( "img\\tileset\\5.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 6:
								tileset[tileid] = loadGamePic( "img\\tileset\\6.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 7:
								tileset[tileid] = loadGamePic( "img\\tileset\\7.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 8:
								tileset[tileid] = loadGamePic( "img\\tileset\\8.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						case 9:
								tileset[tileid] = loadGamePic( "img\\tileset\\9.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;
						default:
								tileset[tileid] = loadGamePic( "img\\tileset\\10.png" , screenGame);
								if( bg_game == NULL )
								{
									printf( "Failed to load GameBG image!\n" );
								}	
								break;

						}
					}
				}
				else if (!strcmp(token[0], "Tiles")){
					cout << "Line = ";
					tiles[map_pos] = new SDL_Surface*[sizey];
					for (int yline = 0; yline < sizey; yline++) {
						tiles[map_pos][yline] = tileset[atoi(token[yline+1])];
						cout << token[yline+1];
					}
					cout << endl;
					map_pos++;
				}
				else if (!strcmp(token[0], "TileSize")){
					tilesize.w = atoi(token[1]);
					tilesize.h = atoi(token[2]);
				}
			}
		}
		fin.close();
	}
}

	
int inCamera(SDL_Rect cam, SDL_Rect pos_object) {
	if (((pos_object.x >= cam.x) && (pos_object.x + pos_object.w <= cam.x + cam.w))
		&& ((pos_object.y >= cam.y) && (pos_object.y + pos_object.h <= cam.y + cam.h)))
		return 1;
	else if ((pos_object.x + pos_object.w >= cam.x) && (pos_object.x < cam.x)
			&& (pos_object.y + pos_object.h > cam.y) && (pos_object.y <cam.y)) {
		return 2;
	}
	else
		return -1;
}
	
void setGame(int mapnumber, int sheight, int swidth) {
	mapid = mapnumber;	
	loadMap(mapnumber);
	stretchRectGame.x = 0;
	stretchRectGame.y = 0;
	stretchRectGame.w = set.width;
	stretchRectGame.h = set.height;
	Camerasurf = SDL_GetWindowSurface( windows_game );
	bg_game = loadGamePic("img/backgroundGame.png", screenGame);
	if( bg_game == NULL )
	{
		printf( "Failed to load GameBG image!\n" );
	}
	state = 1;

	//POS CAPTURE
	testbg.x = 800;
	testbg.y = 500;
	// ZOOM
	testbg.w = 300;
	testbg.h = 300;
	// POS CAM
	testdest.x = 500;
	testdest.y = 500;
	// TAILLE CAM
	testdest.w = 500;
	testdest.h = 500;
}

SDL_Surface* loadGamePic( std::string path, SDL_Surface*	screen )
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface( loadedSurface, screen->format, NULL );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		SDL_FreeSurface( loadedSurface );
	}
	return optimizedSurface;
}

};


#endif