#ifndef PLAYER_H
#define PLAYER_H

class Player
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
    Player(int a, int b, int c);

  //  void handle_events();

    //montrer le personnage
    void show(int a, int b, int c);
};

#endif //PLAYER_H
