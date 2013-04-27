//Les fichiers d'entête
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "sdlglutils.h"
#include <string>
#include "player.h"

extern int xp;
extern int yp;
extern int zp;

extern int mapy;
extern int mapx;


Player::Player()
{
    x = 10;
    y = 20;
    z = 12.5;
    //Corps
    texture[1] = loadTexture("img/bo.jpg");

    // Tete
    texture[2] = loadTexture("img/he.jpg");


    // Bras gauche
    texture[3] = loadTexture("img/la.jpg");

    // Bras droit
    texture[4] = loadTexture("img/ra.jpg");

    // Jambe gauche
    texture[5] = loadTexture("img/ll.jpg");

    // Jambe droit
    texture[6] = loadTexture("img/rl.jpg");
    /*
    //Initialisation des variables de mouvement
    offSet = 0;
    velocity = 0;

    //Initialisation des variables d'animation
    frame = 0;
    status = Player_RIGHT;

    //Départ du timer
    anim.start();*/
}/*

void Player::handle_events()
{/*
    //Si une touche est préssée
    if( event.tye == SDL_KEYDOWN )
    {
        //mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity += (Player_VITESSE / FRAMES_PER_SECOND); break;
            case SDLK_LEFT: velocity -= (Player_VITESSE / FRAMES_PER_SECOND); break;
            default: break;
        }
    }
    //si une touche est relachée
    else if( event.tye == SDL_KEYUP )
    {
        //Mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity -= (Player_VITESSE / FRAMES_PER_SECOND); break;
            case SDLK_LEFT: velocity += (Player_VITESSE / FRAMES_PER_SECOND); break;
            default: break;
        }
    }
}*/

void Player::show()
{
    if (id == 0) {
        x = xp;
        y = yp;
        z = zp;
    }
    else {
        y = 8*id;
    }
    glBindTexture(GL_TEXTURE_2D, texture[1]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1.,y-2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-5);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x,y+2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x,y+2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-5);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(x+1,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x+1,y-2.5,z-5);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(x,y+2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-5);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-5);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z);

    glEnd();


    /* ------------ Tete  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[2]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(x,y-1.25,z+2);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-1.25,z+2);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+1.25,z+2);
    glTexCoord2d(0,1);
    glVertex3d(x,y+1.25,z+2);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(x,y-1.25,z);
    glTexCoord2d(1,0);
    glVertex3d(x,y+1.25,z);
    glTexCoord2d(1,1);
    glVertex3d(x,y+1.25,z+2);
    glTexCoord2d(0,1);
    glVertex3d(x,y-1.25,z+2);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(x+1,y-1.25,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+1.25,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+1.25,z+2);
    glTexCoord2d(0,1);
    glVertex3d(x+1,y-1.25,z+2);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(x,y+1.25,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+1.25,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+1.25,z+2);
    glTexCoord2d(0,1);
    glVertex3d(x,y+1.25,z+2);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(x,y-1.25,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-1.25,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-1.25,z+2);
    glTexCoord2d(0,1);
    glVertex3d(x,y-1.25,z+2);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(x,y-1.25,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-1.25,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+1.25,z);
    glTexCoord2d(0,1);
    glVertex3d(x,y+1.25,z);

    glEnd();


        /* ------------ Bras gauche  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[3]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(x,y+2.5,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+4,z-5);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(x,y+2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x,y+4,z);
    glTexCoord2d(1,1);
    glVertex3d(x,y+4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-5);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(x+1,y+2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+4,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x+1,y+2.5,z-5);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(x,y+4,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+4,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+4,z-5);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(x,y+2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-5);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(x,y+2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+4,z);
    glTexCoord2d(0,1);
    glVertex3d(x,y+4,z);

    glEnd();

        /* ------------ Bras droit ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[4]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-4,z-5);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x,y-4,z);
    glTexCoord2d(1,1);
    glVertex3d(x,y-4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-5);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(x+1,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-4,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x+1,y-2.5,z-5);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(x,y-4,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-4,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-4,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-4,z-5);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-5);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-4,z);
    glTexCoord2d(0,1);
    glVertex3d(x,y-4,z);

    glEnd();

    /* ------------ Jambe gauche  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[5]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-10);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y,z-10);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-10);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x,y+2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x,y+2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y,z-10);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(x+1,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x+1,y,z-10);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(x,y+2.5,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-10);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y,z-10);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y+2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y+2.5,z-5);

    glEnd();



    /* ------------ Jambe droite  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[6]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-10);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y,z-10);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-10);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x,y-2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x,y-2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y,z-10);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(x+1,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x+1,y,z-10);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(x,y-2.5,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y-2.5,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-2.5,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-10);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y,z-10);
    glTexCoord2d(0,1);
    glVertex3d(x,y,z-10);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(x,y,z-5);
    glTexCoord2d(1,0);
    glVertex3d(x+1,y,z-5);
    glTexCoord2d(1,1);
    glVertex3d(x+1,y-2.5,z-5);
    glTexCoord2d(0,1);
    glVertex3d(x,y-2.5,z-5);

    glEnd();
    /*
    //Mouvement
    offSet += velocity;

    //On garde le personnage dans les limites de la fenêtre SDL
    if( ( offSet < 0 ) || ( offSet + Player_WIDTH > SCREEN_WIDTH ) )
    {
        offSet -= velocity;
    }

    //Si Player bouge à gauche
    if( velocity < 0 )
    {
        //On prend le personnage de profil gauche
        status = Player_LEFT;

		//S'il est l'heure, on change l'animation
		if( this->anim.get_ticks() >= Player_DELAI_FRAME ) {

			// On remet le timer à 0
			anim.start();

			// On passe à la frame suivante
			frame++;
		}
    }
    //Si Player bouge à droite
    else if( velocity > 0 )
    {
        //On prend le personnage de profil droit
        status = Player_RIGHT;

		//S'il est l'heure, on change l'animation
		if( this->anim.get_ticks() >= Player_DELAI_FRAME ) {

			// On remet le timer à 0
			anim.start();

			// On passe à la frame suivante
			frame++;
		}
    }
    //Si Player ne bouge plus
    else
    {
        //Restart the animation
        frame = 1;
    }

    //Boucle l'animation
    if( frame >= Player_NB_ANIM )
    {
        frame = 0;
    }

    //Affichage
    if( status == Player_RIGHT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - Player_HEIGHT, Player, screen, &clipsRight[ frame ] );
    }
    else if( status == Player_LEFT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - Player_HEIGHT, Player, screen, &clipsLeft[ frame ] );
    }*/
}
