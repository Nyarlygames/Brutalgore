#ifndef GAME_H
#define GAME_H
#include "player.h"

class Game
{
    public:
    //Le constructeur permettant l'initialisation des variables
    Game(int pcount);
    int nbplayers;
    Player **players;

  //  void handle_events();

    //montrer le personnage
    void show(int a, int b, int c);
};

#endif //GAME_H
