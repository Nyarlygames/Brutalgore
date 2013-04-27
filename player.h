#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
    GLuint texture[9];

    public:
    int x,y,z = 0;
    int id;
    //Le constructeur permettant l'initialisation des variables
    Player();

  //  void handle_events();

    //montrer le personnage
    void show();
};


#endif //PLAYER_H
