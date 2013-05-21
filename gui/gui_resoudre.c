/*********************************************************************************************************************************************
*       Partie graphique Resoudre Code Source
*       Fonctions, GTK/SDL
*       Fait par Quentin Vecchio
*       19 mai 2013
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

#include "gui_resoudre.h"

/*Variables globales */
GtkWidget * dialogBox = NULL;
gchar * lienFichier = NULL;
/********************/
void choisirFichier(GtkWidget *widget, gpointer data)
{
//Initialisation des variables test
        int Niveau = 1;
        int tpsExecution = 30;
        int grilleD[9][9] = {0};
        int grilleF[9][9] = {0};
//Initialisation des variables
        GtkWidget * label1;
        GtkWidget * zoneSaisi1;
        GtkWidget * btnEdit1;
        GtkWidget * hBox1;
//Initialisation de la dialogBox
        dialogBox = gtk_dialog_new_with_buttons("Choisir un Sudoku",GTK_WINDOW(widget), GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
//Initialisation des widgets
	label1 = gtk_label_new("Choisir un Sudoku");
        hBox1 = gtk_hbox_new( FALSE, 10);
        zoneSaisi1 = gtk_entry_new();
        btnEdit1 = gtk_button_new_with_label("...");
        g_signal_connect(G_OBJECT(btnEdit1),"clicked", G_CALLBACK(dialogBoxChoixFichier), NULL);
	gtk_box_pack_start(GTK_BOX(hBox1), zoneSaisi1, FALSE, FALSE,10);
        gtk_box_pack_start(GTK_BOX(hBox1), btnEdit1, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), label1, TRUE, TRUE, 10);
        gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), hBox1, TRUE, TRUE, 10);
//Lancement de la dialogBox
        gtk_widget_show_all(GTK_DIALOG(dialogBox)->vbox);
        switch(gtk_dialog_run(GTK_DIALOG(dialogBox)))
        {
                case GTK_RESPONSE_OK :
                	 affiche(grilleD,grilleF,tpsExecution,Niveau);
	}
}

void dialogBoxChoixFichier(GtkWidget *widget, gpointer data)
{
//Initialisation de la fenetre
	GtkWidget * dialogBoxChoix = NULL;
        dialogBoxChoix = gtk_file_chooser_dialog_new("Choisir un fichier",NULL,GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN ,GTK_RESPONSE_ACCEPT, NULL);
        gtk_widget_set_size_request(dialogBoxChoix, 300,300);
        if(gtk_dialog_run (GTK_DIALOG(dialogBoxChoix)) == GTK_RESPONSE_ACCEPT)
        {
                lienFichier = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogBoxChoix));
		gtk_widget_destroy(dialogBoxChoix);
        }
        else
        {
                gtk_widget_destroy(dialogBoxChoix);
        }

}

void affiche(int grille1[9][9], int grille2[9][9], int tps, int niv)
{
	int i,y;
	char strNiveau[20];
	sprintf(strNiveau,"Niveau %d",niv);
	char strTps[30];
	sprintf(strTps,"Temps execution : %d ms",tps);
	gtk_widget_destroy(dialogBox);
	SDL_Init(SDL_INIT_VIDEO);
//ouverture de la bibliotheque d'écriture
    	TTF_Init();
//Initialisation de la fenetre Principale
	SDL_Surface *fenetrePrincipale = NULL; //Fenetre de l'application
    	fenetrePrincipale = SDL_SetVideoMode(480,480,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    	SDL_FillRect(fenetrePrincipale, NULL, SDL_MapRGB(fenetrePrincipale->format,111,183,255)); //On initialise la couleur de $
    	SDL_WM_SetCaption("Résolution du Sudoku",NULL);
//Initialisation de l'image d'une grille
        SDL_Surface *Grille = NULL;
        Grille = SDL_LoadBMP("Grille.bmp");
        SDL_Rect posGrille;
        posGrille.x = 72;
        posGrille.y = 72;
//Initialisation des écritures et des couleurs
	char nombreAffich[2];//Variable qui contiendra le chiffre à afficher
        TTF_Font *police = NULL;
        police = TTF_OpenFont("police2.ttf",21); //Initialisation de la police
        SDL_Color couleurNoire = {0,0,0}; // Couleur Noire qui affiche les nombres déjà présent
	SDL_Color couleurBleue = {0,0,255}; // Couleur Bleue qui affiche les nouveau nombre
//Initialisation d'un tableau d'affichage pour les chiffres
	SDL_Surface *affichageChiffre[9][9];//Tableau qui va contenir les chiffres
	SDL_Rect posAffichageChiffre[9][9];//Tableau de position qui contient les chiffres
	//Initialisation des positions d'affichage
	for(i=0;i<9;i++)
	{
		for(y=0;y<9;y++)
		{
			posAffichageChiffre[i][y].x = (7.8 + y*40) + 72;
			posAffichageChiffre[i][y].y = (7.8 + i*40) + 72;
		}
	}
//Initialisation de l'affichage du temps d'execution
	TTF_Font *police2 = NULL;
        police2 = TTF_OpenFont("police2.ttf",30);
	SDL_Surface *affichageTps = NULL;
	SDL_Rect posAffichageTps;
	posAffichageTps.x = 170;
	posAffichageTps.y = 20;
	affichageTps = TTF_RenderText_Blended(police2,strTps,couleurNoire);
//Initialisation de l'affichage du niveau
	SDL_Surface *affichageNiveau = NULL;
        SDL_Rect posAffichageNiveau;
        posAffichageNiveau.x = 7;
        posAffichageNiveau.y = 20;
        affichageNiveau = TTF_RenderText_Blended(police2,strNiveau,couleurNoire);
//Initialisation de l'affichage de la phrase qui invite à quitter
	SDL_Surface *affichageQuitter = NULL;
        SDL_Rect posAffichageQuitter;
        posAffichageQuitter.x = 2;
        posAffichageQuitter.y = 440;
        affichageQuitter = TTF_RenderText_Blended(police2,"Appuyer sur une touche pour quitter !",couleurNoire);
//Début du programme
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
		SDL_BlitSurface(affichageQuitter, NULL, fenetrePrincipale, &posAffichageQuitter);
		SDL_BlitSurface(affichageTps, NULL, fenetrePrincipale, &posAffichageTps);
		SDL_BlitSurface(affichageNiveau, NULL, fenetrePrincipale, &posAffichageNiveau);
		SDL_BlitSurface(Grille, NULL, fenetrePrincipale, &posGrille);//On affiche la grille
       	 	for(i=0;i<9;i++)//Affiche les chiffres présent déjà dans la grille
        	{
			for(y=0;y<9;y++)
			{
                		if(grille1[i][y] != 0)
                		{
                        		sprintf(nombreAffich,"%d",grille1[i][y]);
                        		affichageChiffre[i][y] = TTF_RenderText_Blended(police,nombreAffich,couleurNoire);
                        		SDL_BlitSurface(affichageChiffre[i][y], NULL, fenetrePrincipale, &posAffichageChiffre[i][y]);
                		}
				else
				{
					sprintf(nombreAffich,"%d",grille2[i][y]);
                                        affichageChiffre[i][y] = TTF_RenderText_Blended(police,nombreAffich,couleurBleue);
                                        SDL_BlitSurface(affichageChiffre[i][y], NULL, fenetrePrincipale, &posAffichageChiffre[i][y]);
				}
			}
                }
		SDL_BlitSurface(affichageTps, NULL, fenetrePrincipale, &posAffichageTps);
		SDL_Flip(fenetrePrincipale);
    	}
	//On quitte le jeu proprement
        TTF_Quit();
        SDL_Quit();
}
