#ifndef GLOBAL_H
#define GLOBAL_H

#define Global extern


Global int xp = 10;
Global int yp = 0;
Global int zp = 12;

Global int xe = -20;
Global int ye = 0;
Global int ze = 15;

Global int xc = 80000;
Global int yc = 0;
Global int zc = 0;

Global int mapx = 400;
Global int mapy = 100;


Global int speed = 1;
/*

typedef struct	s_perso
{
  int		id;
//  SDL_Rect	infos;
  //int		power;
  int		life;
 // SDL_Surface	*anim[32];
  int		arrived;
  int		state;
  int		dest[2];
}		s_perso;


typedef struct   s_game
{
  /*int		pause;
  int		trigger;
  int		last_input;
  int		current_time;
  int		blink;
  int		blink_time;
  int		max_players;
  char		*custom_mus;
  SDL_Rect	help_r;
  SDL_Surface	*help_s;
  SDL_Surface	*screen;
  SDL_Surface	*box;
  SDL_Surface	*ground;
  SDL_Surface	*wall;
  SDL_Surface	*bomb;
  SDL_Surface	*bombp;
  SDL_Surface	*flame;
  SDL_Surface	*shield;
  SDL_Surface	*fire[7];
  s_grid	**grid;
  int		**tab;
  s_list_bomb   l_bomb;
  TTF_Font	*font;
  TTF_Font	*font_num;
  TTF_Font	*font_home;
  s_game_info	*info;
  s_perso	**persos;
}		s_game;

struct Game {
	bool    serv;
	//SDL_Surface *screen;
};*/

#endif //GLOBAL_H
