
/*******************************************************/
/** Programme de PERRUCHON Romain pour developpez.com   **/
/**             Chapitre XII : Animation                                       **/
/*******************************************************/

//Les fichiers d'entête
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>



//Délais entre deux frames (en ms)
const float CAT_DELAI_FRAME = 120.0;

//Vitesse de marche du chat (en pixel par seconde)
const float CAT_VITESSE = 120.0;

// Nombre de frame d'animation
const int CAT_NB_ANIM = 3;



//Les dimensions du rectangle de notre personnage
const int CAT_WIDTH = 95;
const int CAT_HEIGHT = 130;

//Le statut des directions de notre personnage
const int CAT_RIGHT = 0;
const int CAT_LEFT = 1;

//Les surfaces
SDL_Surface *cat = NULL;

//Les zones de la feuille de sprite
SDL_Rect clipsRight[ 3 ];
SDL_Rect clipsLeft[ 3 ];

SDL_Surface *load_image(char *filename ) {
    //L'image qui est chargée
    SDL_Surface* loadedImage = NULL;

    //L'image optimisée que nous utiliserons par la suite
    SDL_Surface* optimizedImage = NULL;

    //Chargement de l'image
    loadedImage = SDL_LoadBMP( filename.c_str() );

    //Si l'image est chargée correctement
    if( loadedImage != NULL ) {
        //creation de l'image optimisée
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //liberation de l'ancienne image
        SDL_FreeSurface( loadedImage );
    }
    //on retourne l'image optimisé
    return optimizedImage;
}
//La classe Timer
class Timer
{
    private:
    //Le temps quand le timer est lancé
    int startTicks;

    //Les "ticks" enregistré quand le Timer a été mit en pause
    int pausedTicks;

    //Le status du Timer
    bool paused;
    bool started;

    public:
    //Initialise les variables (le constructeur)
    Timer();

    //Les différentes actions du timer
    void start();
    void stop();
    void pause();
    void unpause();

    //recupére le nombre de ticks depuis que le timer a été lancé
    //ou récupére le nombre de ticks depuis que le timer a été mis en pause
    int get_ticks();

    //Fonctions de vérification du status du timer
    bool is_started();
    bool is_paused();
};

//Notre personnage
class Cat
{
    private:
    int offSet;
    Timer anim;

    //sa vitesse de deplacement
    int velocity;

    //sa frame courante
    int frame;

    //Son statut d'animation
    int status;

    public:
    //Le constructeur permettant l'initialisation des variables
    Cat();

    void handle_events();

    //montrer le personnage
    void show();
};

void set_clips()
{
    //On coupe la feuille de sprite
    clipsRight[ 0 ].x = 0;
    clipsRight[ 0 ].y = 0;
    clipsRight[ 0 ].w = CAT_WIDTH;
    clipsRight[ 0 ].h = CAT_HEIGHT;

    clipsRight[ 1 ].x = CAT_WIDTH;
    clipsRight[ 1 ].y = 0;
    clipsRight[ 1 ].w = CAT_WIDTH;
    clipsRight[ 1 ].h = CAT_HEIGHT;

    clipsRight[ 2 ].x = CAT_WIDTH * 2;
    clipsRight[ 2 ].y = 0;
    clipsRight[ 2 ].w = CAT_WIDTH;
    clipsRight[ 2 ].h = CAT_HEIGHT;

    clipsLeft[ 0 ].x = 0;
    clipsLeft[ 0 ].y = CAT_HEIGHT;
    clipsLeft[ 0 ].w = CAT_WIDTH;
    clipsLeft[ 0 ].h = CAT_HEIGHT;

    clipsLeft[ 1 ].x = CAT_WIDTH;
    clipsLeft[ 1 ].y = CAT_HEIGHT;
    clipsLeft[ 1 ].w = CAT_WIDTH;
    clipsLeft[ 1 ].h = CAT_HEIGHT;

    clipsLeft[ 2 ].x = CAT_WIDTH * 2;
    clipsLeft[ 2 ].y = CAT_HEIGHT;
    clipsLeft[ 2 ].w = CAT_WIDTH;
    clipsLeft[ 2 ].h = CAT_HEIGHT;
}


bool load_files()
{
    //Chargement du fond
    cat = load_image()( "cat.png" );

    //S'il y a eu un problème au chargement du fond
    if( cat == NULL )
    {
        return false;
    }

    //Si tout s'est bien chargé
    return true;
}

/*void clean_up()
{
    //Libération des surfaces (ici une seule ^^)
    SDL_FreeSurface( cat );

    //On quitte SDL
    SDL_Quit();
}*/

Cat::Cat()
{
    //Initialisation des variables de mouvement
    offSet = 0;
    velocity = 0;

    //Initialisation des variables d'animation
    frame = 0;
    status = CAT_RIGHT;

    //Départ du timer
    anim.start();
}

void Cat::handle_events()
{
    //Si une touche est préssée
    if( event.type == SDL_KEYDOWN )
    {
        //mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity += (CAT_VITESSE / FRAMES_PER_SECOND); break;
            case SDLK_LEFT: velocity -= (CAT_VITESSE / FRAMES_PER_SECOND); break;
            default: break;
        }
    }
    //si une touche est relachée
    else if( event.type == SDL_KEYUP )
    {
        //Mise à jour de la velocité
        switch( event.key.keysym.sym )
        {
            case SDLK_RIGHT: velocity -= (CAT_VITESSE / FRAMES_PER_SECOND); break;
            case SDLK_LEFT: velocity += (CAT_VITESSE / FRAMES_PER_SECOND); break;
            default: break;
        }
    }
}

void Cat::show()
{
    //Mouvement
    offSet += velocity;

    //On garde le personnage dans les limites de la fenêtre SDL
    if( ( offSet < 0 ) || ( offSet + CAT_WIDTH > SCREEN_WIDTH ) )
    {
        offSet -= velocity;
    }

    //Si Cat bouge à gauche
    if( velocity < 0 )
    {
        //On prend le personnage de profil gauche
        status = CAT_LEFT;

		//S'il est l'heure, on change l'animation
		if( this->anim.get_ticks() >= CAT_DELAI_FRAME ) {

			// On remet le timer à 0
			anim.start();

			// On passe à la frame suivante
			frame++;
		}
    }
    //Si Cat bouge à droite
    else if( velocity > 0 )
    {
        //On prend le personnage de profil droit
        status = CAT_RIGHT;

		//S'il est l'heure, on change l'animation
		if( this->anim.get_ticks() >= CAT_DELAI_FRAME ) {

			// On remet le timer à 0
			anim.start();

			// On passe à la frame suivante
			frame++;
		}
    }
    //Si Cat ne bouge plus
    else
    {
        //Restart the animation
        frame = 1;
    }

    //Boucle l'animation
    if( frame >= CAT_NB_ANIM )
    {
        frame = 0;
    }

    //Affichage
    if( status == CAT_RIGHT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - CAT_HEIGHT, cat, screen, &clipsRight[ frame ] );
    }
    else if( status == CAT_LEFT )
    {
        apply_surface( offSet, SCREEN_HEIGHT - CAT_HEIGHT, cat, screen, &clipsLeft[ frame ] );
    }
}

Timer::Timer()
{
    //Initialisation des variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start()
{
    //Permet de mettre le timer en marche
    started = true;

    //Permet de mettre le timer en mode non pause
    paused = false;

    //On récupére le temps courant
    startTicks = SDL_GetTicks();
}

void Timer::stop()
{
    //On stoppe le timer
    started = false;

    //On enleve la pause
    paused = false;
}

void Timer::pause()
{
    //Si le timer est en marche et pas encore en pause
    if( ( started == true ) && ( paused == false ) )
    {
        //On met en pause le timer
        paused = true;

        //On calcul le pausedTicks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause()
{
    //Si le timer est en pause
    if( paused == true )
    {
        //on enlève la pause du timer
        paused = false;

        //On remet à zero le startTicks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Remise à zero du pausedTicks
        pausedTicks = 0;
    }
}

int Timer::get_ticks()
{
    //Si le timer est en marche
    if( started == true )
    {
        //Si le timer est en pause
        if( paused == true )
        {
            //On retourne le nombre de ticks quand le timer a été mis en pause
            return pausedTicks;
        }
        else
        {
            //On retourne le temps courant moins le temps quand il a démarré
            return SDL_GetTicks() - startTicks;
        }
    }

    //Si le timer n'est pas en marche
    return 0;
}

bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}

int perso_create()
{

    //Chargement des fichiers
    if( load_files() == false )
    {
        return 1;
    }

    //Decoupage de la feuille de sprite
    set_clips();

    //Le timer
    Timer fps;

    //Notre Chat qui va bouger
    Cat walk;

        //Affichage du "Cat" sur l'ecran
        walk.show();


    }

   /* //Nettoyage
    clean_up();*/

    return 0;
}
