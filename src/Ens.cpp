#include "../include/Ens.h"
#include <iostream>
#include "../scene.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "../sdlglutils.h"

// Ennemy constructor
Ennemy::Ennemy(int a, int b, int c)
{
   // set_values(a, b, c);
    //x = a;
    //y = b;
    //z = c;
}
/*
class Ennemy {
    int x, y;
    GLuint texture;
  public:
    void set_values (int,int);
    int area () {return (x*y);}
};*/

void Ennemy::set_values (int a, int b, int c) {
   /* texture = loadTexture("img/ens.png");
    // A = DISTANCE B = TAILLE
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2i(0,1);
    glVertex3d(a,b,40); // HAUT DROIT
    glTexCoord2i(1,1);
    glVertex3d(a,-b,40); // HAUT GAUCHE
    glTexCoord2i(1,0);
    glVertex3d(a,-b,0); // BAS GAUCHE
    glTexCoord2i(0,0);
    glVertex3d(a,b,0); // BAS DROIT
    glEnd();*/
}




/*
Ens::Ens()
{
    //ctor
}

Ens::~Ens()
{
    //dtor
}
*/
