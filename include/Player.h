#ifndef DEF_PLAYER
#define DEF_PLAYER

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>

class Player
{
    public:

    void recevoirDegats(int nbDegats);
    void attaquer(Player &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();

		SDL_Surface* player;
SDL_Surface* missile;
SDL_Rect pos_item_1;
SDL_Rect pos_item_2;
SDL_Rect pos_item_3;
SDL_Rect pos_player;

    private:

    int m_vie;
    int m_mana;
    std::string m_nomArme; //Pas de using namespace std, il faut donc mettrestd:: devant string
    int m_degatsArme;
	


};

#endif