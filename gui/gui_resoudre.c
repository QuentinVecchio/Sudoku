/*********************************************************************************************************************************************
*       Partie graphique Resoudre Code Source
*       Fonctions, GTK/SDL
*       Fait par Quentin Vecchio
*       19 mai 2013
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
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
                gtk_widget_destroy(dialogBox);
        }

}

void affiche(int grille1[9][9], int grille2[9][9], int tps, int niv)
{
	int i,y;
//Destruction de la fenetre choix fichier
	gtk_widget_destroy(dialogBox);
//Initialisation des chaines à afficher
	char nombreAffiche[2];
	char strNiveau[20];
	sprintf(strNiveau,"Niveau %d",niv);
	char strTps[30];
	sprintf(strTps,"Temps execution : %d ms",tps);
//Initialisation variables fenetre
	GtkWidget * fenetrePrincipale = NULL;
	GtkWidget * vBoxFenetre = NULL;
//Initialisation variables haut fenetre
	GtkWidget * labelNiveau = NULL;
	GtkWidget * labelTemps = NULL;
	GtkWidget * hBoxHaut = NULL;
//Initialisation variables milieu de fenetre
	GtkWidget * imageGrille = NULL;
	GtkWidget * labelChiffre[9][9];
	GtkWidget * vBoxGrille;
	GtkWidget * TabHBoxLigne[9];
//Initialisation variables bas de fenetre
	GtkWidget * btnMenu = NULL;
	GtkWidget * btnQuitter = NULL;
	GtkWidget * hBoxBas = NULL;
//Initialisation de la fenetre Principale
	fenetrePrincipale = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position(GTK_WINDOW(fenetrePrincipale), GTK_WIN_POS_CENTER);
        gtk_window_set_title(GTK_WINDOW(fenetrePrincipale), "Solution du sudoku");
        gtk_window_set_default_size(GTK_WINDOW(fenetrePrincipale),480,480);
        g_signal_connect(G_OBJECT(fenetrePrincipale), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
        gtk_window_set_icon_from_file(GTK_WINDOW(fenetrePrincipale),"icon.png",NULL);
	vBoxFenetre = gtk_vbox_new(FALSE,30);
	gtk_container_add(GTK_CONTAINER(fenetrePrincipale),vBoxFenetre);
//Initialisation de la partie Haut de la fenetre
        labelNiveau = gtk_label_new(strNiveau);
	labelTemps = gtk_label_new(strTps);
	hBoxHaut = gtk_hbox_new(TRUE, 30);
        gtk_box_pack_start(GTK_BOX(hBoxHaut),labelNiveau,TRUE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(hBoxHaut),labelTemps,TRUE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxHaut,FALSE, FALSE,0);
//Initialisation de la partie du milieu de la fenetre
	imageGrille = gtk_image_new_from_file("Grille.bmp");
	vBoxGrille = gtk_vbox_new(TRUE,0);
	for(i=0;i<9;i++)
        {
        	TabHBoxLigne[i] = gtk_hbox_new(FALSE, 0);
		for(y=0;y<9;y++)
                {
                        if(grille1[i][y] != 0)
                        {
                                        sprintf(nombreAffiche,"0");
                        }
                        else
                       	{
                                        sprintf(nombreAffiche,"%d",grille2[i][y]);
                       	}
			labelChiffre[i][y] = gtk_label_new("0");
                     	gtk_box_pack_start(GTK_BOX(TabHBoxLigne[i]),labelChiffre[i][y],FALSE,FALSE,0);

       		}
		gtk_box_pack_start(GTK_BOX(vBoxGrille),TabHBoxLigne[i],TRUE,TRUE,0);
       	}
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),imageGrille,TRUE,TRUE,0);
	gtk_container_add(GTK_CONTAINER(imageGrille),vBoxGrille);
//Initialisation de la partie bas de la fenetre
        btnMenu = gtk_button_new_with_mnemonic("_Menu");
	btnQuitter = gtk_button_new_with_mnemonic("_Quitter");
	hBoxBas = gtk_hbox_new(TRUE, 30);
        g_signal_connect(G_OBJECT(btnMenu),"clicked", G_CALLBACK(gtk_main_quit), NULL);
        g_signal_connect(G_OBJECT(btnQuitter),"clicked", G_CALLBACK(gtk_main_quit), NULL);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnMenu,FALSE,FALSE,15);
        gtk_box_pack_start(GTK_BOX(hBoxBas),btnQuitter,FALSE,FALSE,15);
	gtk_box_pack_start(GTK_BOX(vBoxFenetre),hBoxBas,FALSE, FALSE,0);
//Affichage
        gtk_widget_show_all(fenetrePrincipale);
}
