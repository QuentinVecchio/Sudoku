#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

#include "gui_Resoudre.h"

/*Variables globales */
GtkWidget * dialogBox = NULL;
/********************/
void choisirFichier(GtkWidget *widget, gpointer data)
{
	dialogBox = gtk_file_chooser_dialog_new("Choisir un fichier",NULL,GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN ,GTK_RESPONSE_ACCEPT, NULL);
	gtk_widget_set_size_request(dialogBox, 300,300);
	if(gtk_dialog_run (GTK_DIALOG(dialogBox)) == GTK_RESPONSE_ACCEPT)
	{
		gchar * nomFichier = NULL;
		nomFichier = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogBox));
		affiche(nomFichier);
	}
	else
	{
		gtk_widget_destroy(dialogBox);
	}
}

void affiche(char lienFichier[])
{
	gtk_widget_destroy(dialogBox);
	SDL_Init(SDL_INIT_VIDEO);
	//ouverture de la bibliotheque d'écriture
    	TTF_Init();
	//Initialisation de la fenetre Principale
	SDL_Surface *fenetrePrincipale = NULL; //Fenetre de l'application
    	fenetrePrincipale = SDL_SetVideoMode(480,480,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    	SDL_FillRect(fenetrePrincipale, NULL, SDL_MapRGB(fenetrePrincipale->format,111,183,255)); //On initialise la couleur de $
    	SDL_WM_SetCaption("Résoudre Sudoku",NULL);
	int continuer = 1;//variable pour continuer
        SDL_Event event;//Déclaration d'un evenement
	while(continuer)
    	{
        	SDL_PollEvent(&event);//On recupere l'evenement et on le traite
        	switch(event.type)
        	{
                	case SDL_QUIT :
                        	continuer = 0;//On quitte le jeu
                        	break;
		}
		SDL_Flip(fenetrePrincipale);
    	}
	//On quitte le jeu proprement
        TTF_Quit();
        SDL_Quit();
	printf("\n%s\n",lienFichier);
}
