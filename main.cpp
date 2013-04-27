#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include <cmath>
#include <string>

#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "sdlglutils.h"
#include "scene.h"
#include "sound.h"
#include "global.h"
#include "ens.h"
#include "player.h"
#include "game.h"

#define FPS 50
#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600



SDL_Event event;

const int SCREEN_BPP = 32;

//Les surfaces
SDL_Surface *background = NULL;
SDL_Surface *cursor = NULL;
SDL_Surface *launch = NULL;
SDL_Surface *lan = NULL;
SDL_Surface *opt = NULL;
SDL_Surface *screen = NULL;
Ennemy *ens = NULL;
Player *player = NULL;
Game *gameobj = NULL;
//Le font qu'on va utiliser
TTF_Font *font;
TTF_Font *font2;

//La couleur du font-
SDL_Color textColor = { 200, 0, 0 };
void DrawGL( SDL_Surface * ecran);
int game(int nbplayers);

bool handle_event(bool fup, bool fright, bool fleft, bool fdown, int speed);



SDL_Surface *load_image( std::string filename )
{
    //L'image qui est chargée
    SDL_Surface* loadedImage = NULL;

    //L'image optimisée que nous utiliserons par la suite
    SDL_Surface* optimizedImage = NULL;

    //Chargement de l'image
    loadedImage = IMG_Load( filename.c_str() );

    //Si l'image est chargée correctement
    if( loadedImage != NULL )
    {
        //creation de l'image optimisée
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //liberation de l'ancienne image
        SDL_FreeSurface( loadedImage );

        //si l'image optimisée créé est bonne
        if( optimizedImage != NULL )
        {
            //transparence
            SDL_SetColorKey( optimizedImage, SDL_RLEACCEL | SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //on retourne l'image optimisé
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //on blit la surface
    SDL_BlitSurface( source, clip, destination, &offset );
}

/* ------------------------------------------------------------- MENU ------------------------------------------------*/

bool init()
{
    //initialisation de tout les sous-systemes de sdl
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //on met en place l'ecran
    screen = SDL_SetVideoMode( LARGEUR_FENETRE, HAUTEUR_FENETRE, SCREEN_BPP, SDL_SWSURFACE );

    //Si il y a une erreur lors de la mise en place de l'ecran
    if( screen == NULL )
    {
        return false;
    }

    //Initialisation de SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //on met en place la barre caption de la fenetre
    SDL_WM_SetCaption( "Brutal Gore Launcher", NULL );

    //si tout s'est bien passé
    return true;
}

bool load_files()
{
    //chargement du fond
    background = load_image("img/background.png" );

    //Ouverture du font
    font = TTF_OpenFont( "Gore Font II.ttf", 28 );
    font2 = TTF_OpenFont( "brutal-tooth.ttf", 28 );

    //si il y a un probleme au chargement du fond
    if( background == NULL )
    {
        return false;
    }

    //Si il y a une erreur au chargement du font
    if( font == NULL )
    {
        return false;
    }

    //Si tout s'est bien passé
    return true;
}

void clean_up()
{
    //Liberation des surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( cursor );
    SDL_FreeSurface( lan );
    SDL_FreeSurface( opt );

    //On ferme le font qu'on a utilisé
    TTF_CloseFont( font );

    //On quitte SDL_ttf
    TTF_Quit();

    //On quitte SDL
    SDL_Quit();
}

/* ------------------------------------------------------------- SELECTION ------------------------------------------------*/
int selection(int from){
    SDL_Rect bg;
    SDL_Rect cursorl;
    SDL_Surface *pcount = NULL;
    bool quit = false;
    int nbplayers = 1;
    cursorl.x = 20;
    cursorl.y = HAUTEUR_FENETRE/4;
    pcount = TTF_RenderText_Solid( font, "1", textColor );
    bg.x = 0;
    bg.y = 0;

    while( quit == false )
    {
        SDL_Flip(screen);
        SDL_BlitSurface( background, NULL, screen, &bg );
        SDL_BlitSurface( pcount, NULL, screen, &cursorl );
        while( SDL_PollEvent( &event ) )
        {
              switch(event.type)
            {
                case SDL_QUIT:
                    quit = true;
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {/*
                    case SDLK_KP0:
                        pcount = TTF_RenderText_Solid( font, "0", textColor );*/
                        break;
                    case SDLK_KP1:
                        pcount = TTF_RenderText_Solid( font, "1", textColor );
                        nbplayers = 1;
                        break;
                    case SDLK_KP2:
                        pcount = TTF_RenderText_Solid( font, "2", textColor );
                        nbplayers = 2;
                        break;
                    case SDLK_KP3:
                        pcount = TTF_RenderText_Solid( font, "3", textColor );
                        nbplayers = 3;
                        break;
                    case SDLK_KP4:
                        pcount = TTF_RenderText_Solid( font, "4", textColor );
                        nbplayers = 4;
                        break;
                    case SDLK_KP5:
                        pcount = TTF_RenderText_Solid( font, "5", textColor );
                        nbplayers = 5;
                        break;
                    case SDLK_KP6:
                        pcount = TTF_RenderText_Solid( font, "6", textColor );
                        nbplayers = 6;
                        break;
                    case SDLK_KP7:
                        pcount = TTF_RenderText_Solid( font, "7", textColor );
                        nbplayers = 7;
                        break;
                    case SDLK_KP8:
                        pcount = TTF_RenderText_Solid( font, "8", textColor );
                        nbplayers = 8;
                        break;
                    case SDLK_KP9:
                        pcount = TTF_RenderText_Solid( font, "9", textColor );
                        nbplayers = 9;
                        break;
                    break;
                    case SDLK_ESCAPE:
                    quit=true;
                    break;
                    case SDLK_UP:
                    if (cursorl.y > HAUTEUR_FENETRE/4)
                        cursorl.y -= (HAUTEUR_FENETRE/4);
                    else
                        cursorl.y = (HAUTEUR_FENETRE/4);
                    break;
                    case SDLK_DOWN:
                    if (cursorl.y < HAUTEUR_FENETRE*3/4)
                        cursorl.y += (HAUTEUR_FENETRE/4);
                    else
                        cursorl.y = (HAUTEUR_FENETRE*3/4);
                    break;
                    case SDLK_RETURN:
                    if (cursorl.y == HAUTEUR_FENETRE/4)
                    {
                       game(nbplayers);
                    }
                    break;
                }
            }
        }
    }
    return (0);
}
int main( int argc, char* args[] )
{
    SDL_Rect optos;
    SDL_Rect launchos;
    SDL_Rect lanos;
    SDL_Rect bg;
    SDL_Rect cursorl;

    launchos.x = 50;
    launchos.y = HAUTEUR_FENETRE/4;
    lanos.x = 50;
    lanos.y = HAUTEUR_FENETRE*2/4;
    optos.x = 50;
    optos.y = HAUTEUR_FENETRE*3/4;
    bg.x = 0;
    bg.y = 0;
    cursorl.x = 20;
    cursorl.y = HAUTEUR_FENETRE/4;
    //ce qui va nous permettre de quitter
    bool quit = false;

    //Initialisation
    if( init() == false )
    {
        return 1;
    }

    //Chargement des fichiers
    if( load_files() == false )
    {
        return 1;
    }
    /*
    //cursor
    cursor = load_image( "img/cursor.png" );*/

    //application du texte
    launch = TTF_RenderText_Solid( font, "Lancer", textColor );
    lan= TTF_RenderText_Solid( font, "LAN", textColor );
    opt= TTF_RenderText_Solid( font, "Options", textColor );
    cursor = TTF_RenderText_Solid( font2, "=", textColor );

/*

    //Application des surfaces(images) sur l'ecran
    apply_surface( 0, 0, background, screen );
    apply_surface( 20, HAUTEUR_FENETRE/4, cursor, screen );
    apply_surface( 50, HAUTEUR_FENETRE*3/4, launch, screen );
    apply_surface( 50, HAUTEUR_FENETRE*2/4, lan, screen );
    apply_surface( 50, HAUTEUR_FENETRE/4, opt, screen );*/

    //mise à jour de l'ecran
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //Tant que l'utilisateur n'a pas quitter
    while( quit == false )
    {
        SDL_Flip(screen);
        SDL_BlitSurface( background, NULL, screen, &bg );
        SDL_BlitSurface( launch, NULL, screen, &launchos );
        SDL_BlitSurface( lan, NULL, screen, &lanos );
        SDL_BlitSurface( opt, NULL, screen, &optos );
        SDL_BlitSurface( cursor, NULL, screen, &cursorl );
        //tant qu'il y a un evenement dans le handler
        while( SDL_PollEvent( &event ) )
        {
              switch(event.type)
            {
                case SDL_QUIT:
                    clean_up();
                    quit=true;
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    quit=true;
                    break;
                    case SDLK_UP:
                    if (cursorl.y > HAUTEUR_FENETRE/4)
                        cursorl.y -= (HAUTEUR_FENETRE/4);
                    else
                        cursorl.y = (HAUTEUR_FENETRE/4);
                    break;
                    case SDLK_DOWN:
                    if (cursorl.y < HAUTEUR_FENETRE*3/4)
                        cursorl.y += (HAUTEUR_FENETRE/4);
                    else
                        cursorl.y = (HAUTEUR_FENETRE*3/4);
                    break;
                    case SDLK_RETURN:
                    if (cursorl.y == HAUTEUR_FENETRE/4)
                    {
                        selection(1);
                    }
                    if (cursorl.y == HAUTEUR_FENETRE*2/4)
                    {
                        // LAN
                    }

                    break;
                }
                break;
            }
        }
    }

    return 0;
}


/* ------------------------------------------------------------- GAME ------------------------------------------------*/

int game(int nbplayers)
{
	// opengl lighting initialization
	glDisable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );

	float lightpos[]	= { 10.0, 10.0, 100.0 };
	float lightcolor[]	= { 1.0, 1.0, 1.0, 1.0 };

	glLightfv( GL_LIGHT0, GL_POSITION, lightpos );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, lightcolor );
	glLightfv( GL_LIGHT0, GL_SPECULAR, lightcolor );
    bool fright = false;
    bool fleft = false;
    bool fdown = false;
    bool fup = false;
    Player  *players[nbplayers];
    SDL_Surface *ecran = NULL;

    const Uint32 time_per_frame = 1000/FPS;

    Uint32 last_time,current_time,elapsed_time; //for time animation
    Uint32 start_time,stop_time; //for frame limit


    SDL_Init(SDL_INIT_VIDEO);


	//Mise en place de la barre caption
	SDL_WM_SetCaption( "Brutal Gore", NULL );

    atexit(SDL_Quit);
    /*playsound("sound/alig.mp3");*/

    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_OPENGL);
   /* initFullScreen();*/
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective(70,(double)LARGEUR_FENETRE/HAUTEUR_FENETRE,1,1000);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    ens = new Ennemy(-30,0,15);
   /* ens = new Ennemy(50,11,40);

    ens = new Ennemy(55,10,40);
    ens = new Ennemy(50,10,30);*/
    gameobj = new Game(nbplayers);
    chargerTextures();

    last_time = SDL_GetTicks();
    for (;;)
    {

        start_time = SDL_GetTicks();
        SDL_PollEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                exit(0);
                break;
                case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_PRINT:
                    takeScreenshot("test2.bmp");
                    break;
                    case SDLK_ESCAPE:
                    exit(0);
                    break;
                    case SDLK_SPACE:
                        xc = 10;
                        yc = -10;
                        xe = -xp;
                        ye = 10;
                    break;
                    case SDLK_UP:
/*                    movelegs("up");*/
                    fup = true;
                    fdown = false;
                    break;
                    case SDLK_DOWN:
                    fdown = true;
                    fup = false;
                    break;
                    case SDLK_RIGHT:
                    fright = true;
                    fleft = false;
                    break;
                    case SDLK_LEFT:
                    fleft = true;
                    fright = false;
                    break;
                }
                break;
            case SDL_KEYUP:
                  switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                    fup = false;
                    break;
                    case SDLK_DOWN:
                    fdown = false;
                    break;
                    case SDLK_RIGHT:
                    fright = false;
                    break;
                    case SDLK_LEFT:
                    fleft = false;
                    break;
                }
                break;
            }
        handle_event(fup, fright, fleft, fdown, speed);

        current_time = SDL_GetTicks();
        elapsed_time = current_time - last_time;
        last_time = current_time;

        DrawGL(ecran);

        stop_time = SDL_GetTicks();
        if ((stop_time - last_time) < time_per_frame)
        {
           SDL_Delay(time_per_frame - (stop_time - last_time));
        }

    }

    return 0;
}


bool handle_event(bool fup, bool fright, bool fleft, bool fdown, int speed)
{
    Uint8 *keystate = SDL_GetKeyState(NULL);

    if (keystate[SDLK_RIGHT] && (yp-4 < -15*mapy))
        return false;
    else
        if (keystate[SDLK_LEFT] && (yp+4 > 15*mapy))
            return false;
        else
            if (keystate[SDLK_UP] && (xp+10 > 15*mapx))
                return false;
            else
                if (keystate[SDLK_DOWN] && (xp-2 < -15*30))
                return false;


/* --------------------------------------------- MULTI KEY ---------------------------------------------*/
    if ( keystate[SDLK_RIGHT] && keystate[SDLK_UP] )
    {
        yp -= speed/2;
        xp += speed/2;
    };

    if ( keystate[SDLK_LEFT] && keystate[SDLK_UP] )
    {
        yp += speed/2;
        xp += speed/2;
    };

    if ( keystate[SDLK_RIGHT] && keystate[SDLK_DOWN] )
    {
        yp -= speed/2;
        xp -= speed/2;
    };

    if ( keystate[SDLK_LEFT] && keystate[SDLK_DOWN] )
    {
        yp += speed/2;
        xp -= speed/2;
    };

    if ( keystate[SDLK_LEFT] && keystate[SDLK_RIGHT] )
    {
        if (fright)
            yp += speed;
        else
            yp -= speed;
    };
    if ( keystate[SDLK_DOWN] && keystate[SDLK_UP] )
    {
        if (fdown)
            xp += speed;
        else
            xp -= speed;
    };


/* --------------------------------------------- SINGLE KEY ---------------------------------------------*/
    if ( keystate[SDLK_DOWN] )
        xp -= speed;

    if (keystate[SDLK_UP] )
        xp += speed;

    if ( keystate[SDLK_RIGHT])
        yp -= speed;

    if ( keystate[SDLK_LEFT])
        yp += speed;
return true;

}

void DrawGL( SDL_Surface *ecran)
{

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
    gluLookAt(xp+xe,yp+ye,zp+ze,
             xc,yc,zc,
              0,0,1);
    ens->show();
    for (int i = 0; i < gameobj->nbplayers; i++) {
        gameobj->players[i]->show();
    }
    dessinerScene();
    SDL_GL_SwapBuffers();
}
