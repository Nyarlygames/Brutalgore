/*******************************************************/
/** Programme de PERRUCHON Romain pour developpez.com **/
/**               Chapitre V : SDL_TTF                **/
/*******************************************************/

//Les fichiers d'entête
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>

    //Les surfaces
    SDL_Surface *message = NULL;

    //Le font qu'on va utiliser
    TTF_Font *font;




void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //on blit la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}


int printt( SDL_Surface * screen)
{


    //Initialisation de SDL_ttf
    TTF_Init();
    //on met en place la barre caption de la fenetre
    SDL_WM_SetCaption( "TTF Test", NULL );
    //Ouverture du font
    font = TTF_OpenFont( "CaslonBold.ttf", 28 );


    //application du texte
    message = TTF_RenderText_Solid( font, "test", textColor );

    //Si il y a une erreur lors de l'application du texte
    if( message == NULL )
    {
        return 1;
    }

    //Application des surfaces(images) sur l'ecran
    apply_surface(0, 10, message, screen );

    return 0;
}
