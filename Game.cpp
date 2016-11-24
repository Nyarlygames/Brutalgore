#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
#include "include/Gun.h"
#include "include/Player.h"
#include "include/Camera.h"
#include "include/Game.h"
#include "include/MainMenu.h"
#include "Settings.h"
using namespace std;

Game::Game() {}
Game::Game(SDL_Surface*	Screen, SDL_Window *window, Settings s){
	state = 0;
	windows_game = window;
	set = s;
	mainscreen = Screen;
	setGame(1, s.height, s.width);
}

void Game::updateGame() {
	//see if useful later SDL_BlitScaled(bg_game, NULL, screenGame, &stretchRectGame);
	if ((sizex > 0) && (sizey > 0)) {
		for (int xline = 0; xline < sizey; xline++) {
			for (int yline = 0; yline < sizex; yline++) {
				// tilesize.w & tilesize.h if better cam
					tilecollide.w = tilesize.w;
					tilecollide.h = tilesize.h;
					tilecollide.x = yline * tilecollide.w;
					tilecollide.y = xline * tilecollide.h;
					SDL_BlitScaled(tiles[xline][yline], NULL, screenGame, &tilecollide);
			}
		}
	}
	if (nbplayers > 0) {
		for (int playblit = 0; playblit < nbplayers; playblit++) {
			Players[playblit].updatePlayer();
		}
	}
	if (nbenemiyspawn > 0) {
		for (int enblit = 0; enblit < nbenemiyspawn; enblit++) {
			Enemyspawn[enblit].updateEnemy();
		}
	}
	SDL_BlitScaled(screenGame, &cam.gamesize, cam.camsurf, &cam.camsize);
	SDL_BlitScaled(screenGame, &fullboardsize, cam.camsurf, &cam.minimapsize);
	cam.updateCamera(fullboardsize);
}

