#include "scene.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "ens.h"
#include "sdlglutils.h"


GLuint texture[9];
extern int xp;
extern int yp;
extern int zp;

extern int mapy;
extern int mapx;

void chargerTextures()
{

    //Corps
    texture[1] = loadTexture("img/bo.jpg");
    texture[8] = loadTexture("img/ens.png");

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
// MUR
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    glTexCoord2i(0,0);
    glVertex3d(-30,mapy,mapx); // HAUT DROIT
    glTexCoord2i(10,0);
    glVertex3d(mapx,mapy,mapx); // HAUT GAUCHE
    glTexCoord2i(10,10);
    glVertex3d(mapx,mapy,2); // BAS GAUCHE
    glTexCoord2i(0,10);
    glVertex3d(-30,mapy,2); // BAS DROIT
    glEnd();

// ENS
    //En1 = Ennemy(50,10,40);


}
/* ----------------------------------------------------------- FIN MAP ---------------------------------------------*/

/* ----------------------------------------------------------- DESSIN ---------------------------------------------*/


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
  //  perso();
    map();
   // En(50,10,40);
    //En(100,10,40);
}

