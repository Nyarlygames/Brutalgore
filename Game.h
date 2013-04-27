#ifndef GAME_H
#define GAME_H

class Game
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
    Game(Player *playerset);

  //  void handle_events();

    //montrer le personnage
    void show(int a, int b, int c);
};

#endif //GAME_H
