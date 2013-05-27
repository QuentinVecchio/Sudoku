/*********************************************************************************************************************************************
*       Partie graphique Credit Code Source												     *
*       Fonctions, GTK															     *
*       Fait par Quentin Vecchio													     *
*       25 mai 2013															     *
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui_credit.h"

void  afficheCredit(GtkWidget *widget, gpointer data)
{
//initialisation des variables
	GtkWidget * dialogBox = NULL;
        GtkWidget * label1;
//Initialisation de la dialogBox
        dialogBox = gtk_dialog_new_with_buttons("Credits",GTK_WINDOW(widget), GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,NULL);
//Initialisation des widgets
        label1 = gtk_label_new("Crédits\n\nCindy Bender : \nMatthieu Clin : \n\nNicolas Weissenbach : \n\nQuentin Vecchio : \n\n");
        gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialogBox)->vbox), label1, TRUE, TRUE, 10);
//Lancement de la dialogBox
        gtk_widget_show_all(GTK_DIALOG(dialogBox)->vbox);
        switch(gtk_dialog_run(GTK_DIALOG(dialogBox)))
        {
                case GTK_RESPONSE_OK :
                        gtk_widget_destroy(dialogBox);
        }

}
