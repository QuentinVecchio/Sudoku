/*********************************************************************************************************************************************
*       Partie graphique main Code source
*       main du programme Sudoku, GTK/SDL/GUI_Resoudre/GUI_Option
*       Fait par Quentin Vecchio
*       19 mai 2013
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui_resoudre.h"
#include "gui_credit.h"
#include "gui_jeux.h"

int main (int argc, char **argv)
{
	//Initialisation des variables
	GtkWidget * fenetrePrincipale = NULL;
	GtkWidget * labelTitre = NULL;
	GtkWidget * btnJouer = NULL;
	GtkWidget * btnResoudre = NULL;
	GtkWidget * btnCredit = NULL;
	GtkWidget * btnQuitter = NULL;
	gchar * labelResoudre = NULL;
	gchar * labelCredit = NULL;
	GtkWidget * boxVertical = NULL;
	GtkWidget * labelVersion = NULL;

	//Initialisation de la bibliothèque GTK
	gtk_init(&argc, &argv);

	//Initialisation de la fenetre principale
	fenetrePrincipale = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(fenetrePrincipale), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(fenetrePrincipale), "Sudoku");
	gtk_window_set_default_size(GTK_WINDOW(fenetrePrincipale),200,0);
	g_signal_connect(G_OBJECT(fenetrePrincipale), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_set_icon_from_file(GTK_WINDOW(fenetrePrincipale),"icon.png",NULL);

	//Initialisation du box vertical
	boxVertical = gtk_vbox_new(FALSE,0);

        //Initialisation du label
        labelTitre = gtk_label_new("<b>SUDOKU</b><sup>Graph</sup>");
        gtk_label_set_use_markup(GTK_LABEL(labelTitre),TRUE);
        gtk_box_pack_start(GTK_BOX(boxVertical),labelTitre,FALSE,FALSE,5);

	//Initialisation du bouton Jouer
	btnJouer = gtk_button_new_with_mnemonic("_Jouer au Sudoku");
	g_signal_connect(G_OBJECT(btnJouer),"clicked", G_CALLBACK(jouer), NULL);
	gtk_box_pack_start(GTK_BOX(boxVertical),btnJouer,FALSE,FALSE,15);

	//Initialisation du bouton Resoudre
	labelResoudre = g_locale_to_utf8("_Résoudre un Sudoku",-1, NULL, NULL, NULL);//Permet de mettre un accent
	btnResoudre = gtk_button_new_with_mnemonic(labelResoudre);
	g_signal_connect(G_OBJECT(btnResoudre),"clicked", G_CALLBACK(choisirFichier), NULL);
	gtk_box_pack_start(GTK_BOX(boxVertical),btnResoudre,FALSE,FALSE,15);

	//Initialisation du bouton Credit
	labelCredit = g_locale_to_utf8("_Crédits",-1, NULL, NULL, NULL);//Permet de mettre un accent 
	btnCredit = gtk_button_new_with_mnemonic(labelCredit);
	g_signal_connect(G_OBJECT(btnCredit),"clicked", G_CALLBACK(afficheCredit), NULL);
	gtk_box_pack_start(GTK_BOX(boxVertical),btnCredit,FALSE,FALSE,15);

	//Initialisation du bouton Quitter
	btnQuitter = gtk_button_new_with_mnemonic("_Quitter");
	g_signal_connect(G_OBJECT(btnQuitter),"clicked", G_CALLBACK(gtk_main_quit), NULL);
	gtk_box_pack_start(GTK_BOX(boxVertical),btnQuitter,FALSE,FALSE,15);

	//Initialisation du label version
	labelVersion = gtk_label_new("<small>v1.0</small>");
        gtk_label_set_use_markup(GTK_LABEL(labelVersion),TRUE);
        gtk_box_pack_start(GTK_BOX(boxVertical),labelVersion,FALSE,FALSE,5);

	//Affichage
	gtk_container_add(GTK_CONTAINER(fenetrePrincipale),boxVertical);
	gtk_widget_show_all(fenetrePrincipale);
	gtk_main();
	return EXIT_SUCCESS;
}
