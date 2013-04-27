/**
** \file struct.h
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <stdlib.h>
# include <SDL/SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
# include "const.h"

/**
** Conatins the item list
*/
typedef struct	s_items
{
  SDL_Rect	lst[MAX_CASE];
  int		type[MAX_CASE];
  int		count;
  int		buff[4];
}		s_items;

typedef struct  s_list_bomb
{
  SDL_Rect	list[MAX_CASE];
  int		p[MAX_CASE];
  int		pnbb[4];
  int		ticks[MAX_CASE];
}		s_list_bomb;

typedef struct	s_grid
{
  SDL_Rect	pos;
  int		type;
}		s_grid;

typedef struct	s_game_info
{
  int		sec;
  int		min;
  int		remain;
  SDL_Rect	*timer_r;
  SDL_Surface	*timer_s;
  SDL_Rect	*timer_sec_r;
  SDL_Surface	*timer_sec_s;
  SDL_Rect	*timer_min_r;
  SDL_Surface	*timer_min_s;
  SDL_Rect	*timer_separ_r;
  SDL_Surface	*timer_separ_s;
  SDL_Rect	*p1_r;
  SDL_Surface	*p1_s;
  SDL_Rect	*p2_r;
  SDL_Surface	*p2_s;
  SDL_Rect	*p3_r;
  SDL_Surface	*p3_s;
  SDL_Rect	*p4_r;
  SDL_Surface	*p4_s;
  SDL_Rect	*p1_id_r;
  SDL_Surface	*p1_id_s;
  SDL_Rect	*p2_id_r;
  SDL_Surface	*p2_id_s;
  SDL_Rect	*p3_id_r;
  SDL_Surface	*p3_id_s;
  SDL_Rect	*p4_id_r;
  SDL_Surface	*p4_id_s;
  SDL_Rect	*p1_lif_r;
  SDL_Surface	*p1_lif_s;
  SDL_Rect	*p2_lif_r;
  SDL_Surface	*p2_lif_s;
  SDL_Rect	*p3_lif_r;
  SDL_Surface	*p3_lif_s;
  SDL_Rect	*p4_lif_r;
  SDL_Surface	*p4_lif_s;
  SDL_Rect	*winner_r;
  SDL_Surface	*winner_s;
  SDL_Rect	*winner_id_r;
  SDL_Surface	*winner_id_s;
 }		s_game_info;

typedef struct	s_game
{
  int		pause;
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
  s_items	*items;
}		s_game;

typedef struct	s_perso
{
  int		id;
  SDL_Rect	pos;
  int		power;
  int		life;
  SDL_Surface	*anim[32];
  int		arrived;
  int		state;
  int		dest[2];
}		s_perso;

typedef struct	s_sound
{
  int		vol_fx;
  int		vol_music;
  Mix_Music	*music;
  Mix_Chunk	*bomb;
  Mix_Chunk	*planted;
  Mix_Chunk	*step;
}		s_sound;

#endif /* !STRUCT_H_ */
