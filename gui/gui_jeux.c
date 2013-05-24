/*********************************************************************************************************************************************
*       Partie graphique Jeux Code Source
*       Fonctions, GTK
*       Fait par Quentin Vecchio
*       19 mai 2013
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "gui_jeux.h"

void jouer(GtkWidget *widget, gpointer data)
{
//Initialisation des tableaux
	int grille1[9][9] = {0};
	int grille2[9][9] = {0};
	int i,y;
	char lienFichier[] = "../res/g1.txt";
	lireGrille(grille1,lienFichier);
//Initialisation des chaines à afficher
	char nombreAffiche[60];
	char strNiveau[] = "Niveau 1";
	char strChrono[] = "00:00";
//Initialisation d'un GtkRc pour le fond de la grille
	gtk_rc_parse("./gtkrc.rc");
//Initialisation variables fenetre
	GtkWidget * fenetrePrincipale = NULL;
	GtkWidget * vBoxFenetre = NULL;
//Initialisation variables haut fenetre
	GtkWidget * labelNiveau = NULL;
	GtkWidget * labelTemps = NULL;
	GtkWidget * hBoxHaut = NULL;
//Initialisation variables milieu de fenetre
	GtkWidget * labelChiffre[9][9];
	GtkWidget * editChiffre[9][9];
	GtkWidget * vBoxGrille;
	GtkWidget * TabHBoxLigne[9];
//Initialisation variables bas de fenetre
	GtkWidget * btnMenu = NULL;
	GtkWidget * btnQuitter = NULL;
	GtkWidget * hBoxBas = NULL;
//Initialisation de la fenetre Principale
	fenetrePrincipale = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(fenetrePrincipale), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(fenetrePrincipale), "Sudoku");
        gtk_window_set_default_size(GTK_WINDOW(fenetrePrincipale),480,480);
        g_signal_connect(G_OBJECT(fenetrePrincipale), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
        gtk_window_set_icon_from_file(GTK_WINDOW(fenetrePrincipale),"icon.png",NULL);
	vBoxFenetre = gtk_vbox_new(FALSE,6);
	gtk_container_add(GTK_CONTAINER(fenetrePrincipale),vBoxFenetre);
//Initialisation de la partie Haut de la fenetre
        labelNiveau = gtk_label_new(strNiveau);
	labelTemps = gtk_label_new(strChrono);
	hBoxHaut = gtk_hbox_new(TRUE,0);
        gtk_box_pack_start(GTK_BOX(hBoxHaut),labelNiveau,TRUE,TRUE,10);
	gtk_box_pack_start(GTK_BOX(hBoxHaut),labelTemps,TRUE,TRUE,10);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxHaut,FALSE, FALSE,10);
//Initialisation de la partie du milieu de la fenetre
	GtkWidget * alignement = gtk_alignment_new(0.55,0.55,0.1,0.1);
	vBoxGrille = gtk_vbox_new(FALSE,21);
	for(i=0;i<9;i++)
        {
        	TabHBoxLigne[i] = gtk_hbox_new(TRUE, 8);
		for(y=0;y<9;y++)
                {
                        if(grille1[i][y] != 0)
                        {
					sprintf(nombreAffiche,"<span foreground=\"#000000\"><big><b>%d</b></big></span>",grille1[i][y]);
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
	btnQuitter = gtk_button_new_with_mnemonic("_Quitter");
	hBoxBas = gtk_hbox_new(TRUE, 30);
        g_signal_connect(G_OBJECT(btnMenu),"clicked", G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(G_OBJECT(btnQuitter),"clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnMenu,FALSE,FALSE,20);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnQuitter,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxBas,FALSE, FALSE,0);
//Affichage
        gtk_widget_show_all(fenetrePrincipale);
}


