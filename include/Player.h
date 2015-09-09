#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include "Gun.h"

class Player
{
    public:
		
//Player1();
    //Player(std::string nomArme, int degatsArme);
  //  ~Player();


		SDL_Surface* player_pic;
SDL_Surface* missile;
SDL_Rect pos_item_1;
SDL_Rect pos_item_2;
SDL_Rect pos_item_3;
SDL_Rect pos_player;
Gun weapon1;
bool	shoot;

    bool spawn_missile();
    void onClose ();
    private:

    int m_vie;
    int m_mana;
    std::string m_nomArme; //Pas de using namespace std, il faut donc mettrestd:: devant string
    int m_degatsArme;
	


};

#endif