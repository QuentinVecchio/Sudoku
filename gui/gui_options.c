/*********************************************************************************************************************************************
*	Partie graphique Options Code Source
*	Fonctions, GTK
*	Fait par Quentin Vecchio
*	19 mai 2013
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "GUI_Options.h"

void options(GtkWidget *widget, gpointer data)
{
//Initialisation des variables
	GtkWidget * dialogBox;
	GtkWidget * label1;
	GtkWidget * zoneSaisi1;
	GtkWidget * btnEdit1;
	GtkWidget * hBox1;
	GtkWidget * label2;
	GtkWidget * zoneSaisi2;
	GtkWidget * btnEdit2
	GtkWidget * hBox2;
	GtkWidget * label3;
	GtkWidget * zoneSaisi2;
	GtkWidget * btnEdit3;
	GtkWidget * hBox3;
	GtkWidget * btnMenu;
	GtkWidget * vBox;
//Initialisation de la dialogBox
        dialogBox = gtk_dialog_new_with_buttons("Options",GTK_WINDOW(widget), GTK_DIALOG_MODAL,NULL);
	vBox =  
//Initialisation de la première ligne d'options

//Initialisation de la seconde ligne d'options

//Initialisation de la troisième ligne d'options

//Initialisation du bouton Retour Menu
//Lancement de la dialogBox
        if(gtk_dialog_run (GTK_DIALOG(dialogBox)) == GTK_RESPONSE_ACCEPT)
        {
                gchar * nomFichier = NULL;
                nomFichier = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogBox));
                affiche(nomFichier);
        }
        gtk_widget_destroy(dialogBox);
}

