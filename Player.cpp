#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <iostream>
using namespace std;


class Player
{
	
    // Attributs
	SDL_Surface* player;
SDL_Surface* missile;
SDL_Rect pos_item_1;
SDL_Rect pos_item_2;
SDL_Rect pos_item_3;
SDL_Rect pos_player;



    int m_vie;
    int m_mana;
    string m_nomArme;
    int m_degatsArme;    


    // Méthodes
    void recevoirDegats(int nbDegats)
    {

    }

    void attaquer(Player &cible)
    {

    }

    void boirePotionDeVie(int quantitePotion)
    {

    }

    void changerArme(string nomNouvelleArme, int degatsNouvelleArme)
    {

    }

    bool estVivant()
    {

    }

};