/*********************************************************************************************************************************************
*       Partie graphique Jeux Code Source												     *
*       Fonctions, GTK															     *
*       Fait par Quentin Vecchio                                          								     *
*       25 mai 2013															     *
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <string.h>
#include <pthread.h>

#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "gui_jeux.h"

/*Variables gloables*/
int t;
int fini;
GtkWidget * fenetrePrincipaleJeux = NULL;
int grilleO[9][9] = {0};//Grille de l'ordinateur
GtkWidget * editChiffre[9][9];
pthread_t thread;
GtkWidget * labelTemps = NULL;
GtkWidget * fenetreFin = NULL;
char lienFichierJ[] = "../res/g1.txt";
/********************/

//------------------------------//
//	Fonction de jeux	//
//------------------------------//
void jouer(GtkWidget *widget, gpointer data)
{
//Initialisation du tps de debut
	t = time(NULL);
//Initialisation des tableaux
	int i,y;
	lireGrille(grilleO,lienFichierJ);
//Initialisation des chaines à afficher
	char nombreAffiche[60];
	char strNiveau[] = "Niveau 1";
//Initialisation d'un GtkRc pour le fond de la grille
	gtk_rc_parse("./gtkrc.rc");
//Initialisation variables fenetre
	GtkWidget * vBoxFenetre = NULL;
//Initialisation variables haut fenetre
	GtkWidget * labelNiveau = NULL;
	GtkWidget * hBoxHaut = NULL;
//Initialisation variables milieu de fenetre
	GtkWidget * labelChiffre[9][9];
	GtkWidget * vBoxGrille;
	GtkWidget * TabHBoxLigne[9];
//Initialisation variables bas de fenetre
	GtkWidget * btnMenu = NULL;
	GtkWidget * btnSoumettre = NULL;
	GtkWidget * hBoxBas = NULL;
//Initialisation de la fenetre Principale
	fenetrePrincipaleJeux = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(fenetrePrincipaleJeux), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(fenetrePrincipaleJeux), "Sudoku");
        gtk_window_set_default_size(GTK_WINDOW(fenetrePrincipaleJeux),480,480);
        g_signal_connect(G_OBJECT(fenetrePrincipaleJeux), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_icon_from_file(GTK_WINDOW(fenetrePrincipaleJeux),"icon.png",NULL);
	vBoxFenetre = gtk_vbox_new(FALSE,6);
	gtk_container_add(GTK_CONTAINER(fenetrePrincipaleJeux),vBoxFenetre);
//Initialisation de la partie Haut de la fenetre
        labelNiveau= gtk_label_new(strNiveau);
	labelTemps = gtk_label_new("");
	hBoxHaut = gtk_hbox_new(TRUE,0);
        gtk_box_pack_start(GTK_BOX(hBoxHaut),labelNiveau,TRUE,TRUE,10);
	gtk_box_pack_start(GTK_BOX(hBoxHaut),labelTemps,TRUE,TRUE,10);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxHaut,FALSE, FALSE,10);
//pthread_create(&thread, NULL, compteur,NULL);
	//Initialisation d'un thread
        	pthread_create(&thread, NULL, compteur,NULL);
//Initialisation de la partie du milieu de la fenetre
	GtkWidget * alignement = gtk_alignment_new(0.55,0.55,0.1,0.1);
        vBoxGrille = gtk_vbox_new(FALSE,21);
        for(i=0;i<9;i++)
        {
                TabHBoxLigne[i] = gtk_hbox_new(TRUE, 8);
                for(y=0;y<9;y++)
                {
                        if(grilleO[i][y] != 0)
                        {
                                        sprintf(nombreAffiche,"<span foreground=\"#000000\"><big><b>%d</b></big></span>",grilleO[i][y]);
                                        editChiffre[i][y] = NULL;
                                        labelChiffre[i][y] = gtk_label_new(nombreAffiche);
                                        gtk_label_set_use_markup(GTK_LABEL(labelChiffre[i][y]),TRUE);
                                        gtk_widget_set_size_request(labelChiffre[i][y],20,17);
                                        gtk_box_pack_start(GTK_BOX(TabHBoxLigne[i]),labelChiffre[i][y],FALSE,FALSE,5); // on ajoute un chiffre a la ligne
                        }
                        else
                        {
                                        editChiffre[i][y] = gtk_entry_new_with_max_length(1);;
                                        gtk_widget_set_size_request(editChiffre[i][y],20,18);
                                        labelChiffre[i][y] = NULL;
                                        gtk_box_pack_start(GTK_BOX(TabHBoxLigne[i]),editChiffre[i][y],FALSE,FALSE,5); // on ajoute un chiffre a la ligne
                        }
                }
                gtk_box_pack_start(GTK_BOX(vBoxGrille),TabHBoxLigne[i],TRUE,TRUE,0);//On ajoute la ligne a la Box vertical
        }
        gtk_container_add( GTK_CONTAINER(alignement), vBoxGrille);
        gtk_box_pack_start(GTK_BOX(vBoxFenetre),alignement,FALSE,TRUE,34);//On ajoute la box vertical a la fenetre
//Initialisation de la partie bas de la fenetre
        btnMenu = gtk_button_new_with_mnemonic("_Menu");
	btnSoumettre = gtk_button_new_with_mnemonic("_Soumettre");
	hBoxBas = gtk_hbox_new(TRUE, 30);
        g_signal_connect(G_OBJECT(btnMenu),"clicked", G_CALLBACK(retourMenuJeux), NULL);
        g_signal_connect(G_OBJECT(btnSoumettre),"clicked", G_CALLBACK(fin), NULL);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnMenu,FALSE,FALSE,20);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnSoumettre,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxBas,FALSE, FALSE,0);
//Affichage
        gtk_widget_show_all(fenetrePrincipaleJeux);
}

//----------------------------------------------//
//	Fonction appelleé en fin de jeux	//
//----------------------------------------------//
void fin()
{
//Gestion compteur
        fini = 1;//Arrete compteur
//On tue le thread du compteur
        pthread_cancel(thread);
//initialisation des variables
        GtkWidget * label1 = NULL;
	int i,y,continu = 1;
	char nombreAffiche[60];
	int grilleJ[9][9];//Grille du joueur
	int grilleR[9][9] = {0};//Grille résolu
	L_Candidats  LC[9][9]= {{NULL}};
        L_Cases LO = creer_liste_vide();
	Init_Data(LC, LO, grilleR, lienFichierJ);
	int grille_simple=fermerGrille(grilleR, LO, LC);
//Initialisation de grilleJ :: On recupere toutes les entrées dans les gtk_entry
	for(i=0;i<9;i++)
        {
                for(y=0;y<9;y++)
                {
                        if(editChiffre[i][y] != NULL)
                       		grilleJ[i][y] = fctCharChif(gtk_entry_get_text(GTK_ENTRY(editChiffre[i][y])));
			else
				grilleJ[i][y] = grilleO[i][y];
		}
	}
//Verification des résultats
	for(i=0;i<9;i++)
	{
		for(y=0;y<9;y++)
		{
			if(grilleJ[i][y] != grilleR[i][y])
			{
				continu = 0;
				break;
			}
		}
		if(continu == 0)
			break;
	}
//Initialisation des widgets selon la valeur de continue, si con = 0 pas bon et si = 1 alors bon
        if(continu)
		label1 = gtk_label_new("<span foreground=\"#1C863B\"><big><b>FELICITATION !! :)</b></big></span>");
        else
		label1 = gtk_label_new("<span foreground=\"#FF0000\"><big><b>DOMMAGE !!! :(</b></big></span>");
//Initialisation d'un GtkRc pour le fond de la grille
        gtk_rc_parse("./gtkrc.rc");
//Initialisation variables fenetre
        GtkWidget * vBoxFenetre = NULL;
//Initialisation variables milieu de fenetre
        GtkWidget * labelChiffre[9][9];
        GtkWidget * vBoxGrille;
        GtkWidget * TabHBoxLigne[9];
//Initialisation variables bas de fenetre
        GtkWidget * btnMenu = NULL;
        GtkWidget * btnQuitter = NULL;
        GtkWidget * hBoxBas = NULL;
//Initialisation de la fenetre Principale
        fenetreFin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(fenetreFin), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(fenetreFin), "Résultat");
        gtk_window_set_default_size(GTK_WINDOW(fenetreFin),480,480);
        g_signal_connect(G_OBJECT(fenetreFin), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
        gtk_window_set_icon_from_file(GTK_WINDOW(fenetreFin),"icon.png",NULL);
        vBoxFenetre = gtk_vbox_new(FALSE,6);
        gtk_container_add(GTK_CONTAINER(fenetreFin),vBoxFenetre);
//Initialisation de la partie Haut de la fenetre
        gtk_label_set_use_markup(GTK_LABEL(label1),TRUE);
        gtk_box_pack_start(GTK_BOX(vBoxFenetre),label1,FALSE, FALSE,10);
//Initialisation de la partie du milieu de la fenetre
	GtkWidget * alignement = gtk_alignment_new(0.55,0.55,0.1,0.1);
        vBoxGrille = gtk_vbox_new(FALSE,21);
        for(i=0;i<9;i++)
        {
                TabHBoxLigne[i] = gtk_hbox_new(TRUE, 8);
                for(y=0;y<9;y++)
                {
                        if(grilleO[i][y] != 0)
                        {
                                        //Chiffre déjà présent
                                        sprintf(nombreAffiche,"<span foreground=\"#000000\"><big><b>%d</b></big></span>",grilleO[i][y]);
                        }
                        else
                        {
                                        if(grilleJ[i][y] == grilleR[i][y])//Chiffre bien placé
                                                sprintf(nombreAffiche,"<span foreground=\"#1C863B\"><big><b>%d</b></big></span>",grilleR[i][y]);
                                        else//Chiffre pas bien placé
                                                sprintf(nombreAffiche,"<span foreground=\"#FF0000\"><big><b>%d</b></big></span>",grilleO[i][y]);
                        }
                        labelChiffre[i][y] = gtk_label_new(nombreAffiche);
                        gtk_label_set_use_markup(GTK_LABEL(labelChiffre[i][y]),TRUE);
                        gtk_widget_set_size_request(labelChiffre[i][y],20,17);
                        gtk_box_pack_start(GTK_BOX(TabHBoxLigne[i]),labelChiffre[i][y],FALSE,FALSE,5); // on ajoute un chiffre a la ligne
                }
                gtk_box_pack_start(GTK_BOX(vBoxGrille),TabHBoxLigne[i],TRUE,TRUE,0);//On ajoute la ligne a la Box vertical
        }
        gtk_container_add( GTK_CONTAINER(alignement), vBoxGrille);
        gtk_box_pack_start(GTK_BOX(vBoxFenetre),alignement,FALSE,TRUE,34);//On ajoute la box vertical a la fenetre
//Initialisation de la partie bas de la fenetre
        btnMenu = gtk_button_new_with_mnemonic("_Menu");
        btnQuitter = gtk_button_new_with_mnemonic("_Quitter");
        hBoxBas = gtk_hbox_new(TRUE, 30);
        g_signal_connect(G_OBJECT(btnMenu),"clicked", G_CALLBACK(retourMenuJeux2), NULL);
        g_signal_connect(G_OBJECT(btnQuitter),"clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnMenu,FALSE,FALSE,20);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnQuitter,FALSE,FALSE,20);
        gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxBas,FALSE, FALSE,0);
//Affichage
	gtk_widget_destroy(fenetrePrincipaleJeux);
        gtk_widget_show_all(fenetreFin);
}

//------------------------------------------------------//
//	Fonction qui transforme une chaine en entier	//
//------------------------------------------------------//
int fctCharChif(const gchar *str)
{
	int i;
	int nb=0;
	for(i=0;i<strlen(str);i++)
	{
		nb += 10*i+(str[i]-48);
	}
	return nb;
}

//------------------------------//
//	Fonction compteur	//
//------------------------------//
void* compteur(void *data)
{
	int tps,s,m,tpsAvant;
	char strChrono[100],chM[3],chS[3];
	while(fini == 0)
	{
		tps = time(NULL)-t;
		m = tps/60;
		s = tps%60;
		if(s>tpsAvant)
		{
			if(s<10)
				sprintf(chS,"0%d",s);
			else
				sprintf(chS,"%d",s);
			if(m<10)
				sprintf(chM,"0%d",m);
			else
				sprintf(chM,"%d",m);
			sprintf(strChrono,"%s:%s",chM,chS);
			tpsAvant = s;
			gtk_label_set_text(GTK_LABEL(labelTemps),strChrono);
		}
		if(tpsAvant>s)
			tpsAvant = s;
	}
}

//------------------------------------------------------------------------------//
//	Fonction qui permet de retourner au menu depuis la fenetre jeux		//
//------------------------------------------------------------------------------//
void retourMenuJeux()
{
        gtk_widget_destroy(fenetrePrincipaleJeux);
}

//------------------------------------------------------------------------//
//      Fonction qui permet de retourner au menu depuis la fenetre fin    //
//------------------------------------------------------------------------//
void retourMenuJeux2()
{
        gtk_widget_destroy(fenetreFin);
}

