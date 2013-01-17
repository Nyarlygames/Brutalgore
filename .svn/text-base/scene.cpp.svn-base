#include "scene.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include "sdlglutils.h"


GLuint texture[8];
extern int xp;
extern int yp;
extern int zp;

extern int mapy;
extern int mapx;

void chargerTextures()
{

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


    // Background
    texture[7] = loadTexture("img/background.jpg");




    //Sol
    texture[0] = loadTexture("img/ground.jpg");

}

/* ----------------------------------------------------------- MAP ---------------------------------------------*/
void map()
{
    //Sol

    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    glTexCoord2i(0,0);
    glVertex3d(-30,-mapy,2); // HAUT DROIT
    glTexCoord2i(10,0);
    glVertex3d(mapx,-mapy,2); // HAUT GAUCHE
    glTexCoord2i(10,10);
    glVertex3d(mapx,mapy,2); // BAS GAUCHE
    glTexCoord2i(0,10);
    glVertex3d(-30,mapy,2); // BAS DROIT
    glEnd();




}
/* ----------------------------------------------------------- FIN MAP ---------------------------------------------*/

/* ----------------------------------------------------------- PERSO ---------------------------------------------*/

void perso()
{

    /* ------------ CORPS  ----------------*/
  glBindTexture(GL_TEXTURE_2D, texture[1]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1.,yp-2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-5);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp,yp+2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp,yp+2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-5);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(xp+1,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp+1,yp-2.5,zp-5);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-5);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-5);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp);

    glEnd();


    /* ------------ Tete  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[2]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-1.25,zp+2);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-1.25,zp+2);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+1.25,zp+2);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+1.25,zp+2);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-1.25,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp,yp+1.25,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp,yp+1.25,zp+2);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-1.25,zp+2);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(xp+1,yp-1.25,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+1.25,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+1.25,zp+2);
    glTexCoord2d(0,1);
    glVertex3d(xp+1,yp-1.25,zp+2);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+1.25,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+1.25,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+1.25,zp+2);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+1.25,zp+2);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-1.25,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-1.25,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-1.25,zp+2);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-1.25,zp+2);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-1.25,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-1.25,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+1.25,zp);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+1.25,zp);

    glEnd();


        /* ------------ Bras gauche  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[3]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+2.5,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+4,zp-5);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp,yp+4,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp,yp+4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-5);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(xp+1,yp+2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+4,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp+1,yp+2.5,zp-5);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+4,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+4,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+4,zp-5);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-5);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+4,zp);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+4,zp);

    glEnd();

        /* ------------ Bras droit ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[4]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-4,zp-5);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp,yp-4,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp,yp-4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-5);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(xp+1,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-4,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp+1,yp-2.5,zp-5);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-4,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-4,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-4,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-4,zp-5);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-5);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-4,zp);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-4,zp);

    glEnd();

    /* ------------ Jambe gauche  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[5]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-10);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp,zp-10);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-10);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp,yp+2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp,yp+2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp,zp-10);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(xp+1,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp+1,yp,zp-10);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(xp,yp+2.5,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-10);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp,zp-10);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp+2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp+2.5,zp-5);

    glEnd();



    /* ------------ Jambe droite  ----------------*/
glBindTexture(GL_TEXTURE_2D, texture[6]);

    glBegin(GL_QUADS);
    //par terre
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-10);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp,zp-10);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-10);

    //face droite
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp,yp-2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp,yp-2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp,zp-10);

    //face gauche
    glTexCoord2d(0,0);
    glVertex3d(xp+1,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp+1,yp,zp-10);

    //face face
    glTexCoord2d(0,0);
    glVertex3d(xp,yp-2.5,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp-2.5,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-2.5,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-10);

    //face derriere
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp,zp-10);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp,zp-10);
    //face au ciel
    glTexCoord2d(0,0);
    glVertex3d(xp,yp,zp-5);
    glTexCoord2d(1,0);
    glVertex3d(xp+1,yp,zp-5);
    glTexCoord2d(1,1);
    glVertex3d(xp+1,yp-2.5,zp-5);
    glTexCoord2d(0,1);
    glVertex3d(xp,yp-2.5,zp-5);

    glEnd();

}

/* ----------------------------------------------------------- FIN PERSO ---------------------------------------------*/

void dessinerScene()
{

    //Background
    glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin(GL_QUADS);
    glTexCoord2d(1,0);
    glVertex3d(500,-1000,1000); // HAUT DROIT
    glTexCoord2d(0,0);
    glVertex3d(500,-1000,-1000); // BAS DROIT
    glTexCoord2d(1,1);
    glVertex3d(500,1000,1000); // HAUT GAUCHE
    glTexCoord2d(0,1);
    glVertex3d(500,1000,-1000); // BAS GAUCHE
    glEnd();


    perso();
    map();
}

