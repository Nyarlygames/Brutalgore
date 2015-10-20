/**
** \file const.h
*/

#ifndef CONST_H_
# define CONST_H_

# define FPS 20
# define DELAY 20 /* time actualise (ms)*/

# define SIZE	13 /* Size of the grid (SIZE*SIZE) */

# define TICK_BOOM 2500
# define END_GAME 300000

# define COLOR_DEFAULT {220, 120, 0, 0}
# define COLOR_BLUE {20, 60, 210, 0}
# define COLOR_GREY {130, 130, 130, 0}
# define COLOR_HOME {0, 100, 250, 0}
# define COLOR_HOME_ON {250, 100, 0, 0}

# define MAX_CASE 66

# define INPUT_LOOP_THRESHOLD 300  /* Time to limit abusive input repeat */

# define NORTH 0
# define EAST 8
# define SOUTH 16
# define WEST 24

extern int LARGEUR=0;
extern int HAUTEUR=0;

#endif /* !CONST_H_ */
