#ifndef DEF_GUN
#define DEF_GUN

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>

class Gun
{
    public:
		
	SDL_Surface* gun, missile;
	SDL_Rect pos_gun, pos_missiles;
	
	//void loadpic(int id);
	//void display(* screen);

    void loadpic(int nbDegats);
    void attaquer(Gun &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant();




};

#endif