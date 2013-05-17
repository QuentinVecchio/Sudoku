#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "gui_Options.h"

void options(GtkWidget *widget, gpointer data)
{
	GtkWidget * dialogBox;
	GtkWidget * label1;
	GtkWidget * zoneSaisi1;
	GtkWidget * btnEdit1;
	GtkWidget * label2;
	GtkWidget * zoneSaisi2;
	GtkWidget * btnEdit2
        dialogBox = gtk_file_chooser_dialog_new("Choisir un fichier",NULL,GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GT$
        gtk_widget_set_size_request(dialogBox, 300,300);
        if(gtk_dialog_run (GTK_DIALOG(dialogBox)) == GTK_RESPONSE_ACCEPT)
        {
                gchar * nomFichier = NULL;
                nomFichier = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialogBox));
                affiche(nomFichier);
        }
        gtk_widget_destroy(dialogBox);
}

