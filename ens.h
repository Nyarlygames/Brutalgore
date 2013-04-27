#ifndef ENS_H
#define ENS_H

class Ennemy
{
    private:
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

  //  void handle_events();

    //montrer le personnage
    void show(int a, int b, int c);
};

#endif //ENS_H
