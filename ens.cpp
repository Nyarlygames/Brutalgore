//Les fichiers d'entête
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "sdlglutils.h"
#include <string>

//Notre personnage
class Ennemy
{
    private:
    GLuint texture[9];
    int offSet;

    //sa vitesse de deplacement
    int velocity;

    //sa frame courante
    int frame;

    //Son statut d'animation
    int status;

    public:
    //Le constructeur permettant l'initialisation des variables
    Ennemy(int a, int b, int c);

    void handle_events();

    //montrer le personnage
    void show(int a, int b, int c);
};

Ennemy::Ennemy(int a,int b,int c)
{
    texture[8] = loadTexture("img/ens.png");
    /*
    //Initialisation des variables de mouvement
    offSet = 0;
    velocity = 0;

    //Initialisation des variables d'animation
    frame = 0;
    status = Ennemy_RIGHT;

    //Départ du timer
    anim.start();*/
}/*

void Ennemy::handle_events()
{/*
    //Si une touche est préssée
    if( event.type == SDL_KEYDOWN )
    {
        //mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity += (Ennemy_VITESSE / FRAMES_PER_SECOND); break;
            case SDLK_LEFT: velocity -= (Ennemy_VITESSE / FRAMES_PER_SECOND); break;
            default: break;
        }
    }
    //si une touche est relachée
    else if( event.type == SDL_KEYUP )
    {
        //Mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity -= (Ennemy_VITESSE / FRAMES_PER_SECOND); break;
            case SDLK_LEFT: velocity += (Ennemy_VITESSE / FRAMES_PER_SECOND); break;
            default: break;
        }
    }
}*/

void Ennemy::show(int a, int b, int c)
{
    glBindTexture(GL_TEXTURE_2D, texture[8]);
    glBegin(GL_QUADS);
    glTexCoord2i(0,1);
    glVertex3d(a,b,40); // HAUT DROIT
    glTexCoord2i(1,1);
    glVertex3d(a,-b,40); // HAUT GAUCHE
    glTexCoord2i(1,0);
    glVertex3d(a,-b,0); // BAS GAUCHE
    glTexCoord2i(0,0);
    glVertex3d(a,b,0); // BAS DROIT
    glEnd();

    /*
    //Mouvement
    offSet += velocity;

    //On garde le personnage dans les limites de la fenêtre SDL
    if( ( offSet < 0 ) || ( offSet + Ennemy_WIDTH > SCREEN_WIDTH ) )
    {
        offSet -= velocity;
    }

    //Si Ennemy bouge à gauche
    if( velocity < 0 )
    {
        //On prend le personnage de profil gauche
        status = Ennemy_LEFT;

		//S'il est l'heure, on change l'animation
		if( this->anim.get_ticks() >= Ennemy_DELAI_FRAME ) {

			// On remet le timer à 0
			anim.start();

			// On passe à la frame suivante
			frame++;
		}
    }
    //Si Ennemy bouge à droite
    else if( velocity > 0 )
    {
        //On prend le personnage de profil droit
        status = Ennemy_RIGHT;

		//S'il est l'heure, on change l'animation
		if( this->anim.get_ticks() >= Ennemy_DELAI_FRAME ) {

			// On remet le timer à 0
			anim.start();

			// On passe à la frame suivante
			frame++;
		}
    }
    //Si Ennemy ne bouge plus
    else
    {
        //Restart the animation
        frame = 1;
    }

    //Boucle l'animation
    if( frame >= Ennemy_NB_ANIM )
    {
        frame = 0;
    }

    //Affichage
    if( status == Ennemy_RIGHT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - Ennemy_HEIGHT, Ennemy, screen, &clipsRight[ frame ] );
    }
    else if( status == Ennemy_LEFT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - Ennemy_HEIGHT, Ennemy, screen, &clipsLeft[ frame ] );
    }*/
}
