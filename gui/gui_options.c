/*********************************************************************************************************************************************
*	Partie graphique Options Code Source
*	Fonctions, GTK
*	Fait par Quentin Vecchio
*	19 mai 2013
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui_options.h"
#include "gui_resoudre.h"

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
	GtkWidget * btnEdit2;
	GtkWidget * hBox2;
	GtkWidget * label3;
	GtkWidget * zoneSaisi3;
	GtkWidget * btnEdit3;
	GtkWidget * hBox3;
//Initialisation de la dialogBox
        dialogBox = gtk_dialog_new_with_buttons("Options",GTK_WINDOW(widget), GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
//Initialisation de la première ligne d'options
	label1 = gtk_label_new("Choisir un fichier de configuration");
	hBox1 = gtk_hbox_new( FALSE, 10);
	zoneSaisi1 = gtk_entry_new();
	btnEdit1 = gtk_button_new_with_label("...");
	g_signal_connect(G_OBJECT(btnEdit1),"clicked", G_CALLBACK(dialogBoxChoixFichier), NULL);
	gtk_box_pack_start(GTK_BOX(hBox1), zoneSaisi1, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(hBox1), btnEdit1, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), label1, TRUE, TRUE, 10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), hBox1, TRUE, TRUE, 10);
//Initialisation de la seconde ligne d'options
	gchar * labelChoisirFichier = g_locale_to_utf8("Choisir un fichier par défaut",-1, NULL, NULL, NULL);//Permet de mettre un accent
	label2 = gtk_label_new(labelChoisirFichier);
	hBox2 = gtk_hbox_new(FALSE, 10);
	zoneSaisi2 = gtk_entry_new();
	btnEdit2 = gtk_button_new_with_label("...");
	g_signal_connect(G_OBJECT(btnEdit2),"clicked", G_CALLBACK(dialogBoxChoixFichier), NULL);
	gtk_box_pack_start(GTK_BOX(hBox2), zoneSaisi2, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(hBox2), btnEdit2, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), label2, TRUE, TRUE, 10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), hBox2, TRUE, TRUE, 10);
//Initialisation de la troisième ligne d'options
	label3 = gtk_label_new("Choisir une grille");
	hBox3 = gtk_hbox_new(FALSE, 10);
	zoneSaisi3 = gtk_entry_new();
	btnEdit3 = gtk_button_new_with_label("...");
 	g_signal_connect(G_OBJECT(btnEdit3),"clicked", G_CALLBACK(dialogBoxChoixFichier), NULL);
	gtk_box_pack_start(GTK_BOX(hBox3), zoneSaisi3, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(hBox3), btnEdit3, FALSE, FALSE,10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), label3, TRUE, TRUE, 10);
	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), hBox3, TRUE, TRUE, 10);
//Lancement de la dialogBox
	gtk_widget_show_all(GTK_DIALOG(dialogBox)->vbox);
        switch(gtk_dialog_run(GTK_DIALOG(dialogBox)))
        {
		case GTK_RESPONSE_OK :
			gtk_widget_destroy(dialogBox);
        }
}

