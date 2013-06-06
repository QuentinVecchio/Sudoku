/*********************************************************************************************************************************************
*       Partie graphique Resoudre Code Source												     *
*       Fonctions, GTK														   	     *
*       Fait par Quentin Vecchio													     *
*       25 mai 2013															     *
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <time.h>

#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "../src/methodeResolution.h"
#include "../tui/affiche.h"
#include "gui_resoudre.h"

/*Variables globales */
GtkWidget * dialogBox = NULL;
GtkWidget * fenetrePrincipaleResolution = NULL;
gchar * lienFichier = NULL;
GtkWidget * zoneSaisi1 = NULL;
/********************/
void choisirFichier(GtkWidget *widget, gpointer data)
{
//Initialisation des variables sudoku
        int tps = time(NULL);
        int grilleD[9][9] = {0};//Grille de depart
        int grilleF[9][9] = {0};//Grille de fin
	L_Candidats  LC[9][9]= {{NULL}};
        L_Cases LO = creer_liste_vide();
//Initialisation des variables
        GtkWidget * label1;
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
			lireGrille(grilleD,lienFichier);
			Init_Data(LC, LO, grilleF, lienFichier);
			int grille_simple=fermerGrille(grilleF, LO, LC);
        		if (grille_simple)
        		{
                		affiche(grilleD,grilleF,tps-time(NULL),1);
        		}
        		else
        		{
                		int grille_possible=Backtrack(grilleF,LO,LC);
                		if (grille_possible)
					affiche(grilleD,grilleF,tps-time(NULL),2);
                		else
				{
					GtkWidget * fenetreImpossible = NULL;
					fenetreImpossible = gtk_message_dialog_new(GTK_WINDOW(dialogBox),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Sudoku RESOLUTION impossible");
					switch(gtk_dialog_run(GTK_DIALOG(fenetreImpossible)))
					{
						case GTK_RESPONSE_OK :
							gtk_widget_destroy(fenetreImpossible);
					}
				}
        		}
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
		gtk_entry_set_text(GTK_ENTRY(zoneSaisi1), lienFichier);
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
//Destruction de la fenetre choix fichier
	gtk_widget_destroy(dialogBox);
//Initialisation d'un GtkRc pour le fond de la grille
        gtk_rc_parse("./gtkrc.rc");
//Initialisation des chaines à afficher
	char nombreAffiche[60];
	char strNiveau[20];
	sprintf(strNiveau,"Niveau %d",niv);
	char strTps[30];
	sprintf(strTps,"Temps execution : %d ms",tps);
//Initialisation variables fenetre
	GtkWidget * vBoxFenetre = NULL;
//Initialisation variables haut fenetre
	GtkWidget * labelNiveau = NULL;
	GtkWidget * labelTemps = NULL;
	GtkWidget * hBoxHaut = NULL;
//Initialisation variables milieu de fenetre
	GtkWidget * labelChiffre[9][9];
	GtkWidget * vBoxGrille;
	GtkWidget * TabHBoxLigne[9];
//Initialisation variables bas de fenetre
	GtkWidget * btnMenu = NULL;
	GtkWidget * btnQuitter = NULL;
	GtkWidget * hBoxBas = NULL;
//Initialisation de la fenetre Principale
	fenetrePrincipaleResolution = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(fenetrePrincipaleResolution), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(fenetrePrincipaleResolution), "Solution du sudoku");
        gtk_window_set_default_size(GTK_WINDOW(fenetrePrincipaleResolution),480,480);
        g_signal_connect(G_OBJECT(fenetrePrincipaleResolution), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
        gtk_window_set_icon_from_file(GTK_WINDOW(fenetrePrincipaleResolution),"icon.png",NULL);
	vBoxFenetre = gtk_vbox_new(FALSE,8);
	gtk_container_add(GTK_CONTAINER(fenetrePrincipaleResolution),vBoxFenetre);
//Initialisation de la partie Haut de la fenetre
        labelNiveau = gtk_label_new(strNiveau);
	labelTemps = gtk_label_new(strTps);
	hBoxHaut = gtk_hbox_new(TRUE,0);
        gtk_box_pack_start(GTK_BOX(hBoxHaut),labelNiveau,TRUE,TRUE,10);
	gtk_box_pack_start(GTK_BOX(hBoxHaut),labelTemps,TRUE,TRUE,10);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxHaut,FALSE, FALSE,10);
//Initialisation de la partie du milieu de la fenetre
	GtkWidget * alignement = gtk_alignment_new(0.55,0.55,0.1,0.1);
	vBoxGrille = gtk_vbox_new(FALSE,23);
	for(i=0;i<9;i++)
        {
        	TabHBoxLigne[i] = gtk_hbox_new(FALSE, 22);
		for(y=0;y<9;y++)
                {
                        if(grille1[i][y] != 0)
                        {
					sprintf(nombreAffiche,"<span foreground=\"#000000\"><big><b>%d</b></big></span>",grille1[i][y]);
			}
                        else
                       	{
                                     	sprintf(nombreAffiche,"<span foreground=\"#1C863B\"><big><b>%d</b></big></span>",grille2[i][y]);
			}
			labelChiffre[i][y] = gtk_label_new(nombreAffiche);
			gtk_label_set_use_markup(GTK_LABEL(labelChiffre[i][y]),TRUE);
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
        g_signal_connect(G_OBJECT(btnMenu),"clicked", G_CALLBACK(retourMenu), NULL);
        g_signal_connect(G_OBJECT(btnQuitter),"clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnMenu,FALSE,FALSE,20);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnQuitter,FALSE,FALSE,20);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxBas,FALSE, FALSE,0);
//Affichage
        gtk_widget_show_all(fenetrePrincipaleResolution);
}
void retourMenu()
{
	gtk_widget_destroy(fenetrePrincipaleResolution);
}
