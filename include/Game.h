#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Player.h"
#include <SDL.h>
#include <SDL_image.h>

const int MAX_MAP_CHARS = 512;
const int MAX_MAP_TOKENS = 20;
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
const char *bgname;
SDL_Surface** tileset;
SDL_Surface*** tiles;
SDL_Rect tilesize;

Game();
Game(SDL_Surface*	Screen, SDL_Window *window);

void onClose(){}
	
void updateGame() {
	SDL_BlitScaled(bg_game, NULL, screenGame, &stretchRectGame);
	if ((sizex > 0) && (sizey > 0)) {
		for (int xline = 0; xline < sizex; xline++) {
			for (int yline = 0; yline < sizey; yline++) {
				SDL_Rect tilepos;
				tilesize.x = yline * tilesize.w;
				tilesize.y = xline * tilesize.h;
				//SDL_BlitSurface(tiles[xline][yline], NULL, screenGame, &tilepos );
				SDL_BlitScaled(tiles[xline][yline], NULL, screenGame, &tilesize);
			}
		}
	}
	if (nbplayers > 0) {
		for (int playblit = 0; playblit < nbplayers; playblit++) {
			Players[playblit].updatePlayer();
		}
	}
	//printf("%d updateGame \n", state);
}

void loadMap(int mapnumber) {
	printf("Loading a map \n");
	// create a file-reading object
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
	
void setGame(int mapnumber) {
	mapid = mapnumber;	
	loadMap(mapnumber);
	bg_game = loadGamePic("img\\backgroundGame.png", screenGame);
	if( bg_game == NULL )
	{
		printf( "Failed to load GameBG image!\n" );
	}
	state = 1;
}

SDL_Surface* loadGamePic( std::string path, SDL_Surface*	screen )
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
}

};


#endif