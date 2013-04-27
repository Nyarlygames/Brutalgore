#ifndef ENS_H
#define ENS_H

class Ennemy
{
    private:
    int x,y,z;
    GLuint texture[9];

    public:
    //Le constructeur permettant l'initialisation des variables
    Ennemy(int a, int b, int c);

  //  void handle_events();

    //montrer le personnage
    void show();
};

#endif //ENS_H
