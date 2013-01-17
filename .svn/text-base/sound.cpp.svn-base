/*******************************************************/
/** Programme de PERRUCHON Romain pour developpez.com **/
/**           Chapitre VII : Jouer du son             **/
/*******************************************************/

//Les fichiers d'entête
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <string>


//La musique qui sera joué
Mix_Music *music = NULL;


void close_mus()
{
  /*  Mix_FreeMusic( music );*/
    Mix_CloseAudio();
}

int playsound(char *file)
{
    //Initialisation de SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Chargement de la musique
    music = Mix_LoadMUS(file);
    Mix_PlayMusic( music, -1 );
  /*  //S'il n'y a pas de musique joué
    if( Mix_PlayingMusic() == 0 )
        {
        //On lance la musique
        if( Mix_PlayMusic( music, -1 ) == -1 )
            {
            return 1;
            }
        }
                  //Si la musique est déjà lancée
                    else
                    {
                        //Si la musique est en pause
                        if( Mix_PausedMusic() == 1 )
                        {
                            //On enlève la pause (la musique repart où elle en était)
                            Mix_ResumeMusic();
                        }
                        //Si la musique est en train de jouer
                        else
                        {
                            //On met en pause la musique
                            Mix_PauseMusic();
                        }
                    }
                }
                //Si 0 a été préssé
                else if( event.key.keysym.sym == SDLK_0 )
                {
                    //On stoppe la musique
                    Mix_HaltMusic();
                }*/
    //Libération des surfaces, fonts, effets et sons
    //On quitte SDL_mixer, SDL_ttf et SDL


    return 0;
}
